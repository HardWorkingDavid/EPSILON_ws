#include "behavior_planner/behavior_planner.h"

#include <fstream>
#include <cstdio>

namespace planning {

// 返回行为规划器的名称
std::string BehaviorPlanner::Name() {
  return std::string("Generic behavior planner");
}

// 初始化行为规划器
ErrorType BehaviorPlanner::Init(const std::string config) {
  // 初始化导航规划器
  p_route_planner_ = new planning::RoutePlanner();
  behavior_.actual_desired_velocity = 0.0;
  return kSuccess;
}

// 执行多策略决策模型MPDM
ErrorType BehaviorPlanner::RunMpdm() {
  TicToc timer; // 计时器
  LateralBehavior mpdm_behavior;  // 存储行为
  decimal_t mpdm_desired_velocity;// 存储期望速度

  std::ofstream log_file("/home/bigdavid/EPSILON_ws/doc/MultiBehaviorJudge.txt", std::ios::app);
  // 进行行为判断
  if (MultiBehaviorJudge(behavior_.actual_desired_velocity, &mpdm_behavior,
                         &mpdm_desired_velocity) == kSuccess) {
    behavior_.lat_behavior = mpdm_behavior;                   // 分数最高的行为
    behavior_.actual_desired_velocity = mpdm_desired_velocity;// 分数最高的期望速度
    behavior_.forward_trajs = forward_trajs_;                 // 每种行为对应的ego_car的前向轨迹
    behavior_.forward_behaviors = forward_behaviors_;         // 所有可能的行为
    behavior_.surround_trajs = surround_trajs_;               // 每种行为对应的周围所有车的预测轨迹

    printf("[MPDM]MPDM desired velocity %lf in %lf.\n",
           behavior_.actual_desired_velocity, reference_desired_velocity_);
    printf("[MPDM]Time multi behavior judged in %lf ms.\n", timer.toc());
  } else {
    // 如果MPDM失败，打印错误信息
    printf("[MPDM]MPDM failed.\n");
    printf("[MPDM]Time multi behavior judged in %lf ms.\n", timer.toc());
    return kWrongStatus;
  }

  if (log_file.is_open()) {
    log_file << "[Summary]Time multi behavior judged in " << timer.toc() << " ms.\n";
    log_file.close();
  }

  return kSuccess;
}

// 执行导航规划器
ErrorType BehaviorPlanner::RunRoutePlanner(const int nearest_lane_id) {
  TicToc timer_rp; // 计时器
  // ~ Run route planner
  // p_route_planner_->set_navi_mode(RoutePlanner::NaviMode::kRandomExpansion); // 只获得一次WholeLaneNet
  p_route_planner_->set_navi_mode(RoutePlanner::NaviMode::kAssignedTarget); // 给定目标点的导航
  
  // 如果未获取到车道网，则从地图接口获取
  if (!p_route_planner_->if_get_lane_net()) {
    common::LaneNet whole_lane_net;
    map_itf_->GetWholeLaneNet(&whole_lane_net);
    p_route_planner_->set_lane_net(whole_lane_net);
  }

  // 获取自车状态
  State ego_state;
  map_itf_->GetEgoState(&ego_state);
  p_route_planner_->set_ego_state(ego_state);
  p_route_planner_->set_nearest_lane_id(nearest_lane_id);
  // 执行一次导航规划
  if (p_route_planner_->RunOnce() == kSuccess) {
  }
  // printf("[RoutePlanner]succeed in time %lf ms.\n", timer_rp.toc());
  return kSuccess;
}

// 执行行为规划
ErrorType BehaviorPlanner::RunOnce() {
  // ~ The class which inherits this generic bp would probably need
  // ~ to implement the following logics.
  // ~ step 1: parse the navigation message if any
  // ~ step 2: decision making on the applicable behavior set
  // ~ step 3: construct complete semantic bahavior
  // 1 如果有的话解析导航信息
  // 2 在合理行为集合中决策
  // 3 构建完整的语义行为
  int ego_lane_id_by_pos = kInvalidLaneId;
  if (map_itf_->GetEgoLaneIdByPosition(p_route_planner_->navi_path(),
                                       &ego_lane_id_by_pos) != kSuccess) {
    printf("[BP RunOnce]Err - Ego not on lane.\n");
    return kWrongStatus;
  }

  common::Vehicle ego_vehicle;
  if (map_itf_->GetEgoVehicle(&ego_vehicle) != kSuccess) {
    printf("[MPDM]fail to get ego vehicle.\n");
    return kWrongStatus;
  }
  ego_id_ = ego_vehicle.id(); // 设置自车ID

  // 如果使用仿真状态，运行导航规划器
  if (use_sim_state_) {
    RunRoutePlanner(ego_lane_id_by_pos);
  }
  // 如果自车ID无效，更新车道ID
  if (ego_lane_id_ == kInvalidAgentId) {
    UpdateEgoLaneId(ego_lane_id_by_pos);
  }

  LateralBehavior behavior_by_lane_id;
  // 根据车道ID评估行为
  if (JudgeBehaviorByLaneId(ego_lane_id_by_pos, &behavior_by_lane_id) !=
      kSuccess) {
    printf("[RunOnce]fail to judge behavior by lane id!\n");
    return kWrongStatus;
  }
  // 更新车道ID
  UpdateEgoLaneId(ego_lane_id_by_pos);
  printf("[MPDM]ego lane id: %d.\n", ego_lane_id_);
  // 更新自车行为
  if (UpdateEgoBehavior(behavior_by_lane_id) != kSuccess) {
    printf("[RunOnce]fail to update ego behavior!\n");
    return kWrongStatus;
  }
  // 如果行为未定义，默认设置为车道保持
  if (behavior_.lat_behavior == common::LateralBehavior::kUndefined) {
    behavior_.lat_behavior = common::LateralBehavior::kLaneKeeping;
  }
  // 设置期望速度
  behavior_.actual_desired_velocity = user_desired_velocity_;
  // 如果自动驾驶等级>=3，运行MPDM
  if (autonomous_level_ >= 3) {
    TicToc timer;

    std::ofstream log_file("/home/bigdavid/EPSILON_ws/doc/Mpdm_time_cost.txt", std::ios::app);

    planning::MultiModalForward::ParamLookUp(aggressive_level_, &sim_param_);
    if (RunMpdm() != kSuccess) {
      printf("[Summary]Mpdm failed: %lf ms.\n", timer.toc());
      return kWrongStatus;
    } else {
      // printf("[Stuck]Ego id %d on lane %d with behavior %d mpdm success.\n",
      //        ego_vehicle.id(), ego_lane_id_,
      //        static_cast<int>(behavior_.lat_behavior));
    }
    if (log_file.is_open()) {
      log_file << "[Summary]Mpdm time cost: " << timer.toc() << " ms.\n";
      log_file.close();
    }
    printf("[Summary]Mpdm time cost: %lf ms.\n", timer.toc());
  }

  TicToc t1;

  std::ofstream log_file1("/home/bigdavid/EPSILON_ws/doc/ConstructReferenceLane.txt");

  // 根据分数最高的行为(即将采取的行为), 构造参考线
  if (ConstructReferenceLane(behavior_.lat_behavior, &behavior_.ref_lane) !=
      kSuccess) {
    return kWrongStatus;
  }

  if (log_file1.is_open()) {
    log_file1 << "[Summary]ConstructReferenceLane time cost: " << t1.toc() << " ms.\n";
    log_file1.close();
  }

  return kSuccess;
}

// 判断多个行为的优先级
ErrorType BehaviorPlanner::MultiBehaviorJudge(
    const decimal_t previous_desired_vel, LateralBehavior* mpdm_behavior,
    decimal_t* mpdm_desired_velocity) {
  // Step 1: 获取关键语义车辆信息
  common::SemanticVehicleSet semantic_vehicle_set;
  if (map_itf_->GetKeySemanticVehicles(&semantic_vehicle_set) != kSuccess) {
    printf("[MPDM]fail to get key vehicles.\n");
    return kWrongStatus;
  }
  // Step 2: 获取自车信息
  common::Vehicle ego_vehicle;
  if (map_itf_->GetEgoVehicle(&ego_vehicle) != kSuccess) {
    printf("[MPDM]fail to get ego vehicle.\n");
    return kWrongStatus;
  }

  std::cout << "[BehaviorPlanner]" << ego_vehicle.id()
            << "\tsemantic_vehicle_set num:"
            << semantic_vehicle_set.semantic_vehicles.size() << std::endl;

  // Step 3: 清空状态
  forward_trajs_.clear();
  forward_behaviors_.clear();
  surround_trajs_.clear();

  // Step 4: 收集潜在的行为
  std::vector<LateralBehavior> potential_behaviors{
      common::LateralBehavior::kLaneKeeping};
  if (!potential_lcl_lane_ids_.empty())
    potential_behaviors.push_back(common::LateralBehavior::kLaneChangeLeft);
  if (!potential_lcr_lane_ids_.empty())
    potential_behaviors.push_back(common::LateralBehavior::kLaneChangeRight);
  // 新增Nudge行为
  if (!potential_nudge_left_lane_ids_.empty())
    potential_behaviors.push_back(common::LateralBehavior::kNudgeLeft);
  if (!potential_nudge_right_lane_ids_.empty())
    potential_behaviors.push_back(common::LateralBehavior::kNudgeRight);

  // Step 5: 构造<车辆，参考车道>对
  // 设置最大后退距离为10.0米
  const decimal_t max_backward_len = 10.0;
  // 遍历所有语义车辆（即在地图中识别的关键车辆）
  for (auto it = semantic_vehicle_set.semantic_vehicles.begin();
       it != semantic_vehicle_set.semantic_vehicles.end(); ++it) { // 遍历每一辆Key Surrounding Car
    // 获取当前车辆的预测行为
    common::LateralBehavior lat_behavior;
    // 如果能获取到当前车辆的预测行为，则赋值给 lat_behavior；否则默认为车道保持行为（kLaneKeeping）
    if (map_itf_->GetPredictedBehavior(it->second.vehicle.id(),
                                       &lat_behavior) != kSuccess) {
      lat_behavior = common::LateralBehavior::kLaneKeeping; // 默认为车道保持
    }
    // 根据当前车辆的速度计算前向车道的长度，最大值为50米，最小值为车辆速度的10倍
    decimal_t forward_lane_len =
        std::max(it->second.vehicle.state().velocity * 10.0, 50.0);
    // 获取参考车道（即该车辆在当前行为下所在的车道）
    common::Lane ref_lane;
    // 调用接口获取车辆的参考车道
    if (map_itf_->GetRefLaneForStateByBehavior(
            it->second.vehicle.state(), std::vector<int>(), lat_behavior,
            forward_lane_len, max_backward_len, false, &ref_lane) == kSuccess) {
      // 如果成功获取参考车道，则将其赋值给当前车辆
      it->second.lane = ref_lane;
    }
  }

  // Step 6: 前向仿真
  // 设置有效行为列表、前向轨迹列表和周围车辆轨迹列表
  std::vector<LateralBehavior> valid_behaviors;
  vec_E<vec_E<common::Vehicle>> valid_forward_trajs;
  vec_E<std::unordered_map<int, vec_E<common::Vehicle>>> valid_surround_trajs;
  int num_available_behaviors = static_cast<int>(potential_behaviors.size());

  TicToc t3;
  std::ofstream log_file3("/home/bigdavid/EPSILON_ws/doc/simulate_all_the_behaviors.txt", std::ios::app);

  // 循环遍历所有潜在的行为
  for (int i = 0; i < num_available_behaviors; i++) {
    vec_E<common::Vehicle> traj; // 存储当前行为下的前向轨迹
    std::unordered_map<int, vec_E<common::Vehicle>> sur_trajs; // 存储当前行为下的周围车辆轨迹

    // Step 7: 模拟当前行为的前向轨迹
    if (SimulateEgoBehavior(ego_vehicle, potential_behaviors[i],
                            semantic_vehicle_set, &traj,
                            &sur_trajs) != kSuccess) {
      // 如果模拟失败，则输出失败信息，并跳过当前行为
      printf("[MPDM]fail to sim %d forward.\n",
             static_cast<int>(potential_behaviors[i]));
      continue;
    }

    if (log_file3.is_open()) {
      log_file3 << "Time in simulate behavior" << static_cast<int>(potential_behaviors[i]) << " " << t3.toc() << " ms.\n";
    }

    // Step 8: 如果模拟成功，将当前行为和轨迹加入有效列表
    valid_behaviors.push_back(potential_behaviors[i]);
    valid_forward_trajs.push_back(traj);
    valid_surround_trajs.push_back(sur_trajs);
  }

  if (log_file3.is_open()) {
    log_file3 << "[Summary]Time in simulate all the behaviors: " << t3.toc() << " ms.\n";
    log_file3.close();
  }
  // printf("[Summary]Time in simulate all the behaviors: %lf ms.\n",
  // timer.toc());

  // Step 9: 缓存有效行为和轨迹
  forward_behaviors_ = valid_behaviors;
  forward_trajs_ = valid_forward_trajs;
  surround_trajs_ = valid_surround_trajs;

  // Step 10: 判断有效轨迹的数量
  int num_valid_behaviors = static_cast<int>(valid_behaviors.size());
  if (num_valid_behaviors < 1) {
    // 如果没有有效的行为，输出错误信息并返回错误状态
    printf("[MPDM]No valid behaviors.\n");
    return kWrongStatus;
  }
  // 最优行为的得分和期望速度
  decimal_t winner_score, winner_desired_vel;
  LateralBehavior winner_behavior;            // 最优行为
  vec_E<common::Vehicle> winner_forward_traj; // 最优行为对应的前向轨迹
  
  TicToc t4;
  std::ofstream log_file4("/home/bigdavid/EPSILON_ws/doc/EvaluateMultiPolicyTrajs.txt", std::ios::app);
  
  // Step 11: 评估所有有效行为的轨迹，并选择最优行为
  if (EvaluateMultiPolicyTrajs(valid_behaviors, valid_forward_trajs,
                               valid_surround_trajs, &winner_behavior,
                               &winner_forward_traj, &winner_score,
                               &winner_desired_vel) != kSuccess) {
    // 如果评估失败，输出错误信息并返回错误状态
    printf("[MPDM]fail to evaluate multiple policy trajs.\n");
    return kWrongStatus;
  }

  if (log_file4.is_open()) {
    log_file4 << "[Summary]Time in simulate all the behaviors: " << t4.toc() << " ms.\n";
    log_file4 << "valid_behaviors.size(): " << valid_behaviors.size() << "\n";
    log_file4.close();
  }

  // * output
  // 选择最优行为后，确保期望速度与当前速度差距不过大
  const decimal_t max_vel_cmd_gap = 5.0; // 最大速度命令差距为5.0
  if (fabs(winner_desired_vel - ego_vehicle.state().velocity) >
      max_vel_cmd_gap) {
    // 如果期望速度与当前速度差距大于最大限制，则调整期望速度
    if (winner_desired_vel > ego_vehicle.state().velocity) {
      winner_desired_vel = ego_vehicle.state().velocity + max_vel_cmd_gap;
    } else {
      winner_desired_vel = ego_vehicle.state().velocity - max_vel_cmd_gap;
    }
  }
  // Step 13: 如果需要锁定行为到HMI
  if (lock_to_hmi_) {
    // 查找是否HMI行为在有效行为中，如果在，则锁定为HMI行为
    auto it = std::find(forward_behaviors_.begin(), forward_behaviors_.end(),
                        hmi_behavior_);
    if (it != forward_behaviors_.end()) {
      *mpdm_behavior = hmi_behavior_;
    } else {
      *mpdm_behavior = winner_behavior; // 否则选择最优行为
    }
  } else { // 不需要锁定行为到HMI，直接选择最优行为
    *mpdm_behavior = winner_behavior;
  }
  // Step 14: 输出最优行为对应的期望速度
  *mpdm_desired_velocity = winner_desired_vel;
  return kSuccess;
}

// 用于进行自车与周围车辆的开环仿真，模拟自车的轨迹和周围车辆的轨迹
ErrorType BehaviorPlanner::OpenloopSimForward(
    const common::SemanticVehicle& ego_semantic_vehicle,
    const common::SemanticVehicleSet& agent_vehicles,
    const decimal_t& lat_offset,  // 新增：横向偏移量
    vec_E<common::Vehicle>* traj,
    std::unordered_map<int, vec_E<common::Vehicle>>* surround_trajs) {
  traj->clear(); // 清空自车轨迹容器
  traj->push_back(ego_semantic_vehicle.vehicle); // 将自车的初始状态添加到轨迹中
  surround_trajs->clear();                       // 清空周围车辆轨迹容器
  // Step 1: 初始化周围车辆的轨迹
  for (const auto &v : agent_vehicles.semantic_vehicles) {
    surround_trajs->insert(std::pair<int, vec_E<common::Vehicle>>(
        v.first, vec_E<common::Vehicle>()));
    surround_trajs->at(v.first).push_back(v.second.vehicle); // 记录周围车辆的初始状态
  }
  // Step 2: 计算仿真步数（仿真总时长 / 单步分辨率）
  int num_steps_forward = static_cast<int>(sim_horizon_ / sim_resolution_);
  // Step 3: 初始化自车和周围车辆状态
  common::Vehicle cur_ego_vehicle = ego_semantic_vehicle.vehicle;      // 当前自车状态
  common::SemanticVehicleSet semantic_vehicle_set_tmp = agent_vehicles;// 临时保存周围车辆
  common::State ego_state;

  // 获取自车的横向偏移量（Nudge行为专用）
  decimal_t ego_lat_offset = ego_semantic_vehicle.lat_offset;

  // Step 4: 对每个仿真时间步进行迭代
  for (int i = 0; i < num_steps_forward; i++) {
    // 4.1 设置自车的期望速度（来自参考速度）
    sim_param_.idm_param.kDesiredVelocity = reference_desired_velocity_; 

    // 核心修改：自车仿真应用横向偏移
    ErrorType sim_result = planning::OnLaneForwardSimulation::PropagateOnceAdvancedLK(
      common::StateTransformer(ego_semantic_vehicle.lane),
      cur_ego_vehicle,
      common::Vehicle(),  // 无前车
      ego_lat_offset,     // 应用Nudge横向偏移
      sim_resolution_,
      sim_param_,
      &ego_state);
    
    if (sim_result != kSuccess) {
      printf("[MPDM]open loop ego forward failed.\n");
      return kWrongStatus;
    }

    // // 4.2 推进自车状态（前向仿真一次）
    // if (planning::OnLaneForwardSimulation::PropagateOnce(
    //         common::StateTransformer(ego_semantic_vehicle.lane), // 当前车道
    //         cur_ego_vehicle, common::Vehicle(), sim_resolution_, sim_param_,
    //         &ego_state) != kSuccess) {
    //   return kWrongStatus; // 如果推进失败，直接返回错误
    // }
    // 4.3 推进周围车辆状态
    std::unordered_map<int, State> state_cache; // 临时存储每辆周围车的状态
    for (auto& v : semantic_vehicle_set_tmp.semantic_vehicles) {
      // 获取当前车辆的期望速度（直接取初始设定的速度，不考虑动态交互）
      decimal_t desired_vel =
          agent_vehicles.semantic_vehicles.at(v.first).vehicle.state().velocity; // 周围车辆期望速度
      sim_param_.idm_param.kDesiredVelocity = desired_vel;
      common::State agent_state;
      // 推进周围车辆状态（和自车类似，也不考虑前车）
      if (planning::OnLaneForwardSimulation::PropagateOnce(
              common::StateTransformer(v.second.lane), v.second.vehicle,
              common::Vehicle(), sim_resolution_, sim_param_,
              &agent_state) != kSuccess) {
        return kWrongStatus; // 如果推进失败，返回错误
      }
      state_cache.insert(std::make_pair(v.first, agent_state)); // 保存周围车辆的状态
    }
    // 4.4 碰撞检测（检查自车是否和周围车相撞）
    bool is_collision = false;
    map_itf_->CheckIfCollision(ego_semantic_vehicle.vehicle.param(), ego_state,
                               &is_collision);
    if (is_collision) return kWrongStatus; // 如果碰撞，返回错误状态

    // 4.5 更新车辆集合并记录轨迹
    cur_ego_vehicle.set_state(ego_state);
    for (auto& s : state_cache) {
      semantic_vehicle_set_tmp.semantic_vehicles.at(s.first).vehicle.set_state(
          s.second); // 更新周围车辆状态
      surround_trajs->at(s.first).push_back(
          semantic_vehicle_set_tmp.semantic_vehicles.at(s.first).vehicle); // 将周围车辆轨迹更新
    }
    traj->push_back(cur_ego_vehicle); // 将当前自车状态加入轨迹
  }
  return kSuccess; // Step 5: 仿真完成，返回成功
}

// 模拟自车在给定行为下的轨迹，首先进行多智能体仿真。如果失败，回退为开环仿真
ErrorType BehaviorPlanner::SimulateEgoBehavior(
    const common::Vehicle& ego_vehicle, const LateralBehavior& ego_behavior,
    const common::SemanticVehicleSet& semantic_vehicle_set,
    vec_E<common::Vehicle>* traj,
    std::unordered_map<int, vec_E<common::Vehicle>>* surround_trajs) {
  const decimal_t max_backward_len = 10.0;
  decimal_t forward_lane_len =
      std::max(ego_vehicle.state().velocity * 10.0, 50.0);
  common::Lane ego_reflane;

  decimal_t lat_offset = 0.0; // 横向偏移量，用于Nudge

  // // 获取自车参考车道
  // if (map_itf_->GetRefLaneForStateByBehavior(
  //         ego_vehicle.state(), p_route_planner_->navi_path(), ego_behavior,
  //         forward_lane_len, max_backward_len, false,
  //         &ego_reflane) != kSuccess) {
  //   printf("[MPDM]fail to get ego reference lane.\n");
  //   return kWrongStatus; // 获取参考车道失败，返回错误
  // }
  // 获取自车参考车道（Nudge行为使用当前车道，仅添加横向偏移）
  if (map_itf_->GetRefLaneForStateByBehavior(
    ego_vehicle.state(), p_route_planner_->navi_path(), 
    (ego_behavior == common::LateralBehavior::kNudgeLeft || 
     ego_behavior == common::LateralBehavior::kNudgeRight) ? 
     common::LateralBehavior::kLaneKeeping : ego_behavior,
      forward_lane_len, max_backward_len, false, &ego_reflane) != kSuccess) {
    printf("[MPDM]fail to get ego reference lane.\n");
    return kWrongStatus;
  }

  // 设置Nudge行为的横向偏移（例如±0.5米，根据车辆宽度和车道宽度调整）
  const decimal_t kNudgeOffset = 0.5;  // 微移偏移量
  if (ego_behavior == common::LateralBehavior::kNudgeLeft) {
    lat_offset = kNudgeOffset;
    printf("[MPDM]simulating Nudge Left with offset: %.2f\n", lat_offset);
  } else if (ego_behavior == common::LateralBehavior::kNudgeRight) {
    lat_offset = -kNudgeOffset;
    printf("[MPDM]simulating Nudge Right with offset: %.2f\n", lat_offset);
  }

  // 包装自车信息
  common::SemanticVehicle ego_semantic_vehicle;
  {
    ego_semantic_vehicle.vehicle = ego_vehicle;
    ego_semantic_vehicle.lane = ego_reflane;
    ego_semantic_vehicle.lat_offset = lat_offset;
  }

  // 临时保存周围车辆的集合
  common::SemanticVehicleSet semantic_vehicle_set_tmp = semantic_vehicle_set;
  semantic_vehicle_set_tmp.semantic_vehicles.insert(
      std::make_pair(ego_vehicle.id(), ego_semantic_vehicle));

  // ~ multi-agent forward
  // 多智能体仿真
  TicToc t2;
  std::ofstream log_file2("/home/bigdavid/EPSILON_ws/doc/multi_agent.txt", std::ios::app);

  printf("[MPDM]simulating behavior %d.\n", static_cast<int>(ego_behavior));
  
  // if (MultiAgentSimForward(ego_vehicle.id(), semantic_vehicle_set_tmp, traj,
  //                          surround_trajs) != kSuccess) {
  //   printf("[MPDM]multi agent forward under %d failed.\n",
  //          static_cast<int>(ego_behavior));
  //   // 如果多智能体仿真失败，回退到开环仿真
  //   if (OpenloopSimForward(ego_semantic_vehicle, semantic_vehicle_set, traj,
  //                          surround_trajs) != kSuccess) {
  //     printf("[MPDM]open loop forward under %d failed.\n",
  //            static_cast<int>(ego_behavior));
  //     return kWrongStatus; // 如果开环仿真失败，返回错误
  //   }
  // }
  
  bool multi_agent_success = false;
  if (ego_behavior == common::LateralBehavior::kNudgeLeft || 
    ego_behavior == common::LateralBehavior::kNudgeRight) {
    // 针对Nudge行为的多智能体仿真（使用带偏移的参考轨迹）
    multi_agent_success = (MultiAgentSimForward(
        ego_vehicle.id(), semantic_vehicle_set_tmp, lat_offset,  // 传入偏移量
        traj, surround_trajs) == kSuccess);
  } else {
    // 原有行为的多智能体仿真
    multi_agent_success = (MultiAgentSimForward(
        ego_vehicle.id(), semantic_vehicle_set_tmp, 0.0,  // 无偏移
        traj, surround_trajs) == kSuccess);
  }

  if (!multi_agent_success) {
    printf("[MPDM]multi agent forward under %d failed, fallback to openloop.\n",
           static_cast<int>(ego_behavior));
    
    // 开环仿真（带横向偏移处理）
    if (ego_behavior == common::LateralBehavior::kNudgeLeft || 
        ego_behavior == common::LateralBehavior::kNudgeRight) {
      if (OpenloopSimForward(ego_semantic_vehicle, semantic_vehicle_set, 
                             lat_offset, traj, surround_trajs) != kSuccess) {
        printf("[MPDM]open loop forward under %d failed.\n",
               static_cast<int>(ego_behavior));
        return kWrongStatus;
      }
    } else {
      if (OpenloopSimForward(ego_semantic_vehicle, semantic_vehicle_set, 
                             0.0, traj, surround_trajs) != kSuccess) {
        printf("[MPDM]open loop forward under %d failed.\n",
               static_cast<int>(ego_behavior));
        return kWrongStatus;
      }
    }
  }

  if (log_file2.is_open()) {
    log_file2 << "[Summary] multi-agent time cost: " << t2.toc() << " ms.\n";
    log_file2.close();
  }

  // 校验轨迹是否包含横向偏移
  if (lat_offset != 0.0 && !traj->empty()) {
    // 1. 去掉引用符号，直接获取状态副本（因state()返回值而非引用）
    auto first_state = (*traj)[0].state();
    auto last_state = (*traj).back().state();
    // 2. 将position改为vec_position（正确的成员名）
    printf("[MPDM]Nudge trajectory offset check: start=%.2f, end=%.2f\n",
          first_state.vec_position[1] - ego_vehicle.state().vec_position[1],
          last_state.vec_position[1] - ego_vehicle.state().vec_position[1]);
  }

  // 输出仿真结果
  printf("[MPDM]behavior %d traj num of states: %d.\n",
         static_cast<int>(ego_behavior), static_cast<int>(traj->size()));
  return kSuccess;
}

// 评估多个行为下的轨迹，并选择得分最小的行为作为最优选择
ErrorType BehaviorPlanner::EvaluateMultiPolicyTrajs(
    const std::vector<LateralBehavior>& valid_behaviors,
    const vec_E<vec_E<common::Vehicle>>& valid_forward_trajs,
    const vec_E<std::unordered_map<int, vec_E<common::Vehicle>>>&
        valid_surround_trajs,
    LateralBehavior* winner_behavior,
    vec_E<common::Vehicle>* winner_forward_traj, decimal_t* winner_score,
    decimal_t* desired_vel) {
  // 合理行为的数量
  int num_valid_behaviors = static_cast<int>(valid_behaviors.size());
  // 如果没有有效的行为，返回错误
  if (num_valid_behaviors < 1) return kWrongStatus;

  // 存储最优轨迹
  vec_E<common::Vehicle> traj;
  LateralBehavior behavior = common::LateralBehavior::kUndefined;
  // 初始化最小得分为正无穷
  decimal_t min_score = kInf;
  // 初始化期望速度为 0
  decimal_t des_vel = 0.0;
  // 遍历每种有效行为，评估其轨迹得分
  for (int i = 0; i < num_valid_behaviors; i++) {
    decimal_t score, vel;
    // 评估轨迹
    EvaluateSinglePolicyTraj(valid_behaviors[i], valid_forward_trajs[i],
                             valid_surround_trajs[i], &score, &vel);

    // 选择得分最低的轨迹行为
    if (score < min_score) {
      min_score = score;
      des_vel = vel;
      behavior = valid_behaviors[i];
      traj = valid_forward_trajs[i];
    }
  }
  // 输出选择的最优行为和得分
  printf("[MPDM]choose behavior %d with cost %lf.\n",
         static_cast<int>(behavior), min_score);
  *winner_forward_traj = traj;
  *winner_behavior = behavior;
  *winner_score = min_score;
  *desired_vel = des_vel;
  return kSuccess;
}

// 通过判断两个轨迹是否发生碰撞来计算安全性
ErrorType BehaviorPlanner::EvaluateSafetyCost(
    const vec_E<common::Vehicle>& traj_a, const vec_E<common::Vehicle>& traj_b,
    decimal_t* cost) {
  if (traj_a.size() != traj_b.size()) { // 如果两个轨迹的长度不一致，返回错误
    return kWrongStatus;
  }
  int num_states = static_cast<int>(traj_a.size()); // 获取轨迹状态的数量
  decimal_t cost_tmp = 0.0;
  // 遍历轨迹中的每个状态
  for (int i = 0; i < num_states; i++) {
    common::Vehicle inflated_a, inflated_b;
    // 扩展车辆的尺寸，避免碰撞
    common::SemanticsUtils::InflateVehicleBySize(traj_a[i], 1.0, 1.0,
                                                 &inflated_a);
    common::SemanticsUtils::InflateVehicleBySize(traj_b[i], 1.0, 1.0,
                                                 &inflated_b);
    bool is_collision = false;
    // 检查两个车辆是否发生碰撞
    map_itf_->CheckCollisionUsingState(inflated_a.param(), inflated_a.state(),
                                       inflated_b.param(), inflated_b.state(),
                                       &is_collision);
    if (is_collision) {
      // 如果发生碰撞，计算安全成本
      cost_tmp +=
          0.01 * fabs(traj_a[i].state().velocity - traj_b[i].state().velocity) *
          0.5;
    }
  }
  *cost = cost_tmp; // 将计算出的安全成本返回
  return kSuccess;
}

// 评估单一行为的轨迹，包括效率、安全性和行为成本等多个方面
ErrorType BehaviorPlanner::EvaluateSinglePolicyTraj(
    const LateralBehavior& behavior, const vec_E<common::Vehicle>& forward_traj,
    const std::unordered_map<int, vec_E<common::Vehicle>>& surround_traj,
    decimal_t* score, decimal_t* desired_vel) {
  // prepare
  // 准备周围车辆的集合
  common::VehicleSet vehicle_set;
  for (auto it = surround_traj.begin(); it != surround_traj.end(); ++it) {
    if (!it->second.empty()) {
      vehicle_set.vehicles.insert(std::make_pair(it->first, it->second.back()));
    }
  }
  // * efficiency
  // 计算效率相关的成本
  common::Vehicle ego_vehicle_terminal = forward_traj.back(); // 获取自车的终点状态
  decimal_t cost_efficiency_ego_to_desired_vel =
      fabs(ego_vehicle_terminal.state().velocity -
           reference_desired_velocity_) /
      10.0;
  common::Vehicle leading_vehicle;
  // 获取自车参考车道
  common::Lane ego_ref_lane;
  const decimal_t max_backward_len = 10.0;
  decimal_t forward_lane_len =
      std::max(ego_vehicle_terminal.state().velocity * 10.0, 50.0);
  if (map_itf_->GetRefLaneForStateByBehavior(
          ego_vehicle_terminal.state(), p_route_planner_->navi_path(),
          common::LateralBehavior::kLaneKeeping, forward_lane_len,
          max_backward_len, false, &ego_ref_lane) != kSuccess) {
    printf("fail to get ego ref lane duration evaluation for behavior %d.\n",
           static_cast<int>(behavior));
  }
  // 计算自车到参考速度的效率
  decimal_t cost_efficiency_leading_to_desired_vel = 0.0;
  decimal_t distance_residual_ratio = 0.0;
  const decimal_t lat_range = 2.2;
  if (map_itf_->GetLeadingVehicleOnLane(
          ego_ref_lane, ego_vehicle_terminal.state(), vehicle_set, lat_range,
          &leading_vehicle, &distance_residual_ratio) == kSuccess) {
    decimal_t distance_to_leading_vehicle =
        (leading_vehicle.state().vec_position -
         ego_vehicle_terminal.state().vec_position)
            .norm();
    // 如果自车和前车的速度均小于期望速度且距离较近，则增加效率成本
    if (ego_vehicle_terminal.state().velocity < reference_desired_velocity_ &&
        leading_vehicle.state().velocity < reference_desired_velocity_ &&
        distance_to_leading_vehicle < 100.0) {
      cost_efficiency_leading_to_desired_vel =
          1.5 * distance_residual_ratio *
          fabs(ego_vehicle_terminal.state().velocity -
               reference_desired_velocity_) /
          std::max(2.0, distance_to_leading_vehicle);
    }
  }
  // 总效率成本
  decimal_t cost_efficiency = 0.5 * (cost_efficiency_ego_to_desired_vel +
                                     cost_efficiency_leading_to_desired_vel);

  // * safety
  // 安全成本
  decimal_t cost_safety = 0.0;
  for (auto& traj : surround_traj) {
    decimal_t safety_tmp = 0.0;
    EvaluateSafetyCost(forward_traj, traj.second, &safety_tmp); // 评估与周围车辆的安全性
    cost_safety += safety_tmp;
  }

  // * action
  // 行为成本
  decimal_t cost_action = 0.0;
  if (behavior != common::LateralBehavior::kLaneKeeping) {
    cost_action += 0.5; // 如果不是保持车道行为，增加成本
  }

  // 总得分 = 行为成本 + 安全成本 + 效率成本
  *score = cost_action + cost_safety + cost_efficiency;
  printf(
      "[CostDebug]behaivor %d: (action %lf, safety %lf, efficiency ego %lf, "
      "leading %lf).\n",
      static_cast<int>(behavior), cost_action, cost_safety,
      cost_efficiency_ego_to_desired_vel,
      cost_efficiency_leading_to_desired_vel);
  // 获取轨迹的期望速度
  GetDesiredVelocityOfTrajectory(forward_traj, desired_vel);
  return kSuccess;
}

// 获取轨迹的期望速度，通常是轨迹中最小的正常加速度所对应的速度
ErrorType BehaviorPlanner::GetDesiredVelocityOfTrajectory(
    const vec_E<common::Vehicle> vehicle_vec, decimal_t* vel) {
  decimal_t min_vel = kInf; // 初始化为正无穷
  decimal_t max_acc_normal = 0.0;
  // 遍历轨迹中的每辆车，计算最小的期望速度
  for (auto& v : vehicle_vec) {
    auto state = v.state();
    auto acc_normal = fabs(state.curvature) * pow(state.velocity, 2); // 计算法向加速度
    min_vel = acc_normal > max_acc_normal ? state.velocity : min_vel; // 选择最小的速度
  }
  *vel = min_vel; // 返回最小速度
  return kSuccess;
}

// 用于进行多智能体仿真，模拟自车与周围车辆在多个时间步的行为，计算每个车辆的轨迹
ErrorType BehaviorPlanner::MultiAgentSimForward(
    const int ego_id, const common::SemanticVehicleSet& semantic_vehicle_set,
    const decimal_t& lat_offset,  // 新增：横向偏移量
    vec_E<common::Vehicle>* traj,
    std::unordered_map<int, vec_E<common::Vehicle>>* surround_trajs) {
  // Step 1: 清空轨迹并将自车的初始状态加入轨迹
  traj->clear();
  traj->push_back(semantic_vehicle_set.semantic_vehicles.at(ego_id).vehicle); // 将自车的初始状态加入轨迹
  // Step 2: 初始化周围车辆的轨迹
  // 遍历所有的周围车辆，并将其轨迹初始化为空
  surround_trajs->clear();
  for (const auto &v : semantic_vehicle_set.semantic_vehicles) {
    if (v.first == ego_id) continue; // 如果是自车则跳过
    surround_trajs->insert(std::pair<int, vec_E<common::Vehicle>>(
        v.first, vec_E<common::Vehicle>())); // 初始化周围车辆的轨迹为空
    surround_trajs->at(v.first).push_back(v.second.vehicle); // 将车辆初始状态加入对应的轨迹
  }
  // Step 3: 计算仿真步数（即仿真持续的时间步数）
  int num_steps_forward = static_cast<int>(sim_horizon_ / sim_resolution_); // 4 / 0.4
  // 创建临时的语义车辆集合便于仿真
  common::SemanticVehicleSet semantic_vehicle_set_tmp = semantic_vehicle_set;

  // add: 获取自车的横向偏移量Nudge
  decimal_t ego_lat_offset = semantic_vehicle_set.semantic_vehicles.at(ego_id).lat_offset;


  TicToc timer;// 创建计时器，用于计算每一步的时间
  // Step 4: 执行多步仿真
  for (int i = 0; i < num_steps_forward; i++) {
    // 记录每步的开始时间
    timer.tic();
    // 用于存储每个车辆的状态缓存
    std::unordered_map<int, State> state_cache;
    // Step 5: 对每个周围车辆进行状态更新
    for (auto& v : semantic_vehicle_set_tmp.semantic_vehicles) {
      decimal_t desired_vel = semantic_vehicle_set.semantic_vehicles.at(v.first)
                                  .vehicle.state()
                                  .velocity; // 获取当前车辆的期望速度
      decimal_t init_stamp = semantic_vehicle_set.semantic_vehicles.at(v.first)
                                 .vehicle.state()
                                 .time_stamp;// 获取车辆的初始时间戳
      // 如果是自车，使用自车的期望速度
      if (v.first == ego_id) desired_vel = reference_desired_velocity_;

      common::VehicleSet vehicle_set;
      // Step 6: 获取所有其他车辆的集合
      for (auto& v_other : semantic_vehicle_set_tmp.semantic_vehicles) {
        // ~ get the subset of vehicles excluding the simulating one
        // 获取除当前车辆外的其他车辆
        if (v_other.first != v.first)
          vehicle_set.vehicles.insert(
              std::make_pair(v_other.first, v_other.second.vehicle));
      }
      // 存储当前车道的限速
      decimal_t speed_limit;
      // Step 7: 获取车辆当前所在车道的限速，并调整期望速度
      if (map_itf_->GetSpeedLimit(v.second.vehicle.state(), v.second.lane,
                                  &speed_limit) == kSuccess) {
        // 期望速度受限速限制
        desired_vel = std::min(speed_limit * 0.9, desired_vel);
      }
      // 更新期望速度参数
      sim_param_.idm_param.kDesiredVelocity = desired_vel;
      // Step 8: 获取当前车辆所在车道的前车，并检查是否发生碰撞
      common::Vehicle leading_vehicle;
      common::State state;
      decimal_t distance_residual_ratio = 0.0;
      const decimal_t lat_range = 2.2; // 车辆前方的横向范围
      // 获取前车
      if (map_itf_->GetLeadingVehicleOnLane(
              v.second.lane, v.second.vehicle.state(), vehicle_set, lat_range,
              &leading_vehicle, &distance_residual_ratio) == kSuccess) {
        bool is_collision = false;
        // 检查自车和前车是否发生碰撞
        map_itf_->CheckCollisionUsingState(
            v.second.vehicle.param(), v.second.vehicle.state(),
            leading_vehicle.param(), leading_vehicle.state(), &is_collision);
        if (is_collision) {
          return kWrongStatus; // 如果发生碰撞，返回错误
        }
      }

      // 自车使用横向偏移
      ErrorType sim_result;
      if (v.first == ego_id) {
        // 自车使用带横向偏移的高级车道保持仿真
        sim_result = planning::OnLaneForwardSimulation::PropagateOnceAdvancedLK(
          common::StateTransformer(v.second.lane),
          v.second.vehicle,
          leading_vehicle,
          ego_lat_offset,  // 应用Nudge横向偏移
          sim_resolution_,
          sim_param_,
          &state);
      } else {
        // 其他车辆使用原有仿真逻辑
        sim_result = planning::OnLaneForwardSimulation::PropagateOnce(
          common::StateTransformer(v.second.lane), v.second.vehicle,
          leading_vehicle, sim_resolution_, sim_param_,
          &state);
      }

      if (sim_result != kSuccess) {
        printf("[MPDM]fail to forward vehicle %d.\n", v.first);
        return kWrongStatus;
      }
      // // Step 9: 进行一次前向仿真，更新车辆状态 0.4s
      // if (planning::OnLaneForwardSimulation::PropagateOnce(
      //         common::StateTransformer(v.second.lane), v.second.vehicle,
      //         leading_vehicle, sim_resolution_, sim_param_,
      //         &state) != kSuccess) {
      //   printf("[MPDM]fail to forward with leading vehicle.\n");
      //   return kWrongStatus; // 如果前向仿真失败，返回错误
      // }

      // 更新状态
      // 更新仿真时间戳
      state.time_stamp = init_stamp + (i + 1) * sim_resolution_;
      // 将更新后的状态加入缓存
      state_cache.insert(std::make_pair(v.first, state));
    }

    // Step 10: 使用状态缓存更新车辆集合
    for (auto& s : state_cache) {
      semantic_vehicle_set_tmp.semantic_vehicles.at(s.first).vehicle.set_state(
          s.second);
      // Step 11: 根据车辆ID，将更新后的车辆加入轨迹
      if (s.first == ego_id) {
        traj->push_back(
            semantic_vehicle_set_tmp.semantic_vehicles.at(s.first).vehicle);
      } else {
        surround_trajs->at(s.first).push_back(
            semantic_vehicle_set_tmp.semantic_vehicles.at(s.first).vehicle);
      }
    }
  }  // 完成所有时间步的仿真
  return kSuccess; // 返回仿真成功
}

// 构建参考车道，根据不同的横向行为（如车道保持、左车道变换、右车道变换）确定目标车道并构建其轨迹
ErrorType BehaviorPlanner::ConstructReferenceLane(
    const LateralBehavior& lat_behavior, Lane* lane) {
  if (map_itf_ == nullptr) return kWrongStatus; // 检查地图接口是否为空

  int target_lane_id;
  if (lat_behavior == common::LateralBehavior::kLaneKeeping ||
      lat_behavior == common::LateralBehavior::kUndefined) {
    // 如果行为是kLaneKeeping || kUndefined，目标车道为当前车道
    target_lane_id = ego_lane_id_;
  } else if (lat_behavior == common::LateralBehavior::kLaneChangeLeft) {
    // 如果是左车道变换，但找不到目标左车道，则保持当前车道
    if (map_itf_->GetLeftLaneId(ego_lane_id_, &target_lane_id) != kSuccess) {
      printf("[BP]Commanding a left lane change, but no existing lane.\n");
      target_lane_id = ego_lane_id_;
      behavior_.lat_behavior = common::LateralBehavior::kLaneKeeping;
    }
  } else if (lat_behavior == common::LateralBehavior::kLaneChangeRight) { // 如果是右车道变换，但找不到目标右车道，则保持当前车道
    if (map_itf_->GetRightLaneId(ego_lane_id_, &target_lane_id) != kSuccess) {
      printf("[BP]Commanding a right lane change, but no existing lane.\n");
      target_lane_id = ego_lane_id_;
      behavior_.lat_behavior = common::LateralBehavior::kLaneKeeping;
    }
  } else {
    assert(false); // 如果行为类型不符合预期，触发断言
  }
  // 获取当前自车状态
  State ego_state;
  map_itf_->GetEgoState(&ego_state);
  // 最大参考车道距离
  const decimal_t kMaxReflaneDist = 150.0;
  // 后退距离
  const decimal_t kBackwardDist = 20.0;
  vec_Vecf<2> samples;
  // 获取当前车道的局部车道样本
  if (map_itf_->GetLocalLaneSamplesByState(
          ego_state, target_lane_id, p_route_planner_->navi_path(),
          kMaxReflaneDist, kBackwardDist, &samples) != kSuccess) {
    return kWrongStatus;
  }
  // 从样本数据构建车道
  if (ConstructLaneFromSamples(samples, lane) != kSuccess) {
    return kWrongStatus;
  }
  // 计算参考期望速度
  common::StateTransformer stf(*lane);
  common::FrenetState current_fs;
  stf.GetFrenetStateFromState(ego_state, &current_fs);

  decimal_t c, cc;
  decimal_t v_max_by_curvature;
  decimal_t v_ref = kInf;
  const decimal_t sim_lat_max = 1.5; // 最大侧向加速度(向心加速度)
  decimal_t a_comfort = 1.67;        // 舒适加速度
  decimal_t t_forward = ego_state.velocity / a_comfort; // 舒服的减速时间
  decimal_t s_forward =
      std::min(std::max(20.0, t_forward * ego_state.velocity), lane->end()); // 计算前进的距离
  decimal_t resolution = 0.2; // 采样精度

  for (decimal_t s = current_fs.vec_s[0]; s < current_fs.vec_s[0] + s_forward;
       s += resolution) {
    if (lane->GetCurvatureByArcLength(s, &c, &cc) == kSuccess) {
      // 计算与车道曲率相关的最大速度
      v_max_by_curvature = sqrt(sim_lat_max / fabs(c)); // a = v^2 / R: 根据车道线上点的曲率圆半径计算最大线速度
      v_ref = v_max_by_curvature < v_ref ? v_max_by_curvature : v_ref; // 选择最小的最大速度
    }
  }
  // 根据当前车道线形状计算期望速度
  reference_desired_velocity_ =
      std::floor(std::min(std::max(v_ref - 2.0, 0.0), user_desired_velocity_));

  // printf("[DEBUG]reference desired vel %lf.\n", reference_desired_velocity_);
  return kSuccess;
}

// 通过样本点数据拟合出一条车道
ErrorType BehaviorPlanner::ConstructLaneFromSamples(
    const vec_E<Vecf<2>>& samples, Lane* lane) {
  double d = 0.0;
  std::vector<decimal_t> para;
  para.push_back(d);

  int num_samples = static_cast<int>(samples.size());
  // 计算样本点之间的距离
  for (int i = 1; i < num_samples; i++) {
    double dx = samples[i](0) - samples[i - 1](0);
    double dy = samples[i](1) - samples[i - 1](1);
    d += std::hypot(dx, dy);
    para.push_back(d); // 每一点距离起点的近似弧长
  }

  const int num_segments = 20;
  // 生成分段点
  Eigen::ArrayXf breaks =
      Eigen::ArrayXf::LinSpaced(num_segments, para.front(), para.back());

  const decimal_t regulator = (double)1e6; // 正则化系数
  if (common::LaneGenerator::GetLaneBySampleFitting(
          samples, para, breaks, regulator, lane) != kSuccess) {
    // printf("fitting error.\n");
    return kWrongStatus; // 车道拟合失败
  }
  return kSuccess;
}

// 根据车道 ID 判断自车当前的横向行为（如车道保持、车道变换）
ErrorType BehaviorPlanner::JudgeBehaviorByLaneId(
    const int ego_lane_id_by_pos, LateralBehavior* behavior_by_lane_id) {
  if (ego_lane_id_by_pos == ego_lane_id_) {
    *behavior_by_lane_id = common::LateralBehavior::kLaneKeeping;
    return kSuccess;
  }
  // 判断是否在潜在的车道保持、左车道变换或右车道变换
  auto it = std::find(potential_lk_lane_ids_.begin(),
                      potential_lk_lane_ids_.end(), ego_lane_id_by_pos);
  auto it_lcl = std::find(potential_lcl_lane_ids_.begin(),
                          potential_lcl_lane_ids_.end(), ego_lane_id_by_pos);
  auto it_lcr = std::find(potential_lcr_lane_ids_.begin(),
                          potential_lcr_lane_ids_.end(), ego_lane_id_by_pos);

  if (it != potential_lk_lane_ids_.end()) {
    // ~ if routing information is available, here
    // ~ we still need to check whether the change is consist with the
    *behavior_by_lane_id = common::LateralBehavior::kLaneKeeping;
    return kSuccess;
  }

  if (it_lcl != potential_lcl_lane_ids_.end()) {
    *behavior_by_lane_id = common::LateralBehavior::kLaneChangeLeft;
    return kSuccess;
  }

  if (it_lcr != potential_lcr_lane_ids_.end()) {
    *behavior_by_lane_id = common::LateralBehavior::kLaneChangeRight;
    return kSuccess;
  }

  *behavior_by_lane_id = common::LateralBehavior::kUndefined;
  return kSuccess;
}

// 根据新的横向行为更新自车的行为状态
ErrorType BehaviorPlanner::UpdateEgoBehavior(
    const LateralBehavior& behavior_by_lane_id) {
  // 如果当前行为是车道保持（kLaneKeeping）
  if (behavior_.lat_behavior == common::LateralBehavior::kLaneKeeping) {
    if (behavior_by_lane_id == common::LateralBehavior::kLaneKeeping) {
      // 如果新的行为仍然是车道保持（没有变化），保持当前状态
    } else if (behavior_by_lane_id == common::LateralBehavior::kUndefined) { // 车道行为未定义
      // 如果新的行为未定义，说明系统检测到车道行为异常或跳变
      // ~ 在这种情况下，保持当前的车道保持行为
    } else {
      // ~ observed wrong behavior, cause undefined system behavior
      // 如果观察到不合法的行为（不是车道保持，也不是定义的行为）
      // ~ 说明系统进入了错误状态，设置为未定义状态
      // ~ 触发系统故障状态
      behavior_.lat_behavior = common::LateralBehavior::kUndefined;
    }
  } else if (behavior_.lat_behavior ==
             common::LateralBehavior::kLaneChangeLeft) { // 如果当前行为是左侧变道（kLaneChangeLeft）
    if (behavior_by_lane_id == common::LateralBehavior::kLaneKeeping) {
      // 如果当前行为变为车道保持，说明变道还没完成，继续变道
      // ~ 继续变道，不改变当前状态
      // ~ still in the course of lane changing
    } else if (behavior_by_lane_id ==
               common::LateralBehavior::kLaneChangeLeft) {
      // 如果新的行为也是左侧变道，说明变道完成
      // ~ 变道完成，恢复车道保持行为
      // ~ lane change complete
      behavior_.lat_behavior = common::LateralBehavior::kLaneKeeping;
      lock_to_hmi_ = false;
    } else if (behavior_by_lane_id == common::LateralBehavior::kUndefined) {
      // 如果新的行为是未定义的，说明变道过程中发生了不一致，取消变道
      // ~ 在变道过程中，发生了异常，取消变道行为，恢复车道保持
      // ~ lane id jumping in lane change, cancel lane change
      behavior_.lat_behavior = common::LateralBehavior::kLaneKeeping;
      lock_to_hmi_ = false;
    } else {
      // ~ wrong behavior
      // 如果观察到不合法的行为（不是左变道，也不是定义的行为）
      // ~ 设置为未定义行为，说明出现了错误
      behavior_.lat_behavior = common::LateralBehavior::kUndefined;
      lock_to_hmi_ = false;
    }
  } else if (behavior_.lat_behavior ==
             common::LateralBehavior::kLaneChangeRight) { // 如果当前行为是右侧变道（kLaneChangeRight）
    // 如果当前行为变为车道保持或者是Nudge，说明变道还没完成，继续变道
    // ~ 继续变道，不改变当前状态
    if (behavior_by_lane_id == common::LateralBehavior::kLaneKeeping) {
      // ~ still in the course of lane changing
    } else if (behavior_by_lane_id ==
               common::LateralBehavior::kLaneChangeRight) {
      // 如果新的行为也是右侧变道，说明变道完成
      // ~ 变道完成，恢复车道保持行为
      // ~ lane change complete
      behavior_.lat_behavior = common::LateralBehavior::kLaneKeeping;
      lock_to_hmi_ = false;
    } else if (behavior_by_lane_id == common::LateralBehavior::kUndefined) {
      // ~ lane id jumping in lane change, cancel lane change
      // 如果新的行为是未定义的，说明变道过程中发生了不一致，取消变道
      // ~ 在变道过程中，发生了异常，取消变道行为，恢复车道保持
      behavior_.lat_behavior = common::LateralBehavior::kLaneKeeping;
      lock_to_hmi_ = false;
    } else {
      // 如果观察到不合法的行为（不是右变道，也不是定义的行为）
      // ~ 设置为未定义行为，说明出现了错误
      behavior_.lat_behavior = common::LateralBehavior::kUndefined;
      lock_to_hmi_ = false;
    }
  }  // end enumerating current behaviors
  return kSuccess;
}

// 更新自车的车道 ID，并重新计算潜在的车道 ID
ErrorType BehaviorPlanner::UpdateEgoLaneId(const int new_ego_lane_id) {
  // 查找ego_car可能行驶的lanes
  ego_lane_id_ = new_ego_lane_id;
  GetPotentialLaneIds(ego_lane_id_, common::LateralBehavior::kLaneKeeping,
                      &potential_lk_lane_ids_);
  GetPotentialLaneIds(ego_lane_id_, common::LateralBehavior::kLaneChangeLeft,
                      &potential_lcl_lane_ids_);
  GetPotentialLaneIds(ego_lane_id_, common::LateralBehavior::kLaneChangeRight,
                      &potential_lcr_lane_ids_);
  return kSuccess;
}

// 根据横向行为计算潜在的车道 ID
ErrorType BehaviorPlanner::GetPotentialLaneIds(
    const int source_lane_id, const LateralBehavior& beh,
    std::vector<int>* candidate_lane_ids) {
  candidate_lane_ids->clear();
  if (beh == common::LateralBehavior::kUndefined ||
      beh == common::LateralBehavior::kLaneKeeping) { // 如果车道横向行为未定义、车道保持、Nudge, 获取当前车道的子车道
    map_itf_->GetChildLaneIds(source_lane_id, candidate_lane_ids); // 获取当前车道的子车道
  } else if (beh == common::LateralBehavior::kLaneChangeLeft) {
    int l_lane_id;
    if (map_itf_->GetLeftLaneId(source_lane_id, &l_lane_id) == kSuccess) {
      map_itf_->GetChildLaneIds(l_lane_id, candidate_lane_ids); // 获取左车道的子车道
      candidate_lane_ids->push_back(l_lane_id);                 // 将左车道加入候选车道
    }
  } else if (beh == common::LateralBehavior::kLaneChangeRight) {
    int r_lane_id;
    if (map_itf_->GetRightLaneId(source_lane_id, &r_lane_id) == kSuccess) {
      map_itf_->GetChildLaneIds(r_lane_id, candidate_lane_ids); // 获取右车道的子车道
      candidate_lane_ids->push_back(r_lane_id);                 // 将右车道加入候选车道
    }
  } else {
    assert(false);
  }
  return kSuccess;
}

// 设置地图接口
void BehaviorPlanner::set_map_interface(BehaviorPlannerMapItf* itf) {
  map_itf_ = itf;
}

// 设置HMI接口
void BehaviorPlanner::set_hmi_behavior(const LateralBehavior& hmi_behavior) {
  // ~ hmi interface is enabled when >= L2
  if (autonomous_level_ == 2) {
    behavior_.lat_behavior = hmi_behavior;
    hmi_behavior_ = hmi_behavior;
    lock_to_hmi_ = true;
  } else if (autonomous_level_ == 3) {
    hmi_behavior_ = hmi_behavior;
    lock_to_hmi_ = true;
  }
}

// 设置自动驾驶等级
void BehaviorPlanner::set_autonomous_level(int level) {
  autonomous_level_ = level;
}

// 设置激进等级
void BehaviorPlanner::set_aggressive_level(int level) {
  aggressive_level_ = level;
}

// 设置使用者期望速度
void BehaviorPlanner::set_user_desired_velocity(const decimal_t desired_vel) {
  if (autonomous_level_ >= 2) {
    user_desired_velocity_ = std::max(desired_vel, 0.0);
  }
}

// 设置仿真状态
void BehaviorPlanner::set_use_sim_state(bool use_sim_state) {
  use_sim_state_ = use_sim_state;
}

// 设置仿真分辨率
void BehaviorPlanner::set_sim_resolution(const decimal_t sim_resolution) {
  sim_resolution_ = sim_resolution;
}

// 设置仿真时域
void BehaviorPlanner::set_sim_horizon(const decimal_t sim_horizon) {
  sim_horizon_ = sim_horizon;
}

// 使用者期望速度
decimal_t BehaviorPlanner::user_desired_velocity() const {
  return user_desired_velocity_;
}

// 参考期望速度
decimal_t BehaviorPlanner::reference_desired_velocity() const {
  return reference_desired_velocity_;
}

// 行为
BehaviorPlanner::Behavior BehaviorPlanner::behavior() const {
  return behavior_;
}

// 前向轨迹
vec_E<vec_E<common::Vehicle>> BehaviorPlanner::forward_trajs() const {
  return forward_trajs_;
}

// 前向行为
std::vector<BehaviorPlanner::LateralBehavior>
BehaviorPlanner::forward_behaviors() const {
  return forward_behaviors_;
}

// 自动驾驶等级
int BehaviorPlanner::autonomous_level() const { return autonomous_level_; }

}  // namespace planning
