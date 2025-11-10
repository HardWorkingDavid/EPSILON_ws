// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vehicle_msgs:msg/ControlSignal.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__CONTROL_SIGNAL__BUILDER_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__CONTROL_SIGNAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vehicle_msgs/msg/detail/control_signal__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vehicle_msgs
{

namespace msg
{

namespace builder
{

class Init_ControlSignal_state
{
public:
  explicit Init_ControlSignal_state(::vehicle_msgs::msg::ControlSignal & msg)
  : msg_(msg)
  {}
  ::vehicle_msgs::msg::ControlSignal state(::vehicle_msgs::msg::ControlSignal::_state_type arg)
  {
    msg_.state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vehicle_msgs::msg::ControlSignal msg_;
};

class Init_ControlSignal_is_openloop
{
public:
  explicit Init_ControlSignal_is_openloop(::vehicle_msgs::msg::ControlSignal & msg)
  : msg_(msg)
  {}
  Init_ControlSignal_state is_openloop(::vehicle_msgs::msg::ControlSignal::_is_openloop_type arg)
  {
    msg_.is_openloop = std::move(arg);
    return Init_ControlSignal_state(msg_);
  }

private:
  ::vehicle_msgs::msg::ControlSignal msg_;
};

class Init_ControlSignal_steer_rate
{
public:
  explicit Init_ControlSignal_steer_rate(::vehicle_msgs::msg::ControlSignal & msg)
  : msg_(msg)
  {}
  Init_ControlSignal_is_openloop steer_rate(::vehicle_msgs::msg::ControlSignal::_steer_rate_type arg)
  {
    msg_.steer_rate = std::move(arg);
    return Init_ControlSignal_is_openloop(msg_);
  }

private:
  ::vehicle_msgs::msg::ControlSignal msg_;
};

class Init_ControlSignal_acc
{
public:
  explicit Init_ControlSignal_acc(::vehicle_msgs::msg::ControlSignal & msg)
  : msg_(msg)
  {}
  Init_ControlSignal_steer_rate acc(::vehicle_msgs::msg::ControlSignal::_acc_type arg)
  {
    msg_.acc = std::move(arg);
    return Init_ControlSignal_steer_rate(msg_);
  }

private:
  ::vehicle_msgs::msg::ControlSignal msg_;
};

class Init_ControlSignal_header
{
public:
  Init_ControlSignal_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ControlSignal_acc header(::vehicle_msgs::msg::ControlSignal::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ControlSignal_acc(msg_);
  }

private:
  ::vehicle_msgs::msg::ControlSignal msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vehicle_msgs::msg::ControlSignal>()
{
  return vehicle_msgs::msg::builder::Init_ControlSignal_header();
}

}  // namespace vehicle_msgs

#endif  // VEHICLE_MSGS__MSG__DETAIL__CONTROL_SIGNAL__BUILDER_HPP_
