// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vehicle_msgs:msg/FreeState.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__FREE_STATE__BUILDER_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__FREE_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vehicle_msgs/msg/detail/free_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vehicle_msgs
{

namespace msg
{

namespace builder
{

class Init_FreeState_angle
{
public:
  explicit Init_FreeState_angle(::vehicle_msgs::msg::FreeState & msg)
  : msg_(msg)
  {}
  ::vehicle_msgs::msg::FreeState angle(::vehicle_msgs::msg::FreeState::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vehicle_msgs::msg::FreeState msg_;
};

class Init_FreeState_acc
{
public:
  explicit Init_FreeState_acc(::vehicle_msgs::msg::FreeState & msg)
  : msg_(msg)
  {}
  Init_FreeState_angle acc(::vehicle_msgs::msg::FreeState::_acc_type arg)
  {
    msg_.acc = std::move(arg);
    return Init_FreeState_angle(msg_);
  }

private:
  ::vehicle_msgs::msg::FreeState msg_;
};

class Init_FreeState_vel
{
public:
  explicit Init_FreeState_vel(::vehicle_msgs::msg::FreeState & msg)
  : msg_(msg)
  {}
  Init_FreeState_acc vel(::vehicle_msgs::msg::FreeState::_vel_type arg)
  {
    msg_.vel = std::move(arg);
    return Init_FreeState_acc(msg_);
  }

private:
  ::vehicle_msgs::msg::FreeState msg_;
};

class Init_FreeState_pos
{
public:
  explicit Init_FreeState_pos(::vehicle_msgs::msg::FreeState & msg)
  : msg_(msg)
  {}
  Init_FreeState_vel pos(::vehicle_msgs::msg::FreeState::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return Init_FreeState_vel(msg_);
  }

private:
  ::vehicle_msgs::msg::FreeState msg_;
};

class Init_FreeState_header
{
public:
  Init_FreeState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FreeState_pos header(::vehicle_msgs::msg::FreeState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_FreeState_pos(msg_);
  }

private:
  ::vehicle_msgs::msg::FreeState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vehicle_msgs::msg::FreeState>()
{
  return vehicle_msgs::msg::builder::Init_FreeState_header();
}

}  // namespace vehicle_msgs

#endif  // VEHICLE_MSGS__MSG__DETAIL__FREE_STATE__BUILDER_HPP_
