#ifndef _CORE_BEHAVIOR_PLANNER_INC_BEHAVIOR_PLANNER_BEHAVIOR_PLANNER_H_
#define _CORE_BEHAVIOR_PLANNER_INC_BEHAVIOR_PLANNER_BEHAVIOR_PLANNER_H_

#include <memory>
#include <string>

#include "behavior_planner/map_interface.h"
#include "common/basics/basics.h"
#include "common/interface/planner.h"
#include "common/lane/lane.h"
#include "common/lane/lane_generator.h"
#include "common/state/state.h"
#include "route_planner/route_planner.h"

#include "forward_simulator/multimodal_forward.h"
#include "forward_simulator/onlane_forward_simulation.h"
namespace planning {

// 行为规划器类
class BehaviorPlanner : public Planner {
 public:
  // 使用common命名空间下的State,Lane,SemanticBehavior和LateralBehavior
  using State = common::State;
  using Lane = common::Lane;
  using Behavior = common::SemanticBehavior;
  using LateralBehavior = common::LateralBehavior;
  
  std::string Name() override;
  // 初始化方法，加载配置
  ErrorType Init(const std::string config) override;
  // 执行一次行为规划
  ErrorType RunOnce() override;
  // 设置地图接口
  void set_map_interface(BehaviorPlannerMapItf* itf);
  // 设置期望速度
  void set_user_desired_velocity(const decimal_t desired_vel);

  /**
   * @brief 设置L2级别的人工指令车道变换行为
   **/
  void set_hmi_behavior(const LateralBehavior& hmi_behavior);

  // 设置自动驾驶等级
  void set_autonomous_level(int level);
  
  // 设置仿真分辨率
  void set_sim_resolution(const decimal_t sim_resolution);
  
  // 设置仿真时间范围
  void set_sim_horizon(const decimal_t sim_horizon);
  
  // 设置是否使用仿真状态
  void set_use_sim_state(bool use_sim_state);
  
  // 设置激进驾驶等级
  void set_aggressive_level(int level);
  
  // 执行路线规划
  ErrorType RunRoutePlanner(const int nearest_lane_id);
  
  // 执行MPDM（多策略决策模型）
  ErrorType RunMpdm();
  
  // 获取当前行为
  Behavior behavior() const;
  
  // 获取用户期望的速度
  decimal_t user_desired_velocity() const;
  
  // 获取参考的期望速度
  decimal_t reference_desired_velocity() const;
  // 获取自动驾驶等级
  int autonomous_level() const;
  // 获取前向轨迹
  vec_E<vec_E<common::Vehicle>> forward_trajs() const;
  // 获取前向行为
  std::vector<LateralBehavior> forward_behaviors() const;

