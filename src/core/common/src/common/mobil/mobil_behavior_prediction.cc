#include "common/mobil/mobil_behavior_prediction.h"

namespace common {

ErrorType MobilBehaviorPrediction::RemapGainsToProb(
    const bool is_lcl_safe, const decimal_t mobil_gain_left,
    const bool is_lcr_safe, const decimal_t mobil_gain_right,
    const bool is_nudge_left_safe, const decimal_t nudge_gain_left,
    const bool is_nudge_right_safe, const decimal_t nudge_gain_right,
    ProbDistOfLatBehaviors *res) {
  // decimal_t lower_bound = -1.0;
  // // decimal_t upper_bound = 1.0;
  // decimal_t upper_bound = 6.0;

  // if (is_lcl_safe && is_lcr_safe) {
  //   decimal_t gain_l = normalize_with_bound(mobil_gain_left, lower_bound,
  //                                           upper_bound, 0.0, 1.0);
  //   decimal_t gain_k =
  //       normalize_with_bound(1.0, lower_bound, upper_bound, 0.0, 1.0);
  //   decimal_t gain_r = normalize_with_bound(mobil_gain_right, lower_bound,
  //                                           upper_bound, 0.0, 1.0);

  //   decimal_t p_l = gain_l / (gain_k + gain_l + gain_r);
  //   decimal_t p_k = gain_k / (gain_k + gain_l + gain_r);
  //   decimal_t p_r = gain_r / (gain_k + gain_l + gain_r);

  //   res->SetEntry(common::LateralBehavior::kLaneChangeLeft, p_l);
  //   res->SetEntry(common::LateralBehavior::kLaneChangeRight, p_r);
  //   res->SetEntry(common::LateralBehavior::kLaneKeeping, p_k);
  //   res->is_valid = true;

  // } else if (is_lcl_safe) {
  //   decimal_t gain = normalize_with_bound(mobil_gain_left, lower_bound,
  //                                         upper_bound, 0.0, 1.0);
  //   res->SetEntry(common::LateralBehavior::kLaneChangeLeft, gain);
  //   res->SetEntry(common::LateralBehavior::kLaneChangeRight, 0.0);
  //   res->SetEntry(common::LateralBehavior::kLaneKeeping, 1.0 - gain);
  //   res->is_valid = true;
  // } else if (is_lcr_safe) {
  //   decimal_t gain = normalize_with_bound(mobil_gain_right, lower_bound,
  //                                         upper_bound, 0.0, 1.0);
  //   res->SetEntry(common::LateralBehavior::kLaneChangeLeft, 0.0);
  //   res->SetEntry(common::LateralBehavior::kLaneChangeRight, gain);
  //   res->SetEntry(common::LateralBehavior::kLaneKeeping, 1.0 - gain);
  //   res->is_valid = true;
  // } else {
  //   res->SetEntry(common::LateralBehavior::kLaneChangeLeft, 0.0);
  //   res->SetEntry(common::LateralBehavior::kLaneChangeRight, 0.0);
  //   res->SetEntry(common::LateralBehavior::kLaneKeeping, 1.0);
  //   res->is_valid = true;
  // }
  // return kSuccess;
  decimal_t lower_bound = -1.0;
  decimal_t upper_bound = 6.0;

  // 初始化所有行为概率（包括Nudge）为0
  res->SetEntry(common::LateralBehavior::kLaneChangeLeft, 0.0);
  res->SetEntry(common::LateralBehavior::kLaneChangeRight, 0.0);
  res->SetEntry(common::LateralBehavior::kLaneKeeping, 0.0);
  res->SetEntry(common::LateralBehavior::kNudgeLeft, 0.0);    // 新增NudgeLeft
  res->SetEntry(common::LateralBehavior::kNudgeRight, 0.0);   // 新增NudgeRight

  // 计算Nudge行为的归一化增益（仅当安全时有效）
  decimal_t gain_nl = is_nudge_left_safe ? 
      normalize_with_bound(nudge_gain_left, lower_bound, upper_bound, 0.0, 1.0) : 0.0;
  decimal_t gain_nr = is_nudge_right_safe ? 
      normalize_with_bound(nudge_gain_right, lower_bound, upper_bound, 0.0, 1.0) : 0.0;

  if (is_lcl_safe && is_lcr_safe) {
    // 原有逻辑：左/右变道+车道保持
    decimal_t gain_l = normalize_with_bound(mobil_gain_left, lower_bound, upper_bound, 0.0, 1.0);
    decimal_t gain_k = normalize_with_bound(1.0, lower_bound, upper_bound, 0.0, 1.0);
    decimal_t gain_r = normalize_with_bound(mobil_gain_right, lower_bound, upper_bound, 0.0, 1.0);

    // 总增益 = 原有行为增益 + 安全的Nudge增益
    decimal_t total_gain = gain_l + gain_k + gain_r + gain_nl + gain_nr;
    // 防止除零（至少车道保持有效，总增益不为0）
    total_gain = total_gain < kEPS ? kEPS : total_gain;

    // 计算所有行为概率
    res->SetEntry(common::LateralBehavior::kLaneChangeLeft, gain_l / total_gain);
    res->SetEntry(common::LateralBehavior::kLaneChangeRight, gain_r / total_gain);
    res->SetEntry(common::LateralBehavior::kLaneKeeping, gain_k / total_gain);
    res->SetEntry(common::LateralBehavior::kNudgeLeft, gain_nl / total_gain);    // 新增NudgeLeft概率
    res->SetEntry(common::LateralBehavior::kNudgeRight, gain_nr / total_gain);   // 新增NudgeRight概率
    res->is_valid = true;

  } else if (is_lcl_safe) {
    // 原有逻辑：仅左变道+车道保持
    decimal_t gain_l = normalize_with_bound(mobil_gain_left, lower_bound, upper_bound, 0.0, 1.0);
    decimal_t gain_k = normalize_with_bound(1.0, lower_bound, upper_bound, 0.0, 1.0);

    // 总增益 = 原有行为增益 + 安全的Nudge增益
    decimal_t total_gain = gain_l + gain_k + gain_nl + gain_nr;
    total_gain = total_gain < kEPS ? kEPS : total_gain;

    res->SetEntry(common::LateralBehavior::kLaneChangeLeft, gain_l / total_gain);
    res->SetEntry(common::LateralBehavior::kLaneKeeping, gain_k / total_gain);
    res->SetEntry(common::LateralBehavior::kNudgeLeft, gain_nl / total_gain);    // 新增NudgeLeft概率
    res->SetEntry(common::LateralBehavior::kNudgeRight, gain_nr / total_gain);   // 新增NudgeRight概率
    res->is_valid = true;
  } else if (is_lcr_safe) {
    // 原有逻辑：仅右变道+车道保持
    decimal_t gain_r = normalize_with_bound(mobil_gain_right, lower_bound, upper_bound, 0.0, 1.0);
    decimal_t gain_k = normalize_with_bound(1.0, lower_bound, upper_bound, 0.0, 1.0);

    // 总增益 = 原有行为增益 + 安全的Nudge增益
    decimal_t total_gain = gain_r + gain_k + gain_nl + gain_nr;
    total_gain = total_gain < kEPS ? kEPS : total_gain;

    res->SetEntry(common::LateralBehavior::kLaneChangeRight, gain_r / total_gain);
    res->SetEntry(common::LateralBehavior::kLaneKeeping, gain_k / total_gain);
    res->SetEntry(common::LateralBehavior::kNudgeLeft, gain_nl / total_gain);    // 新增NudgeLeft概率
    res->SetEntry(common::LateralBehavior::kNudgeRight, gain_nr / total_gain);   // 新增NudgeRight概率
    res->is_valid = true;
  } else {
    // 原有逻辑：仅车道保持
    decimal_t gain_k = normalize_with_bound(1.0, lower_bound, upper_bound, 0.0, 1.0);

    // 总增益 = 车道保持增益 + 安全的Nudge增益
    decimal_t total_gain = gain_k + gain_nl + gain_nr;
    total_gain = total_gain < kEPS ? kEPS : total_gain;

    res->SetEntry(common::LateralBehavior::kLaneKeeping, gain_k / total_gain);
    res->SetEntry(common::LateralBehavior::kNudgeLeft, gain_nl / total_gain);    // 新增NudgeLeft概率
    res->SetEntry(common::LateralBehavior::kNudgeRight, gain_nr / total_gain);   // 新增NudgeRight概率
    res->is_valid = true;
  }
  return kSuccess;
}

ErrorType MobilBehaviorPrediction::LateralBehaviorPrediction(
    const Vehicle &vehicle, const vec_E<Lane> &lanes,
    const vec_E<common::Vehicle> &leading_vehicles,
    const vec_E<common::FrenetState> &leading_frenet_states,
    const vec_E<common::Vehicle> &following_vehicles,
    const vec_E<common::FrenetState> &follow_frenet_states,
    const common::VehicleSet &nearby_vehicles, ProbDistOfLatBehaviors *res) {
  if (lanes.size() != 3) {
    printf(
        "[MobilBehaviorPrediction]Must have three lanes (invalid also "
        "acceptable).\n");
    return kWrongStatus;
  }

  // * Notations here are following MOBIL paper
  decimal_t acc_c = 0.0;
  decimal_t acc_o = 0.0, acc_o_tilda = 0.0;
  decimal_t politeness_coeff = 0.0;

  bool is_lcl_safe = false;
  bool is_lcr_safe = false;

  decimal_t mobil_gain_left = -kInf;
  decimal_t mobil_gain_right = -kInf;

  // 新增：Nudge相关变量
  bool is_nudge_left_safe = false;
  bool is_nudge_right_safe = false;
  decimal_t nudge_gain_left = -kInf;
  decimal_t nudge_gain_right = -kInf;
  const decimal_t nudge_offset = 0.5; // Nudge横向偏移(m)

  // * When the vehicle is almost stop, we assume the behavior is lane keeping
  decimal_t desired_vel = vehicle.state().velocity;
  if (fabs(desired_vel) < kBigEPS) {
    res->SetEntry(common::LateralBehavior::kLaneChangeLeft, 0.0);
    res->SetEntry(common::LateralBehavior::kLaneChangeRight, 0.0);
    res->SetEntry(common::LateralBehavior::kLaneKeeping, 1.0);
    res->is_valid = true;
    return kSuccess;
  }

  // ~ For current lane
  common::Lane lk_lane = lanes[0];
  if (lk_lane.IsValid()) {
    common::Vehicle leading_vehicle = leading_vehicles[0];
    common::FrenetState leading_fs = leading_frenet_states[0];
    common::Vehicle following_vehicle = following_vehicles[0];
    common::FrenetState following_fs = follow_frenet_states[0];

    common::StateTransformer stf(lk_lane);
    common::FrenetState ego_frenet_state;
    stf.GetFrenetStateFromState(vehicle.state(), &ego_frenet_state);

    if (MobilLaneChangingModel::GetMobilAccChangesOnCurrentLane(
            ego_frenet_state, leading_vehicle, leading_fs, following_vehicle,
            following_fs, &acc_o, &acc_o_tilda, &acc_c) != kSuccess) {
      printf("[MobilBehaviorPrediction]lane-keep lane not valid.\n");
      return kWrongStatus;
    }
  } else {
    return kWrongStatus;
  }

  // ~ For lane change left
  common::Lane lcl_lane = lanes[1];
  if (lcl_lane.IsValid()) {
    common::Vehicle leading_vehicle = leading_vehicles[1];
    common::FrenetState leading_fs = leading_frenet_states[1];
    common::Vehicle following_vehicle = following_vehicles[1];
    common::FrenetState following_fs = follow_frenet_states[1];
    decimal_t acc_n = 0.0, acc_n_tilda = 0.0, acc_c_tilda = 0.0;

    common::StateTransformer stf(lcl_lane);
    common::FrenetState projected_frenet_state;
    stf.GetFrenetStateFromState(vehicle.state(), &projected_frenet_state);

    MobilLaneChangingModel::GetMobilAccChangesOnTargetLane(
        projected_frenet_state, leading_vehicle, leading_fs, following_vehicle,
        following_fs, &is_lcl_safe, &acc_n, &acc_n_tilda, &acc_c_tilda);
    if (is_lcl_safe) {
      decimal_t d_a_c = acc_c_tilda - acc_c;
      decimal_t d_a_n = acc_n_tilda - acc_n;
      decimal_t d_a_o = acc_o_tilda - acc_o;
      mobil_gain_left = d_a_c + politeness_coeff * (d_a_n + d_a_o);
    }
  }

  // ~ For lane change right
  common::Lane lcr_lane = lanes[2];
  if (lcr_lane.IsValid()) {
    common::Vehicle leading_vehicle = leading_vehicles[2];
    common::FrenetState leading_fs = leading_frenet_states[2];
    common::Vehicle following_vehicle = following_vehicles[2];
    common::FrenetState following_fs = follow_frenet_states[2];
    decimal_t acc_n = 0.0, acc_n_tilda = 0.0, acc_c_tilda = 0.0;

    common::StateTransformer stf(lcr_lane);
    common::FrenetState projected_frenet_state;
    stf.GetFrenetStateFromState(vehicle.state(), &projected_frenet_state);

    MobilLaneChangingModel::GetMobilAccChangesOnTargetLane(
        projected_frenet_state, leading_vehicle, leading_fs, following_vehicle,
        following_fs, &is_lcr_safe, &acc_n, &acc_n_tilda, &acc_c_tilda);
    if (is_lcr_safe) {
      decimal_t d_a_c = acc_c_tilda - acc_c;
      decimal_t d_a_n = acc_n_tilda - acc_n;
      decimal_t d_a_o = acc_o_tilda - acc_o;
      mobil_gain_right = d_a_c + politeness_coeff * (d_a_n + d_a_o);
    }
  }

  // 新增：左Nudge计算（当前车道内左偏）
  if (lk_lane.IsValid()) {  // 基于当前车道计算
    common::Vehicle leading_vehicle = leading_vehicles[0];  // 当前车道前车
    common::FrenetState leading_fs = leading_frenet_states[0];
    common::Vehicle following_vehicle = following_vehicles[0];  // 当前车道后车
    common::FrenetState following_fs = follow_frenet_states[0];

    // 计算Nudge左偏后的Frenet状态（横向偏移nudge_offset）
    common::StateTransformer stf_nudge(lk_lane);
    common::FrenetState nudge_left_fs;
    stf_nudge.GetFrenetStateFromState(vehicle.state(), &nudge_left_fs);
    nudge_left_fs.vec_dt[0] = nudge_offset;  // 左偏横向距离（修正：用vec_dt替代vec_d）
    nudge_left_fs.vec_dt[1] = 0.0;  // 横向速度设为0（可选，保持稳定）

    // 安全检查（复用变道的安全检查逻辑）
    decimal_t acc_n = 0.0, acc_n_tilda = 0.0, acc_c_tilda = 0.0;
    MobilLaneChangingModel::GetMobilAccChangesOnTargetLane(
        nudge_left_fs, leading_vehicle, leading_fs,
        following_vehicle, following_fs,
        &is_nudge_left_safe, &acc_n, &acc_n_tilda, &acc_c_tilda);

    // 计算增益（参考变道增益公式）
    if (is_nudge_left_safe) {
      decimal_t d_a_c = acc_c_tilda - acc_c;  // 自身加速度变化
      decimal_t d_a_n = acc_n_tilda - acc_n;  // 后车加速度变化
      decimal_t d_a_o = acc_o_tilda - acc_o;  // 前车加速度变化（复用当前车道值）
      nudge_gain_left = d_a_c + politeness_coeff * (d_a_n + d_a_o);
    }
  }

  // 新增：右Nudge计算（当前车道内右偏）
  if (lk_lane.IsValid()) {  // 基于当前车道计算
    common::Vehicle leading_vehicle = leading_vehicles[0];
    common::FrenetState leading_fs = leading_frenet_states[0];
    common::Vehicle following_vehicle = following_vehicles[0];
    common::FrenetState following_fs = follow_frenet_states[0];

    // 计算Nudge右偏后的Frenet状态（横向偏移-nudge_offset）
    common::StateTransformer stf_nudge(lk_lane);
    common::FrenetState nudge_right_fs;
    stf_nudge.GetFrenetStateFromState(vehicle.state(), &nudge_right_fs);
    nudge_right_fs.vec_dt[0] = -nudge_offset;  // 右偏横向距离
    nudge_right_fs.vec_dt[1] = 0.0;  // 横向速度设为0（可选，保持稳定）

    // 安全检查
    decimal_t acc_n = 0.0, acc_n_tilda = 0.0, acc_c_tilda = 0.0;
    MobilLaneChangingModel::GetMobilAccChangesOnTargetLane(
        nudge_right_fs, leading_vehicle, leading_fs,
        following_vehicle, following_fs,
        &is_nudge_right_safe, &acc_n, &acc_n_tilda, &acc_c_tilda);

    // 计算增益
    if (is_nudge_right_safe) {
      decimal_t d_a_c = acc_c_tilda - acc_c;
      decimal_t d_a_n = acc_n_tilda - acc_n;
      decimal_t d_a_o = acc_o_tilda - acc_o;
      nudge_gain_right = d_a_c + politeness_coeff * (d_a_n + d_a_o);
    }
  }
  // 添加了left_nudge、right_nudge
  RemapGainsToProb(is_lcl_safe, mobil_gain_left, is_lcr_safe, mobil_gain_right,
                   is_nudge_left_safe, nudge_gain_left,
                   is_nudge_right_safe, nudge_gain_right, res);
  printf("[Mobil]%d, Left gain: %.3lf, Right gain: %.3lf\n", vehicle.id(),
         mobil_gain_left, mobil_gain_right);
  return kSuccess;
}

}  // namespace common
