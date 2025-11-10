#include "behavior_planner/behavior_server_ros.h"

namespace planning {

// 构造函数不输入work_rate，默认20Hz
BehaviorPlannerServer::BehaviorPlannerServer(std::shared_ptr<rclcpp::Node> node, int ego_id)
  : node_(node), work_rate_(20.0), ego_id_(ego_id) {
    p_visualizer_ = std::make_unique<BehaviorPlannerVisualizer>(node, &bp_, ego_id);
    p_input_smm_buff_ = std::make_unique<moodycamel::ReaderWriterQueue<SemanticMapManager>>(config_.kInputBufferSize);
}

BehaviorPlannerServer::BehaviorPlannerServer(std::shared_ptr<rclcpp::Node> node, double work_rate, int ego_id)
  : node_(node), work_rate_(work_rate), ego_id_(ego_id) {
    p_visualizer_ = std::make_unique<BehaviorPlannerVisualizer>(node, &bp_, ego_id);
    p_input_smm_buff_ = std::make_unique<moodycamel::ReaderWriterQueue<SemanticMapManager>>(config_.kInputBufferSize);
}

// 推送语义地图到缓冲区
void BehaviorPlannerServer::PushSemanticMap(const SemanticMapManager &smm) {
  if (p_input_smm_buff_) p_input_smm_buff_->try_enqueue(smm);
}

// 发布可视化数据
void BehaviorPlannerServer::PublishData() {
  p_visualizer_->PublishDataWithStamp(node_->get_clock()->now());
}

// 初始化行为规划器
void BehaviorPlannerServer::Init() {
  // 初始化行为规划器
  bp_.Init("bp"); 
  // 如果自动驾驶等级 >= 2，订阅Joy消息以接收手柄输入
  if (bp_.autonomous_level() >= 2) {
    joy_sub_ = node_->create_subscription<sensor_msgs::msg::Joy>(
        "/joy", 10, std::bind(&BehaviorPlannerServer::JoyCallback, this, std::placeholders::_1));
  }
  bool use_sim_state = true;
  // node_->declare_parameter("use_sim_state", use_sim_state);
  node_->get_parameter("use_sim_state", use_sim_state);
  bp_.set_use_sim_state(use_sim_state);
  // 初始化可视化工具
  p_visualizer_->Init();
}

// Joy消息的回调函数，用于处理手柄输入
void BehaviorPlannerServer::JoyCallback(const sensor_msgs::msg::Joy::ConstSharedPtr msg) {
  // 如果自动驾驶等级低于2，不处理手柄输入
  if (bp_.autonomous_level() < 2) return;
  // 如果没有启用HMI接口，不处理输入
  if (!is_hmi_enabled_) return;

  int msg_id;
  // 获取Joy消息的ID
  if (msg->header.frame_id.empty()) {
    msg_id = 0;
  } else {
    msg_id = std::stoi(msg->header.frame_id); // 将frame_id转换为整数作为车辆ID
  }
  // 如果当前消息的ID与当前车辆ID不匹配，则忽略该消息
  if (msg_id != ego_id_) return;
  // ~ buttons[2] --> 1 -->  lcl     A:左转
  // ~ buttons[1] --> 1 -->  lcr     D:右转
  // ~ buttons[3] --> 1 -->  +1m/s   W:加速
  // ~ buttons[0] --> 1 -->  -1m/s   S:减速
  if (msg->buttons[0] == 0 && msg->buttons[1] == 0 && msg->buttons[2] == 0 && msg->buttons[3] == 0)
    return; // 如果没有按钮按下，忽略

  // 根据不同按钮设置不同的行为
  if (msg->buttons[2] == 1) {
    // 如果左车道变道按钮被按下，设置为左车道变道
    bp_.set_hmi_behavior(common::LateralBehavior::kLaneChangeLeft);
  } else if (msg->buttons[1] == 1) {
    // 如果右车道变道按钮被按下，设置为右车道变道
    bp_.set_hmi_behavior(common::LateralBehavior::kLaneChangeRight);
  } else if (msg->buttons[3] == 1) {
    // 如果加速按钮被按下，增加期望速度1.0m/s
    bp_.set_user_desired_velocity(bp_.user_desired_velocity() + 1.0);
  } else if (msg->buttons[0] == 1) {
    // 如果减速按钮被按下，减少期望速度1.0m/s
    bp_.set_user_desired_velocity(bp_.user_desired_velocity() - 1.0);
  }
}

// 启动行为规划器服务器
void BehaviorPlannerServer::Start() {
  // 设置地图接口
  bp_.set_map_interface(&map_adapter_);
  // 启动主线程，开始规划
  std::thread(&BehaviorPlannerServer::MainThread, this).detach();
}

// 主线程，按照工作频率周期性调用行为规划
void BehaviorPlannerServer::MainThread() {
  using namespace std::chrono;
  system_clock::time_point current_start_time{system_clock::now()};
  system_clock::time_point next_start_time{current_start_time};
  // auto current_start_time = system_clock::now();
  // auto next_start_time = current_start_time;
  const milliseconds interval(static_cast<int>(1000.0 / work_rate_)); // 计算每次规划的时间间隔 50ms = 0.05s
  while (rclcpp::ok()) {
    current_start_time = system_clock::now();       // 获取当前时间
    next_start_time = current_start_time + interval;// 计算下次规划的开始时间
    PlanCycleCallback();                            // 执行规划周期回调
    std::this_thread::sleep_until(next_start_time); // 按照设定的时间间隔休眠
  }
}

// 执行行为规划周期回调
void BehaviorPlannerServer::PlanCycleCallback() {
  if (p_input_smm_buff_ == nullptr) return;

  SemanticMapManager smm;
  bool has_updated_map = false;
  // 从输入缓冲区中取出语义地图
  while (p_input_smm_buff_->try_dequeue(smm)) {
    has_updated_map = true;
  }
  // 如果有更新的地图
  if (has_updated_map) {
    // 将地图传递给地图适配器
    auto map_ptr = std::make_shared<semantic_map_manager::SemanticMapManager>(smm);
    map_adapter_.set_map(map_ptr);

    TicToc timer; // 定时器，记录执行时间

    // 调用MPDP算法
    if (bp_.RunOnce() == kSuccess) {
      smm.set_ego_behavior(bp_.behavior()); // 更新ego_behavior后的smm加入到队列中
    }

    // 如果绑定了回调函数，执行回调
    if (has_callback_binded_) {
      private_callback_fn_(smm);
    }
    // 发布规划数据
    PublishData();
  }
}

// 绑定行为更新回调函数
void BehaviorPlannerServer::BindBehaviorUpdateCallback(std::function<int(const SemanticMapManager &)> fn) {
  private_callback_fn_ = std::bind(fn, std::placeholders::_1); // 将回调函数绑定到内部成员
  has_callback_binded_ = true;                                 // 设置回调已绑定
}

// 重规划，此函数为空
void BehaviorPlannerServer::Replan() {}

// 设置自动驾驶等级
void BehaviorPlannerServer::set_autonomous_level(int level) {
  bp_.set_autonomous_level(level);
}

// 设置激进驾驶等级
void BehaviorPlannerServer::set_aggressive_level(int level) {
  bp_.set_aggressive_level(level);
}

// 设置用户期望的速度
void BehaviorPlannerServer::set_user_desired_velocity(const decimal_t desired_vel) {
  bp_.set_user_desired_velocity(desired_vel);
}

// 获取用户期望的速度
decimal_t BehaviorPlannerServer::user_desired_velocity() const {
  return bp_.user_desired_velocity();
}

// 获取参考的期望速度
decimal_t BehaviorPlannerServer::reference_desired_velocity() const {
  return bp_.reference_desired_velocity();
}

// 启用HMI接口
void BehaviorPlannerServer::enable_hmi_interface() {
  is_hmi_enabled_ = true;
}

}  // namespace planning
