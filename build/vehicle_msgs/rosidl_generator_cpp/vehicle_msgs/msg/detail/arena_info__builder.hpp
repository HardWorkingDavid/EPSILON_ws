// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vehicle_msgs:msg/ArenaInfo.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__ARENA_INFO__BUILDER_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__ARENA_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vehicle_msgs/msg/detail/arena_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vehicle_msgs
{

namespace msg
{

namespace builder
{

class Init_ArenaInfo_vehicle_set
{
public:
  explicit Init_ArenaInfo_vehicle_set(::vehicle_msgs::msg::ArenaInfo & msg)
  : msg_(msg)
  {}
  ::vehicle_msgs::msg::ArenaInfo vehicle_set(::vehicle_msgs::msg::ArenaInfo::_vehicle_set_type arg)
  {
    msg_.vehicle_set = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vehicle_msgs::msg::ArenaInfo msg_;
};

class Init_ArenaInfo_obstacle_set
{
public:
  explicit Init_ArenaInfo_obstacle_set(::vehicle_msgs::msg::ArenaInfo & msg)
  : msg_(msg)
  {}
  Init_ArenaInfo_vehicle_set obstacle_set(::vehicle_msgs::msg::ArenaInfo::_obstacle_set_type arg)
  {
    msg_.obstacle_set = std::move(arg);
    return Init_ArenaInfo_vehicle_set(msg_);
  }

private:
  ::vehicle_msgs::msg::ArenaInfo msg_;
};

class Init_ArenaInfo_lane_net
{
public:
  explicit Init_ArenaInfo_lane_net(::vehicle_msgs::msg::ArenaInfo & msg)
  : msg_(msg)
  {}
  Init_ArenaInfo_obstacle_set lane_net(::vehicle_msgs::msg::ArenaInfo::_lane_net_type arg)
  {
    msg_.lane_net = std::move(arg);
    return Init_ArenaInfo_obstacle_set(msg_);
  }

private:
  ::vehicle_msgs::msg::ArenaInfo msg_;
};

class Init_ArenaInfo_header
{
public:
  Init_ArenaInfo_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArenaInfo_lane_net header(::vehicle_msgs::msg::ArenaInfo::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ArenaInfo_lane_net(msg_);
  }

private:
  ::vehicle_msgs::msg::ArenaInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vehicle_msgs::msg::ArenaInfo>()
{
  return vehicle_msgs::msg::builder::Init_ArenaInfo_header();
}

}  // namespace vehicle_msgs

#endif  // VEHICLE_MSGS__MSG__DETAIL__ARENA_INFO__BUILDER_HPP_
