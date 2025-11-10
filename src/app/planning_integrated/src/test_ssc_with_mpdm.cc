#include <rclcpp/rclcpp.hpp>
#include <stdlib.h>

#include <chrono>
#include <iostream>

#include "behavior_planner/behavior_server_ros.h"
#include "semantic_map_manager/data_renderer.h"
#include "semantic_map_manager/ros_adapter.h"
#include "semantic_map_manager/semantic_map_manager.h"
#include "semantic_map_manager/visualizer.h"
#include "ssc_planner/ssc_server_ros.h"

DECLARE_BACKWARD;
double ssc_planner_work_rate = 20.0; // ssc规划器工作频率
double bp_work_rate = 20.0;          // 行为规划器工作频率

std::shared_ptr<planning::SscPlannerServer> p_ssc_server_{nullptr};    // 初始化ssc规划器
std::shared_ptr<planning::BehaviorPlannerServer> p_bp_server_{nullptr};// 初始化行为规划器

// 行为更新回调(语义地图更新)
int BehaviorUpdateCallback(const semantic_map_manager::SemanticMapManager& smm) {
  if (p_ssc_server_) p_ssc_server_->PushSemanticMap(smm); // 如果ssc规划器存在，推送语义地图
  return 0;
}

// 语义地图更新回调
int SemanticMapUpdateCallback(const semantic_map_manager::SemanticMapManager& smm) {
  if (p_bp_server_) p_bp_server_->PushSemanticMap(smm); // 如果行为规划器存在，推送语义地图
  return 0;
}

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("test_ssc_with_mpdm");

  int ego_id = 0; // 自车(id = 0)
  std::string agent_config_path = "";
  std::string ssc_config_path = "";
  double desired_vel = 6.0; // 期望速度

  node->declare_parameter<int>("ego_id", ego_id);
  node->declare_parameter<double>("desired_vel", desired_vel);
  node->declare_parameter<std::string>("agent_config_path", agent_config_path);
  node->declare_parameter<std::string>("ssc_config_path", ssc_config_path);
  // node->declare_parameter<std::string>("agent_config_path", "/home/tao/Desktop/Autonomous-Motorsports-Motion-Planning-for-the-IAC/EPSILON/src/core/playgrounds/highway_v1.0/agent_config.json");
  // node->declare_parameter<std::string>("ssc_config_path", "/home/tao/Desktop/Autonomous-Motorsports-Motion-Planning-for-the-IAC/EPSILON/src/util/ssc_planner/config/ssc_config.pb.txt");

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
  // 读取智能体的配置(Json格式), 在SemanticMapManager构造函数内解析
  if (!node->get_parameter("agent_config_path", agent_config_path)) {
    RCLCPP_ERROR(node->get_logger(), "Failed to get parameter: agent_config_path");
  } else {
    RCLCPP_INFO(node->get_logger(), "agent_config_path: %s", agent_config_path.c_str());
  }
  // 读取规划的配置
  if (!node->get_parameter("ssc_config_path", ssc_config_path)) {
    RCLCPP_ERROR(node->get_logger(), "Failed to get parameter: ssc_config_path");
  } else {
    RCLCPP_INFO(node->get_logger(), "ssc_config_path: %s", ssc_config_path.c_str());
  }

  try {
    // 创建语义地图管理器实例
    auto semantic_map_manager = std::make_shared<semantic_map_manager::SemanticMapManager>(ego_id, agent_config_path);
    // 创建ROS适配器实例
    auto smm_ros_adapter = std::make_shared<semantic_map_manager::RosAdapter>(node, semantic_map_manager.get());
    smm_ros_adapter->BindMapUpdateCallback(SemanticMapUpdateCallback); // 绑定地图更新回调函数
    
    // Declare bp 初始化行为规划器
    p_bp_server_ = std::make_shared<planning::BehaviorPlannerServer>(node, bp_work_rate, ego_id);
    p_bp_server_->set_user_desired_velocity(desired_vel);            // 设置用户期望速度 20.0
    p_bp_server_->BindBehaviorUpdateCallback(BehaviorUpdateCallback);// 绑定行为更新回调函数
    p_bp_server_->set_autonomous_level(3);                           // 设置自动化级别
    p_bp_server_->enable_hmi_interface();                            // true -> 使能手柄进行人机交互

    // 初始化ssc规划器
    p_ssc_server_ = std::make_shared<planning::SscPlannerServer>(node, ssc_planner_work_rate, ego_id);
    p_ssc_server_->Init(ssc_config_path); // 1.初始化规划的参数  2.发布topic: 控制信号, ssc地图, 轨迹可视化
    p_bp_server_->Init();                 // 1.构建RoutePlanner  2.订阅手柄数据  3.可视化
    smm_ros_adapter->Init();              // 1.订阅静态环境信息  2.订阅动态环境信息

    // 启动行为规划器和ssc规划器
    p_bp_server_->Start();  // 1.设定地图接口  2.开启behavior planner线程
    p_ssc_server_->Start(); // 1.设定地图接口  2.开启ssc planner线程

    // 启动ROS循环，每秒100次
    rclcpp::Rate rate(100);
    while (rclcpp::ok()) {
      rclcpp::spin_some(node); // 执行ROS节点的回调函数
      rate.sleep();            // 按照设定的频率休眠
    }

  } catch (const std::exception &e) {
    RCLCPP_ERROR(node->get_logger(), "Exception: %s", e.what());
    return -1;
  }

  rclcpp::shutdown();
  return 0;
}
