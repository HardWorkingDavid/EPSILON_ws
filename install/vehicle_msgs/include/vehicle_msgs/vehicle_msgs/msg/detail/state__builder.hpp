// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vehicle_msgs:msg/State.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__STATE__BUILDER_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vehicle_msgs/msg/detail/state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vehicle_msgs
{

namespace msg
{

namespace builder
{

class Init_State_steer
{
public:
  explicit Init_State_steer(::vehicle_msgs::msg::State & msg)
  : msg_(msg)
  {}
  ::vehicle_msgs::msg::State steer(::vehicle_msgs::msg::State::_steer_type arg)
  {
    msg_.steer = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vehicle_msgs::msg::State msg_;
};

class Init_State_acceleration
{
public:
  explicit Init_State_acceleration(::vehicle_msgs::msg::State & msg)
  : msg_(msg)
  {}
  Init_State_steer acceleration(::vehicle_msgs::msg::State::_acceleration_type arg)
  {
    msg_.acceleration = std::move(arg);
    return Init_State_steer(msg_);
  }

private:
  ::vehicle_msgs::msg::State msg_;
};

class Init_State_velocity
{
public:
  explicit Init_State_velocity(::vehicle_msgs::msg::State & msg)
  : msg_(msg)
  {}
  Init_State_acceleration velocity(::vehicle_msgs::msg::State::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_State_acceleration(msg_);
  }

private:
  ::vehicle_msgs::msg::State msg_;
};

class Init_State_curvature
{
public:
  explicit Init_State_curvature(::vehicle_msgs::msg::State & msg)
  : msg_(msg)
  {}
  Init_State_velocity curvature(::vehicle_msgs::msg::State::_curvature_type arg)
  {
    msg_.curvature = std::move(arg);
    return Init_State_velocity(msg_);
  }

private:
  ::vehicle_msgs::msg::State msg_;
};

class Init_State_angle
{
public:
  explicit Init_State_angle(::vehicle_msgs::msg::State & msg)
  : msg_(msg)
  {}
  Init_State_curvature angle(::vehicle_msgs::msg::State::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return Init_State_curvature(msg_);
  }

private:
  ::vehicle_msgs::msg::State msg_;
};

class Init_State_vec_position
{
public:
  explicit Init_State_vec_position(::vehicle_msgs::msg::State & msg)
  : msg_(msg)
  {}
  Init_State_angle vec_position(::vehicle_msgs::msg::State::_vec_position_type arg)
  {
    msg_.vec_position = std::move(arg);
    return Init_State_angle(msg_);
  }

private:
  ::vehicle_msgs::msg::State msg_;
};

class Init_State_header
{
public:
  Init_State_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_State_vec_position header(::vehicle_msgs::msg::State::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_State_vec_position(msg_);
  }

private:
  ::vehicle_msgs::msg::State msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vehicle_msgs::msg::State>()
{
  return vehicle_msgs::msg::builder::Init_State_header();
}

}  // namespace vehicle_msgs

#endif  // VEHICLE_MSGS__MSG__DETAIL__STATE__BUILDER_HPP_
