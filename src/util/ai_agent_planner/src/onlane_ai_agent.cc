#include <chrono>
#include <iostream>
#include <memory>
#include <random>

#include <stdlib.h>
#include "rclcpp/rclcpp.hpp"

#include "behavior_planner/behavior_server_ros.h"
#include "common/basics/tic_toc.h"
#include "forward_simulator/multimodal_forward.h"
#include "forward_simulator/onlane_forward_simulation.h"
#include "semantic_map_manager/ros_adapter.h"
#include "semantic_map_manager/semantic_map_manager.h"
#include "semantic_map_manager/visualizer.h"
#include "sensor_msgs/msg/joy.hpp"
#include "vehicle_msgs/msg/control_signal.hpp"
#include "vehicle_msgs/encoder.h"

DECLARE_BACKWARD;
double fs_work_rate = 50.0;          // 前向模拟工作频率（Hz）
double visualization_msg_rate = 20.0;// 可视化消息发布频率
double bp_work_rate = 20.0;          // 行为规划工作频率
int ego_id;                          // 自车ID

// 控制信号发布器指针（发布车辆控制指令）
rclcpp::Publisher<vehicle_msgs::msg::ControlSignal>::SharedPtr ctrl_signal_pub_;
// 行为规划服务器指针
std::shared_ptr<planning::BehaviorPlannerServer> p_bp_server_{nullptr};
// 控制输入语义地图缓冲区（线程安全队列，用于传递语义地图数据）
std::shared_ptr<moodycamel::ReaderWriterQueue<semantic_map_manager::SemanticMapManager>> p_ctrl_input_smm_buff_{nullptr};
// 语义地图可视化器指针
std::shared_ptr<semantic_map_manager::Visualizer> p_smm_vis_{nullptr};

common::State desired_state; // 期望状态
bool has_init_state = false; // 标记是否已初始化期望状态
double desired_vel;          // 期望速度

rclcpp::Time next_vis_pub_time; // 下一次可视化消息发布时间
semantic_map_manager::SemanticMapManager last_smm; // 上一次的语义地图数据
planning::OnLaneForwardSimulation::Param sim_param; // 前向模拟参数

// ~ Add noise
std::mt19937 rng;
double vel_noise = 0.0; // 速度噪声值
int cnt = 0;
int aggressiveness_level = 3; // 驾驶激进程度等级

/**
 * @brief 语义地图更新回调函数
 * 当语义地图更新时被调用，将新地图推送给行为规划服务器，并初始化期望状态
 * @param smm 更新后的语义地图
 * @return 0（成功）
 */
int SemanticMapUpdateCallback(const semantic_map_manager::SemanticMapManager& smm) {
  // 若行为规划服务器存在，将语义地图推送给它
  if (p_bp_server_) {
    p_bp_server_->PushSemanticMap(smm);
  } else {
    RCLCPP_WARN(rclcpp::get_logger("onlane_ai_agent"), "p_bp_server_ is nullptr in SemanticMapUpdateCallback");
  }

  // 若未初始化期望状态，使用当前自车状态初始化
  if (!has_init_state) {
    desired_state = smm.ego_vehicle().state();
    has_init_state = true;
    desired_state.print();
  }
  return 0;
}

/**
 * @brief 行为更新回调函数
 * 当行为规划结果更新时被调用，将语义地图放入控制输入缓冲区
 * @param smm 包含最新行为规划结果的语义地图
 * @return 0（成功）
 */
int BehaviorUpdateCallback(const semantic_map_manager::SemanticMapManager& smm) {
  // 若缓冲区存在，将语义地图入队
  if (p_ctrl_input_smm_buff_) {
    p_ctrl_input_smm_buff_->try_enqueue(smm);
  } else {
    RCLCPP_WARN(rclcpp::get_logger("onlane_ai_agent"), "p_ctrl_input_smm_buff_ is nullptr in BehaviorUpdateCallback");
  }
  return 0;
}

/**
 * @brief 随机行为生成函数
 * 定期生成随机速度噪声，调整期望速度（模拟随机驾驶行为）
 */
void RandomBehavior() {
  if (cnt == 0) {
    std::uniform_real_distribution<double> dist_vel(-2, 5); // 生成[-2, 5]范围内的随机速度噪声
    vel_noise = dist_vel(rng);
    // 设置行为规划器的期望速度（当前期望速度+噪声）
    if (p_bp_server_) {
      p_bp_server_->set_user_desired_velocity(desired_vel + vel_noise);
      RCLCPP_INFO(rclcpp::get_logger("onlane_ai_agent"), "[OnlaneAi]%d - desired velocity: %lf", ego_id, desired_vel + vel_noise);
    } else {
      RCLCPP_WARN(rclcpp::get_logger("onlane_ai_agent"), "p_bp_server_ is nullptr in RandomBehavior");
    }
  }
  cnt++;
  if (cnt >= 2000) cnt = 0; // 每2000步更新一次噪声
}

