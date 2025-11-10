// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vehicle_msgs:msg/CircleObstacle.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__CIRCLE_OBSTACLE__BUILDER_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__CIRCLE_OBSTACLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vehicle_msgs/msg/detail/circle_obstacle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vehicle_msgs
{

namespace msg
{

namespace builder
{

class Init_CircleObstacle_circle
{
public:
  explicit Init_CircleObstacle_circle(::vehicle_msgs::msg::CircleObstacle & msg)
  : msg_(msg)
  {}
  ::vehicle_msgs::msg::CircleObstacle circle(::vehicle_msgs::msg::CircleObstacle::_circle_type arg)
  {
    msg_.circle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vehicle_msgs::msg::CircleObstacle msg_;
};

class Init_CircleObstacle_id
{
public:
  explicit Init_CircleObstacle_id(::vehicle_msgs::msg::CircleObstacle & msg)
  : msg_(msg)
  {}
  Init_CircleObstacle_circle id(::vehicle_msgs::msg::CircleObstacle::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_CircleObstacle_circle(msg_);
  }

private:
  ::vehicle_msgs::msg::CircleObstacle msg_;
};

class Init_CircleObstacle_header
{
public:
  Init_CircleObstacle_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CircleObstacle_id header(::vehicle_msgs::msg::CircleObstacle::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_CircleObstacle_id(msg_);
  }

private:
  ::vehicle_msgs::msg::CircleObstacle msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vehicle_msgs::msg::CircleObstacle>()
{
  return vehicle_msgs::msg::builder::Init_CircleObstacle_header();
}

}  // namespace vehicle_msgs

#endif  // VEHICLE_MSGS__MSG__DETAIL__CIRCLE_OBSTACLE__BUILDER_HPP_
