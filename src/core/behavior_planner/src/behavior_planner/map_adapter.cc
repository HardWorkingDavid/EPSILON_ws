#include "behavior_planner/map_adapter.h"

namespace planning {
// 判断接口是否有效
bool BehaviorPlannerMapAdapter::IsValid() { return is_valid_; }
// 获取自车的状态
ErrorType BehaviorPlannerMapAdapter::GetEgoState(State *state) {
  if (!is_valid_) return kWrongStatus;
  *state = map_->ego_vehicle().state();
  return kSuccess;
}
// 获取自车ID
ErrorType BehaviorPlannerMapAdapter::GetEgoId(int *id) {
  if (!is_valid_) return kWrongStatus; // 如果地图无效，返回错误
  *id = map_->ego_id();                // 获取自车的ID
  return kSuccess;
}
// 获取自车对象
ErrorType BehaviorPlannerMapAdapter::GetEgoVehicle(common::Vehicle *vehicle) {
  if (!is_valid_) return kWrongStatus; // 如果地图无效，返回错误
  *vehicle = map_->ego_vehicle();      // 获取自车对象
  return kSuccess;
}
// 根据导航路径获取自车所在的车道ID
ErrorType BehaviorPlannerMapAdapter::GetEgoLaneIdByPosition(
    const std::vector<int> &navi_path, int *lane_id) {
  if (!is_valid_) {
    printf("[GetEgoLaneIdByPosition]Interface not valid.\n");
    return kWrongStatus; // 如果地图无效，返回错误
  }

  int ego_lane_id = kInvalidLaneId; // 初始化车道ID为无效ID
  decimal_t distance_to_lane;
  decimal_t arc_len;
  // 获取自车的三维状态（位置和朝向）
  Vec3f state_3dof(map_->ego_vehicle().state().vec_position(0),
                   map_->ego_vehicle().state().vec_position(1),
                   map_->ego_vehicle().state().angle);
  std::set<std::tuple<decimal_t, decimal_t, int>> dist_set;
  // 获取与自车最近的车道ID
  if (map_->GetNearestLaneIdUsingState(state_3dof, navi_path, &ego_lane_id,
                                       &distance_to_lane,
                                       &arc_len) != kSuccess) {
    printf("[GetEgoLaneIdByPosition]Cannot get nearest lane.\n");
    return kWrongStatus;
  }

  *lane_id = ego_lane_id; // 设置车道ID
  return kSuccess;
}
// 根据自车状态和导航路径获取最近的车道ID
ErrorType BehaviorPlannerMapAdapter::GetNearestLaneIdUsingState(
    const Vec3f &state, const std::vector<int> &navi_path, int *id,
    decimal_t *distance, decimal_t *arc_len) {
  if (!is_valid_) {
    printf("[GetNearestLaneIdUsingState]Interface not valid.\n");
    return kWrongStatus; // 如果地图无效，返回错误
  }
  std::set<std::tuple<decimal_t, decimal_t, int>> dist_set;
  if (map_->GetNearestLaneIdUsingState(state, navi_path, id, distance,
                                       arc_len) != kSuccess) {
    printf("[GetNearestLaneIdUsingState]Cannot get nearest lane.\n");
    return kWrongStatus; // 如果获取车道失败，返回错误
  }
  return kSuccess;
}
// 检查车道在拓扑结构上是否可达
ErrorType BehaviorPlannerMapAdapter::IsTopologicallyReachable(
    const int lane_id, const std::vector<int> &path, int *num_lane_changes,
    bool *res) {
  if (!is_valid_) {
    printf("[GetNearestLaneIdUsingState]Interface not valid.\n");
    return kWrongStatus;
  }
  // 检查车道在拓扑上是否可达
  if (map_->IsTopologicallyReachable(lane_id, path, num_lane_changes, res) !=
      kSuccess) {
    printf("[GetNearestLaneIdUsingState]Cannot get nearest lane.\n");
    return kWrongStatus;
  }
  return kSuccess;
}
// 获取右侧邻近车道ID
ErrorType BehaviorPlannerMapAdapter::GetRightLaneId(const int lane_id,
                                                    int *r_lane_id) {
  if (!is_valid_) return kWrongStatus;
  auto semantic_lane_set = map_->semantic_lane_set();       // 获取语义车道集合
  auto it = semantic_lane_set.semantic_lanes.find(lane_id); // 查找指定车道ID
  if (it == semantic_lane_set.semantic_lanes.end()) {
    return kWrongStatus; // 如果没有找到车道ID，返回错误
  } else {
    if (it->second.r_change_avbl) { // 如果右侧车道可变更
      *r_lane_id = it->second.r_lane_id; // 获取右侧车道ID
    } else {
      return kWrongStatus;
    }
  }
  return kSuccess;
}
// 获取左侧邻近车道ID
ErrorType BehaviorPlannerMapAdapter::GetLeftLaneId(const int lane_id,
                                                   int *l_lane_id) {
  if (!is_valid_) return kWrongStatus;
  auto semantic_lane_set = map_->semantic_lane_set();
  auto it = semantic_lane_set.semantic_lanes.find(lane_id);
  if (it == semantic_lane_set.semantic_lanes.end()) {
    return kWrongStatus;
  } else {
    if (it->second.l_change_avbl) { // 如果左侧车道可变更
      *l_lane_id = it->second.l_lane_id; // 获取左侧车道ID
    } else {
      return kWrongStatus;
    }
  }
  return kSuccess;
}
// 根据车道ID获取车道对象
ErrorType BehaviorPlannerMapAdapter::GetLaneByLaneId(const int lane_id,
                                                     Lane *lane) {
  if (!is_valid_) return kWrongStatus;
  auto semantic_lane_set = map_->semantic_lane_set();
  auto it = semantic_lane_set.semantic_lanes.find(lane_id);
  if (it == semantic_lane_set.semantic_lanes.end()) {
    return kWrongStatus;
  } else {
    *lane = it->second.lane; // 获取车道对象
    if (!lane->IsValid()) {
      return kWrongStatus;   // 如果车道无效，返回错误
    }
  }
  return kSuccess;
}
// 获取子车道ID集合
ErrorType BehaviorPlannerMapAdapter::GetChildLaneIds(
    const int lane_id, std::vector<int> *child_ids) {
  if (!is_valid_) return kWrongStatus;
  auto semantic_lane_set = map_->semantic_lane_set();      // 获取语义车道集合
  auto it = semantic_lane_set.semantic_lanes.find(lane_id);// 查找指定车道ID
  if (it == semantic_lane_set.semantic_lanes.end()) {
    return kWrongStatus; // 如果没有找到车道ID，返回错误
  } else {
    // ~ note this is an assign 
    // 将子车道ID添加到child_ids中
    child_ids->assign(it->second.child_id.begin(), it->second.child_id.end());
  }
  return kSuccess;
}

// 获取父车道ID集合
ErrorType BehaviorPlannerMapAdapter::GetFatherLaneIds(
    const int lane_id, std::vector<int> *father_ids) {
  if (!is_valid_) return kWrongStatus;
  auto semantic_lane_set = map_->semantic_lane_set();       // 获取语义车道集合
  auto it = semantic_lane_set.semantic_lanes.find(lane_id); // 查找指定车道ID
  if (it == semantic_lane_set.semantic_lanes.end()) {
    return kWrongStatus; // 如果没有找到车道ID，返回错误
  } else {
    // 将父车道ID添加到father_ids中
    father_ids->assign(it->second.father_id.begin(),
                       it->second.father_id.end());
  }
  return kSuccess;
}

// 根据自车状态和车道ID获取局部车道采样点
ErrorType BehaviorPlannerMapAdapter::GetLocalLaneSamplesByState(
    const State &state, const int lane_id, const std::vector<int> &navi_path,
    const decimal_t max_reflane_dist, const decimal_t max_backward_dist,
    vec_Vecf<2> *samples) {
  if (!is_valid_) return kWrongStatus; // 如果地图无效，返回错误
  if (map_->GetLocalLaneSamplesByState(state, lane_id, navi_path,
                                       max_reflane_dist, max_backward_dist,
                                       samples) != kSuccess) {
    return kWrongStatus;
  }
  return kSuccess;
}

// 根据行为类型获取参考车道
ErrorType BehaviorPlannerMapAdapter::GetRefLaneForStateByBehavior(
    const State &state, const std::vector<int> &navi_path,
    const LateralBehavior &behavior, const decimal_t &max_forward_len,
    const decimal_t &max_back_len, const bool is_high_quality, Lane *lane) {
  if (!is_valid_) return kWrongStatus; // 如果地图无效，返回错误
  if (map_->GetRefLaneForStateByBehavior(state, navi_path, behavior,
                                         max_forward_len, max_back_len,
                                         is_high_quality, lane) != kSuccess) {
    return kWrongStatus;
  }
  if (!lane->IsValid()) {
    return kWrongStatus;
  }
  return kSuccess;
}

// 获取车道上领先的车辆
ErrorType BehaviorPlannerMapAdapter::GetLeadingVehicleOnLane(
    const common::Lane &ref_lane, const common::State &ref_state,
    const common::VehicleSet &vehicle_set, const decimal_t &lat_range,
    common::Vehicle *leading_vehicle, decimal_t *distance_residual_ratio) {
  if (!is_valid_) return kWrongStatus;
  if (map_->GetLeadingVehicleOnLane(ref_lane, ref_state, vehicle_set, lat_range,
                                    leading_vehicle,
                                    distance_residual_ratio) != kSuccess) {
    return kWrongStatus;
  }
  return kSuccess;
}

// 获取关键车辆集合
ErrorType BehaviorPlannerMapAdapter::GetKeyVehicles(
    common::VehicleSet *key_vehicle_set) {
  if (!is_valid_) return kWrongStatus;
  // TODO: (@denny.ding) add vehicle selection strategy here
  *key_vehicle_set = map_->surrounding_vehicles(); // 获取周围车辆
  return kSuccess;
}

// 获取关键语义车辆集合
ErrorType BehaviorPlannerMapAdapter::GetKeySemanticVehicles(
    common::SemanticVehicleSet *key_vehicle_set) {
  if (!is_valid_) return kWrongStatus;
  // TODO: (@denny.ding) add vehicle selection strategy here
  *key_vehicle_set = map_->semantic_key_vehicles(); // 获取关键语义车辆
  return kSuccess;
}

// 获取整个车道网络
ErrorType BehaviorPlannerMapAdapter::GetWholeLaneNet(
    common::LaneNet *lane_net) {
  if (!is_valid_) return kWrongStatus;
  *lane_net = map_->whole_lane_net();  // 获取整个车道网络
  return kSuccess;
}

// 检查两个车辆是否发生碰撞
ErrorType BehaviorPlannerMapAdapter::CheckCollisionUsingState(
    const common::VehicleParam &param_a, const common::State &state_a,
    const common::VehicleParam &param_b, const common::State &state_b,
    bool *res) {
  if (!is_valid_) return kWrongStatus;
  // 如果碰撞检测失败，返回错误
  if (map_->CheckCollisionUsingState(param_a, state_a, param_b, state_b, res) !=
      kSuccess) {
    return kWrongStatus;
  }
  return kSuccess;
}

// 检查自车与其他车辆是否发生碰撞
ErrorType BehaviorPlannerMapAdapter::CheckIfCollision(
    const common::VehicleParam &vehicle_param, const State &state, bool *res) {
  if (!is_valid_) return kWrongStatus;
  map_->CheckCollisionUsingStateAndVehicleParam(vehicle_param, state, res);
  return kSuccess;
}
// 获取车道的速度限制
ErrorType BehaviorPlannerMapAdapter::GetSpeedLimit(const State &state,
                                                   const Lane &lane,
                                                   decimal_t *speed_limit) {
  if (!is_valid_) return kWrongStatus;
  if (map_->GetSpeedLimit(state, lane, speed_limit) != kSuccess) {
    return kWrongStatus;
  }
  return kSuccess;
}
// 获取车辆的预测行为
ErrorType BehaviorPlannerMapAdapter::GetPredictedBehavior(
    const int vehicle_id, common::LateralBehavior *lat_behavior) {
  if (!is_valid_) return kWrongStatus;
  if (vehicle_id == kInvalidAgentId) return kWrongStatus;
  auto semantic_vehicle_set = map_->semantic_surrounding_vehicles();      // 获取周围车辆
  *lat_behavior =
      semantic_vehicle_set.semantic_vehicles.at(vehicle_id).lat_behavior; // 获取预测行为
  return kSuccess;
}
// 设置语义地图管理器
void BehaviorPlannerMapAdapter::set_map(
    std::shared_ptr<IntegratedMap> map_ptr) {
  map_ = map_ptr;   // 设置地图
  is_valid_ = true; // 标记地图有效
}

}  // namespace planning
