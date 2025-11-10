// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vehicle_msgs:msg/PolygonObstacle.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__POLYGON_OBSTACLE__BUILDER_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__POLYGON_OBSTACLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vehicle_msgs/msg/detail/polygon_obstacle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vehicle_msgs
{

namespace msg
{

namespace builder
{

class Init_PolygonObstacle_polygon
{
public:
  explicit Init_PolygonObstacle_polygon(::vehicle_msgs::msg::PolygonObstacle & msg)
  : msg_(msg)
  {}
  ::vehicle_msgs::msg::PolygonObstacle polygon(::vehicle_msgs::msg::PolygonObstacle::_polygon_type arg)
  {
    msg_.polygon = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vehicle_msgs::msg::PolygonObstacle msg_;
};

class Init_PolygonObstacle_id
{
public:
  explicit Init_PolygonObstacle_id(::vehicle_msgs::msg::PolygonObstacle & msg)
  : msg_(msg)
  {}
  Init_PolygonObstacle_polygon id(::vehicle_msgs::msg::PolygonObstacle::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_PolygonObstacle_polygon(msg_);
  }

private:
  ::vehicle_msgs::msg::PolygonObstacle msg_;
};

class Init_PolygonObstacle_header
{
public:
  Init_PolygonObstacle_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PolygonObstacle_id header(::vehicle_msgs::msg::PolygonObstacle::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_PolygonObstacle_id(msg_);
  }

private:
  ::vehicle_msgs::msg::PolygonObstacle msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vehicle_msgs::msg::PolygonObstacle>()
{
  return vehicle_msgs::msg::builder::Init_PolygonObstacle_header();
}

}  // namespace vehicle_msgs

#endif  // VEHICLE_MSGS__MSG__DETAIL__POLYGON_OBSTACLE__BUILDER_HPP_
