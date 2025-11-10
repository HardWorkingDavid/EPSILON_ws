// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vehicle_msgs:msg/Circle.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__CIRCLE__BUILDER_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__CIRCLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vehicle_msgs/msg/detail/circle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vehicle_msgs
{

namespace msg
{

namespace builder
{

class Init_Circle_radius
{
public:
  explicit Init_Circle_radius(::vehicle_msgs::msg::Circle & msg)
  : msg_(msg)
  {}
  ::vehicle_msgs::msg::Circle radius(::vehicle_msgs::msg::Circle::_radius_type arg)
  {
    msg_.radius = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vehicle_msgs::msg::Circle msg_;
};

class Init_Circle_center
{
public:
  Init_Circle_center()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Circle_radius center(::vehicle_msgs::msg::Circle::_center_type arg)
  {
    msg_.center = std::move(arg);
    return Init_Circle_radius(msg_);
  }

private:
  ::vehicle_msgs::msg::Circle msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vehicle_msgs::msg::Circle>()
{
  return vehicle_msgs::msg::builder::Init_Circle_center();
}

}  // namespace vehicle_msgs

#endif  // VEHICLE_MSGS__MSG__DETAIL__CIRCLE__BUILDER_HPP_
