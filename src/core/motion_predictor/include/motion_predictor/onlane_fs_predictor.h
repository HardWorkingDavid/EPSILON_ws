#ifndef _CORE_MOTION_PREDICTOR_INC_ONLANE_FORWARD_SIMULATION_PREDICTOR_H_
#define _CORE_MOTION_PREDICTOR_INC_ONLANE_FORWARD_SIMULATION_PREDICTOR_H_

#include "common/basics/semantics.h"
#include "common/lane/lane.h"
#include "common/state/state.h"
#include "forward_simulator/onlane_forward_simulation.h"

namespace planning {

// 基于车道的前向模拟预测器类：用于根据车道信息和车辆当前状态，预测未来轨迹
class OnLaneFsPredictor {
 public:
  using Lane = common::Lane; 
  using State = common::State;
  using VehicleControlSignal = common::VehicleControlSignal;
  using Vehicle = common::Vehicle;

  OnLaneFsPredictor() {}
  ~OnLaneFsPredictor();

  // 静态方法：获取预测轨迹
  // 参数说明：
  //   lane：当前参考车道信息
  //   vehicle：当前车辆信息（包含状态等）
  //   t_pred：预测总时长（秒）
  //   t_step：预测时间步长（秒）
  //   pred_states：输出参数，存储预测的一系列状态（轨迹）
  // 返回值：错误类型（成功/失败）
  static ErrorType GetPredictedTrajectory(const Lane& lane,
                                          const Vehicle& vehicle,
                                          const decimal_t& t_pred,
                                          const decimal_t& t_step,
                                          vec_E<State>* pred_states) {
    pred_states->clear();
    int num_step = std::round(t_pred / t_step);   // 计算预测总步数（总时长/步长）
    State desired_state;                          // 存储每一步预测后的状态
    decimal_t desired_vel = vehicle.state().velocity; // 初始期望速度设为车辆当前速度
    planning::OnLaneForwardSimulation::Param sim_param; // 前向模拟参数
    sim_param.idm_param.kDesiredVelocity = desired_vel; // 设置IDM模型（智能驾驶模型）的期望速度
    pred_states->push_back(vehicle.state());  // 将当前车辆状态作为预测轨迹的起点
    common::Vehicle v_in = vehicle;           // 复制当前车辆信息，用于逐步更新状态
    common::StateTransformer stf = common::StateTransformer(lane); // 创建基于当前车道的状态转换器（用于坐标转换等）
    // 循环执行前向模拟，计算每一步的预测状态
    for (int i = 0; i < num_step; ++i) {
      if (lane.IsValid()) { // 若车道信息有效，使用基于车道的前向模拟
        // 调用前向模拟接口，根据当前状态和车道信息，计算下一步状态
        if (planning::OnLaneForwardSimulation::PropagateOnce(
                stf, v_in, common::Vehicle(), t_step, sim_param,
                &desired_state) != kSuccess) {
          return kWrongStatus;
        }
      } else { // 若无车道线信息, 使用常速度和常转向模型预测
        // 调用简化模型接口，基于当前速度和时间步长预测下一步状态
        if (planning::OnLaneForwardSimulation::PropagateOnce(
                desired_vel, v_in, t_step,
                planning::OnLaneForwardSimulation::Param(),
                &desired_state) != kSuccess) {
          return kWrongStatus;
        }
      }
      pred_states->push_back(desired_state); // 将当前步预测的状态加入轨迹
      v_in.set_state(desired_state);         // 更新车辆状态，用于下一步模拟
    }
    return kSuccess;
  }

 private:
};

}  // namespace planning

#endif  // _CORE_MOTION_PREDICTOR_INC_ONLANE_FORWARD_SIMULATION_PREDICTOR_H_