#include "vehicle_model/controllers/idm_velocity_controller.h"

#include "vehicle_model/idm_model.h"

namespace control {
ErrorType IntelligentVelocityControl::CalculateDesiredVelocity(
    const simulator::IntelligentDriverModel::Param& param, const decimal_t s,
    const decimal_t s_front, const decimal_t v, const decimal_t v_front,
    const decimal_t dt, decimal_t* velocity_at_dt) {
  // 使用IDM（智能驾驶模型）来计算期望的速度
  using simulator::IntelligentDriverModel;
  // 创建IDM模型实例
  IntelligentDriverModel model(param);
  // 定义并设置IDM模型的状态
  IntelligentDriverModel::State state;
  state.s = s; // 自车的当前距离
  state.v =
      std::max(0.0, v);    // 当前车速，确保车速不为负数
  state.s_front = s_front; // 前车的距离
  state.v_front = v_front; // 前车的车速
  model.set_state(state);  // 设置IDM模型的状态
  model.Step(dt);          // 执行IDM模型的时间步进，计算下一时刻的状态
  // printf("[DEBUG]s %lf, s_front %lf, v %lf, v_front %lf dt %lf.\n", s,
  // s_front,
  //        v, v_front, dt);
  // printf("[DEBUG]desired v %lf, braking acc %lf.\n", param.kDesiredVelocity,
  //        param.kComfortableBrakingDeceleration);
  // 获取模型计算后的期望状态
  auto desired_state = model.state();
  // if (std::isnan(desired_state.v)) {
  //   printf("[DEBUGNAN]next s %lf, s_front %lf, v %lf, v_front %lf.\n",
  //          desired_state.s, desired_state.s_front, v, desired_state.v_front);
  //   assert(!std::isnan(desired_state.v));
  // }
  // 更新期望的车速，确保不为负值
  *velocity_at_dt = std::max(0.0, desired_state.v);
  // if (std::isinf(*velocity_at_dt)) {
  //   printf("[DEBUG]idm desired v %lf a %lf, b %lf, T %lf, gap %lf.\n",
  //          param.kDesiredVelocity, param.kAcceleration,
  //          param.kComfortableBrakingDeceleration, param.kDesiredHeadwayTime,
  //          param.kMinimumSpacing);
  //   printf("[DEBUG]s %lf, s_front %lf, v %lf, v_front %lf, dt %lf out%lf.\n",
  //   s,
  //          s_front, v, v_front, dt, *velocity_at_dt);
  //   assert(false);
  // }
  return kSuccess;
}

}  // namespace control