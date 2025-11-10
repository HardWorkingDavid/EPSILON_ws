#ifndef _CORE_BEHAVIOR_PLANNER_INC_BEHAVIOR_SERVER_ROS2_H__
#define _CORE_BEHAVIOR_PLANNER_INC_BEHAVIOR_SERVER_ROS2_H__

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include "tf2_ros/transform_listener.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"
#include "vehicle_msgs/encoder.h"
#include "visualization_msgs/msg/marker.hpp"
#include "visualization_msgs/msg/marker_array.hpp"

#include <chrono>
#include <functional>
#include <numeric>
#include <thread>
// 引入行为规划相关的头文件
#include "behavior_planner/behavior_planner.h"
#include "behavior_planner/map_adapter.h"
#include "behavior_planner/visualizer.h"
#include "semantic_map_manager/semantic_map_manager.h"

#include "common/basics/tic_toc.h"
#include "common/visualization/common_visualization_util.h"
#include "moodycamel/atomicops.h"
#include "moodycamel/readerwriterqueue.h"

namespace planning {
// 行为规划器服务器
class BehaviorPlannerServer {
 public:
  // 定义语义地图管理器的别名
  using SemanticMapManager = semantic_map_manager::SemanticMapManager;

  struct Config {
    int kInputBufferSize{100}; // 输入缓冲区大小
  };
  // 构造函数1：接收ROS2节点和自车ID
  BehaviorPlannerServer(std::shared_ptr<rclcpp::Node> node, int ego_id);
  // 构造函数2：接收ROS2节点、工作频率和自车ID
  BehaviorPlannerServer(std::shared_ptr<rclcpp::Node> node, double work_rate, int ego_id);

  // 推送语义地图
  void PushSemanticMap(const SemanticMapManager &smm);
  // 绑定行为更新的回调函数
  void BindBehaviorUpdateCallback(std::function<int(const SemanticMapManager &)> fn);

  /**
   * @brief 设置自动驾驶的等级
   * @param level 自动驾驶等级（例如：L1、L2、L3等）
   */
  void set_autonomous_level(int level);

  /**
   * @brief 设置用户期望的速度
   * @param desired_vel 用户期望的速度
   */
  void set_user_desired_velocity(const decimal_t desired_vel);

  // 设置激进驾驶级别
  void set_aggressive_level(int level);

  // 获取用户设定的期望速度
  decimal_t user_desired_velocity() const;

  // 获取规划器使用的参考速度
  decimal_t reference_desired_velocity() const;

  // 启用人机交互接口
  void enable_hmi_interface();

  // 初始化行为规划器服务器
  void Init();

  // 启动行为规划器服务器
  void Start();
  
 private:
  // 规划周期回调函数
  void PlanCycleCallback();
  // Joy消息的回调函数（用于接收手柄输入WSAD）
  void JoyCallback(const sensor_msgs::msg::Joy::ConstSharedPtr msg);
  // 重规划
  void Replan();
  // 发布规划结果数据
  void PublishData();
  // 主线程函数，持续执行行为规划
  void MainThread();
  // 配置项
  Config config_;
  // 行为规划器
  BehaviorPlanner bp_;
  // 地图适配器，用于将语义地图转换为行为规划所需格式
  BehaviorPlannerMapAdapter map_adapter_;
  std::unique_ptr<BehaviorPlannerVisualizer> p_visualizer_;

  // 性能分析工具（用于记录时间戳）
  TicToc time_profile_tool_;
  decimal_t global_init_stamp_{0.0}; // 全局初始化时间戳

  // ros related
  std::shared_ptr<rclcpp::Node> node_;
  // 手柄消息的订阅者
  rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr joy_sub_;

  // 自车ID
  int ego_id_;
  // 工作频率
  double work_rate_;

  // 输入缓冲区，使用无锁队列（提高性能）
  std::unique_ptr<moodycamel::ReaderWriterQueue<SemanticMapManager>> p_input_smm_buff_;
  bool has_callback_binded_ = false;
  
  // 私有的行为更新回调函数
  std::function<int(const SemanticMapManager &)> private_callback_fn_;
  bool is_hmi_enabled_ = false;
};

}  // namespace planning

#endif  // _CORE_BEHAVIOR_PLANNER_INC_BEHAVIOR_SERVER_ROS2_H__
