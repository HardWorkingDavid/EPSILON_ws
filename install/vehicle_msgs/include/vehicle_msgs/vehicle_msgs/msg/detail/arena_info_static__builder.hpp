// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vehicle_msgs:msg/ArenaInfoStatic.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__ARENA_INFO_STATIC__BUILDER_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__ARENA_INFO_STATIC__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vehicle_msgs/msg/detail/arena_info_static__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vehicle_msgs
{

namespace msg
{

namespace builder
{

class Init_ArenaInfoStatic_obstacle_set
{
public:
  explicit Init_ArenaInfoStatic_obstacle_set(::vehicle_msgs::msg::ArenaInfoStatic & msg)
  : msg_(msg)
  {}
  ::vehicle_msgs::msg::ArenaInfoStatic obstacle_set(::vehicle_msgs::msg::ArenaInfoStatic::_obstacle_set_type arg)
  {
    msg_.obstacle_set = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vehicle_msgs::msg::ArenaInfoStatic msg_;
};

class Init_ArenaInfoStatic_lane_net
{
public:
  explicit Init_ArenaInfoStatic_lane_net(::vehicle_msgs::msg::ArenaInfoStatic & msg)
  : msg_(msg)
  {}
  Init_ArenaInfoStatic_obstacle_set lane_net(::vehicle_msgs::msg::ArenaInfoStatic::_lane_net_type arg)
  {
    msg_.lane_net = std::move(arg);
    return Init_ArenaInfoStatic_obstacle_set(msg_);
  }

private:
  ::vehicle_msgs::msg::ArenaInfoStatic msg_;
};

class Init_ArenaInfoStatic_header
{
public:
  Init_ArenaInfoStatic_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArenaInfoStatic_lane_net header(::vehicle_msgs::msg::ArenaInfoStatic::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ArenaInfoStatic_lane_net(msg_);
  }

private:
  ::vehicle_msgs::msg::ArenaInfoStatic msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vehicle_msgs::msg::ArenaInfoStatic>()
{
  return vehicle_msgs::msg::builder::Init_ArenaInfoStatic_header();
}

}  // namespace vehicle_msgs

#endif  // VEHICLE_MSGS__MSG__DETAIL__ARENA_INFO_STATIC__BUILDER_HPP_