 protected:
  // 构造参考车道
  ErrorType ConstructReferenceLane(const LateralBehavior& lat_behavior,
                                   Lane* lane);
  // 从样本中构造车道
  ErrorType ConstructLaneFromSamples(const vec_E<Vecf<2>>& samples, Lane* lane);
  // 多种行为判断，根据先前的期望速度更新行为
  ErrorType MultiBehaviorJudge(const decimal_t previous_desired_vel,
                               LateralBehavior* mpdm_behavior,
                               decimal_t* actual_desired_velocity);
  // 获取潜在车道的ID
  ErrorType GetPotentialLaneIds(const int source_lane_id,
                                const LateralBehavior& beh,
                                std::vector<int>* candidate_lane_ids);
  // 更新自车所在车道ID
  ErrorType UpdateEgoLaneId(const int new_ego_lane_id);
  // 根据车道ID判断行为
  ErrorType JudgeBehaviorByLaneId(const int ego_lane_id_by_pos,
                                  LateralBehavior* behavior_by_lane_id);
  // 更新自车行为
  ErrorType UpdateEgoBehavior(const LateralBehavior& behavior_by_lane_id);
  // 多智能体仿真前向推演
  ErrorType MultiAgentSimForward(
      const int ego_id, const common::SemanticVehicleSet& semantic_vehicle_set,
      const decimal_t& lat_offset,  // 新增：横向偏移量
      vec_E<common::Vehicle>* traj,
      std::unordered_map<int, vec_E<common::Vehicle>>* surround_trajs);
  // 开环仿真前向推演
  ErrorType OpenloopSimForward(
      const common::SemanticVehicle& ego_semantic_vehicle,
      const common::SemanticVehicleSet& agent_vehicles,
      const decimal_t& lat_offset, // 新增：横向偏移量
      vec_E<common::Vehicle>* traj,
      std::unordered_map<int, vec_E<common::Vehicle>>* surround_trajs);
  // 仿真自车行为
  ErrorType SimulateEgoBehavior(
      const common::Vehicle& ego_vehicle, const LateralBehavior& ego_behavior,
      const common::SemanticVehicleSet& semantic_vehicle_set,
      vec_E<common::Vehicle>* traj,
      std::unordered_map<int, vec_E<common::Vehicle>>* surround_trajs);
  // 评估多策略轨迹
  ErrorType EvaluateMultiPolicyTrajs(
      const std::vector<LateralBehavior>& valid_behaviors,
      const vec_E<vec_E<common::Vehicle>>& valid_forward_trajs,
      const vec_E<std::unordered_map<int, vec_E<common::Vehicle>>>&
          valid_surround_trajs,
      LateralBehavior* winner_behavior,
      vec_E<common::Vehicle>* winner_forward_traj, decimal_t* winner_score,
      decimal_t* desired_vel);
  // 评估单一策略轨迹
  ErrorType EvaluateSinglePolicyTraj(
      const LateralBehavior& behaivor,
      const vec_E<common::Vehicle>& forward_traj,
      const std::unordered_map<int, vec_E<common::Vehicle>>& surround_traj,
      decimal_t* score, decimal_t* desired_vel);
  // 评估安全成本
  ErrorType EvaluateSafetyCost(const vec_E<common::Vehicle>& traj_a,
                               const vec_E<common::Vehicle>& traj_b,
                               decimal_t* cost);
  // 获取轨迹的期望速度
  ErrorType GetDesiredVelocityOfTrajectory(
      const vec_E<common::Vehicle> vehicle_vec, decimal_t* vel);
  
  BehaviorPlannerMapItf* map_itf_{nullptr}; // 地图接口
  Behavior behavior_;                       // 当前行为

  planning::RoutePlanner* p_route_planner_{nullptr}; // 导航规划器

  decimal_t user_desired_velocity_{5.0};             // 用户期望速度
  decimal_t reference_desired_velocity_{5.0};        // 参考期望速度
  int autonomous_level_{3};                          // 自动驾驶等级

  decimal_t sim_resolution_{0.4};                      // 仿真分辨率
  decimal_t sim_horizon_{4.0};                         // 仿真时间范围
  int aggressive_level_{3};                            // 激进驾驶等级
  planning::OnLaneForwardSimulation::Param sim_param_; // 仿真参数

  bool use_sim_state_ = true;                          // 是否使用仿真状态
  bool lock_to_hmi_ = false;                           // 是否锁定到HMI
  LateralBehavior hmi_behavior_ = LateralBehavior::kLaneKeeping; // 人机界面行为（默认为车道保持）

  // 记录自车车道ID
  int ego_lane_id_{kInvalidLaneId}; // 自车车道ID
  int ego_id_;                      // 自车ID
  std::vector<int> potential_lcl_lane_ids_;   // 潜在的左车道变道ID
  std::vector<int> potential_lcr_lane_ids_;   // 潜在的右车道变道ID
  std::vector<int> potential_lk_lane_ids_;    // 潜在的车道保持车道ID
  // 在潜在车道ID中添加Nudge相关
  std::vector<int> potential_nudge_left_lane_ids_;  // 往左微调
  std::vector<int> potential_nudge_right_lane_ids_; // 往右微调

  // debug 调试
  vec_E<vec_E<common::Vehicle>> forward_trajs_;   // 每种行为对应的前向轨迹(用离散状态表示轨迹)
  std::vector<LateralBehavior> forward_behaviors_;// 所有可能的行为
  vec_E<std::unordered_map<int, vec_E<common::Vehicle>>> surround_trajs_; // 每种行为对应的周围所有车辆的预测轨迹
};

}  // namespace planning

#endif