/**
 * @brief 发布控制信号函数
 * 从缓冲区获取最新语义地图，计算控制信号并发布，同时处理可视化
 */
void PublishControl() {
  // 若未初始化期望状态，直接返回
  if (!has_init_state) return;
  // 若行为规划服务器或缓冲区为空，直接返回
  if (p_bp_server_ == nullptr) return;
  if (p_ctrl_input_smm_buff_ == nullptr) return;

  // 检查是否有新的语义地图更新
  bool is_map_updated = false;
  decimal_t previous_stamp = last_smm.time_stamp();
  // 从缓冲区读取所有最新地图，只保留最后一个
  while (p_ctrl_input_smm_buff_->try_dequeue(last_smm)) {
    is_map_updated = true;
  }
  if (!is_map_updated) return;

  // 计算时间差（当前与上一次地图的时间间隔）
  decimal_t delta_t = last_smm.time_stamp() - previous_stamp;
  // 限制最大时间差（避免过大跳变）
  if (delta_t > 100.0 / fs_work_rate) delta_t = 1.0 / fs_work_rate;

  // 获取行为规划器输出的参考期望速度
  decimal_t command_vel = p_bp_server_->reference_desired_velocity();
  // 获取当前车道的限速，并将命令速度限制在限速内
  decimal_t speed_limit;
  if (last_smm.GetSpeedLimit(last_smm.ego_vehicle().state(),
                             last_smm.ego_behavior().ref_lane,
                             &speed_limit) == kSuccess) {
    command_vel = std::min(speed_limit, command_vel);
  }

  // 准备自车信息，更新其状态为当前期望状态
  common::Vehicle ego_vehicle = last_smm.ego_vehicle();
  ego_vehicle.set_state(desired_state);
  // 设置前向模拟的期望速度（IDM模型参数）
  sim_param.idm_param.kDesiredVelocity = command_vel;

  // 获取当前车道上的前车信息（用于跟车模拟）
  common::Vehicle leading_vehicle;
  common::State state;
  decimal_t distance_residual_ratio = 0.0;
  const decimal_t lat_range = 2.2;  // 横向范围（用于判断同车道车辆）
  last_smm.GetLeadingVehicleOnLane(last_smm.ego_behavior().ref_lane,
                                   desired_state,
                                   last_smm.surrounding_vehicles(), lat_range,
                                   &leading_vehicle, &distance_residual_ratio);
  // 执行前向模拟，计算下一步状态（考虑前车）
  if (planning::OnLaneForwardSimulation::PropagateOnce(
          common::StateTransformer(last_smm.ego_behavior().ref_lane),
          ego_vehicle, leading_vehicle, delta_t, sim_param,
          &state) != kSuccess) {
    RCLCPP_ERROR(rclcpp::get_logger("onlane_ai_agent"), "[AiAgent]Err-Simulation error (with leading vehicle).");
    return;
  }

  // 生成控制信号（基于模拟后的状态）
  common::VehicleControlSignal ctrl(state);
  {
    // 将控制信号转换为ROS消息并发布
    vehicle_msgs::msg::ControlSignal ctrl_msg;
    vehicle_msgs::Encoder::GetRosControlSignalFromControlSignal(
        ctrl, rclcpp::Clock(RCL_ROS_TIME).now(), std::string("map"), &ctrl_msg);
    ctrl_signal_pub_->publish(ctrl_msg);
  }
  // 更新期望状态为模拟后的状态（用于下一步迭代）
  desired_state = ctrl.state;

  // 可视化处理（按设定频率发布）
  {
    rclcpp::Time tnow = rclcpp::Clock(RCL_ROS_TIME).now();
    if (tnow >= next_vis_pub_time) {
      // 更新下一次可视化发布时间
      next_vis_pub_time += rclcpp::Duration::from_seconds(1.0 / visualization_msg_rate);
      // 若可视化器存在，发布可视化数据和TF变换
      if (p_smm_vis_) {
        // RCLCPP_INFO(rclcpp::get_logger("onlane_ai_agent"), "Publishing visualization data.");
        p_smm_vis_->VisualizeDataWithStamp(tnow, last_smm);
        p_smm_vis_->SendTfWithStamp(tnow, last_smm);
      } else {
        RCLCPP_WARN(rclcpp::get_logger("onlane_ai_agent"), "p_smm_vis_ is nullptr in PublishControl");
      }
    }
  }
}

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<rclcpp::Node>("onlane_ai_agent");

  // next_vis_pub_time = rclcpp::Clock(RCL_ROS_TIME).now();
  next_vis_pub_time = node->get_clock()->now();  


  double desired_vel = 6.0;
  int autonomous_level = 3;
  int aggressiveness_level = 3;
  std::string agent_config_path = "";

  node->declare_parameter<int>("ego_id", ego_id);
  node->declare_parameter<std::string>("agent_config_path", agent_config_path);
  node->declare_parameter<double>("desired_vel", desired_vel);
  node->declare_parameter<int>("autonomous_level", aggressiveness_level);
  node->declare_parameter<int>("aggressiveness_level", aggressiveness_level);

  node->get_parameter("ego_id", ego_id);
  node->get_parameter("desired_vel", desired_vel);
  node->get_parameter("agent_config_path", agent_config_path);
  node->get_parameter("autonomous_level", autonomous_level);
  node->get_parameter("aggressiveness_level", aggressiveness_level);

  if (!node->get_parameter("ego_id", ego_id)) {
    RCLCPP_ERROR(node->get_logger(), "Failed to get parameter: ego_id");
  } else {
    RCLCPP_INFO(node->get_logger(), "ego_id: %d", ego_id);
  }

  if (!node->get_parameter("desired_vel", desired_vel)) {
    RCLCPP_ERROR(node->get_logger(), "Failed to get parameter: desired_vel");
  } else {
    RCLCPP_INFO(node->get_logger(), "desired_vel: %f", desired_vel);
  }
  
  if (!node->get_parameter("agent_config_path", agent_config_path)) {
    RCLCPP_ERROR(node->get_logger(), "Failed to get parameter: agent_config_path");
  } else {
    RCLCPP_INFO(node->get_logger(), "agent_config_path: %s", agent_config_path.c_str());
  }

  if (!node->get_parameter("autonomous_level", autonomous_level)) {
    RCLCPP_ERROR(node->get_logger(), "Failed to get parameter: autonomous_level");
  } else {
    RCLCPP_INFO(node->get_logger(), "autonomous_level: %d", autonomous_level);
  }

  if (!node->get_parameter("aggressiveness_level", aggressiveness_level)) {
    RCLCPP_ERROR(node->get_logger(), "Failed to get parameter: aggressiveness_level");
  } else {
    RCLCPP_INFO(node->get_logger(), "aggressiveness_level: %d", aggressiveness_level);
  }


  try {
    // 创建控制信号发布器（主题名为"ctrl"，队列长度10）
    ctrl_signal_pub_ = node->create_publisher<vehicle_msgs::msg::ControlSignal>("ctrl", 10);

    // 初始化随机数生成器（用当前时间作为种子）
    rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());

    // 根据激进程度等级查找前向模拟参数
    planning::MultiModalForward::ParamLookUp(aggressiveness_level, &sim_param);
    RCLCPP_INFO(node->get_logger(), "[OnlaneAi]%d - aggresive: %d", ego_id, aggressiveness_level);

    // 创建语义地图管理器（管理自车和环境语义信息）
    auto semantic_map_manager = std::make_shared<semantic_map_manager::SemanticMapManager>(ego_id, agent_config_path);
    // 创建语义地图ROS适配器（处理ROS消息与语义地图的转换）
    auto smm_ros_adapter = std::make_shared<semantic_map_manager::RosAdapter>(node, semantic_map_manager.get());
    // 创建语义地图可视化器
    p_smm_vis_ = std::make_shared<semantic_map_manager::Visualizer>(node, ego_id);

    // 创建行为规划服务器
    p_bp_server_ = std::make_shared<planning::BehaviorPlannerServer>(node, bp_work_rate, ego_id);
    if (p_bp_server_ == nullptr) {
      RCLCPP_ERROR(node->get_logger(), "Failed to create BehaviorPlannerServer");
      return -1;
    } else {
      RCLCPP_INFO(node->get_logger(), "Success to create BehaviorPlannerServer");
    }

    p_bp_server_->set_user_desired_velocity(desired_vel); // 设置期望速度
    p_bp_server_->set_autonomous_level(autonomous_level); // 设置自动驾驶等级
    p_bp_server_->set_aggressive_level(aggressiveness_level); // 设置激进程度
    p_bp_server_->enable_hmi_interface(); // 启用HMI接口（人机交互）

    // 绑定回调函数：语义地图更新时调用SemanticMapUpdateCallback
    smm_ros_adapter->BindMapUpdateCallback(SemanticMapUpdateCallback);
    // 绑定回调函数：行为规划更新时调用BehaviorUpdateCallback
    p_bp_server_->BindBehaviorUpdateCallback(BehaviorUpdateCallback);

    // 初始化语义地图ROS适配器和行为规划服务器
    smm_ros_adapter->Init();
    p_bp_server_->Init();

    // 创建控制输入语义地图缓冲区（容量100）
    p_ctrl_input_smm_buff_ = std::make_shared<moodycamel::ReaderWriterQueue<semantic_map_manager::SemanticMapManager>>(100);

    // 启动行为规划服务器
    p_bp_server_->Start();
    // 设置主循环频率（前向模拟工作频率）
    rclcpp::Rate rate(fs_work_rate);
    while (rclcpp::ok()) {
      rclcpp::spin_some(node);
      PublishControl();     // 计算并发布控制信号
      rate.sleep();
    }

  } catch (const std::exception &e) {
    RCLCPP_ERROR(node->get_logger(), "Exception: %s", e.what());
    return -1;
  }

  rclcpp::shutdown();
  return 0;
}
