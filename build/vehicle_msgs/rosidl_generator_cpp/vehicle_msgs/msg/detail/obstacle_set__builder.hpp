// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vehicle_msgs:msg/ObstacleSet.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__OBSTACLE_SET__BUILDER_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__OBSTACLE_SET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vehicle_msgs/msg/detail/obstacle_set__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vehicle_msgs
{

namespace msg
{

namespace builder
{

class Init_ObstacleSet_obs_polygon
{
public:
  explicit Init_ObstacleSet_obs_polygon(::vehicle_msgs::msg::ObstacleSet & msg)
  : msg_(msg)
  {}
  ::vehicle_msgs::msg::ObstacleSet obs_polygon(::vehicle_msgs::msg::ObstacleSet::_obs_polygon_type arg)
  {
    msg_.obs_polygon = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vehicle_msgs::msg::ObstacleSet msg_;
};

class Init_ObstacleSet_obs_circle
{
public:
  explicit Init_ObstacleSet_obs_circle(::vehicle_msgs::msg::ObstacleSet & msg)
  : msg_(msg)
  {}
  Init_ObstacleSet_obs_polygon obs_circle(::vehicle_msgs::msg::ObstacleSet::_obs_circle_type arg)
  {
    msg_.obs_circle = std::move(arg);
    return Init_ObstacleSet_obs_polygon(msg_);
  }

private:
  ::vehicle_msgs::msg::ObstacleSet msg_;
};

class Init_ObstacleSet_header
{
public:
  Init_ObstacleSet_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObstacleSet_obs_circle header(::vehicle_msgs::msg::ObstacleSet::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ObstacleSet_obs_circle(msg_);
  }

private:
  ::vehicle_msgs::msg::ObstacleSet msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vehicle_msgs::msg::ObstacleSet>()
{
  return vehicle_msgs::msg::builder::Init_ObstacleSet_header();
}

}  // namespace vehicle_msgs

#endif  // VEHICLE_MSGS__MSG__DETAIL__OBSTACLE_SET__BUILDER_HPP_
