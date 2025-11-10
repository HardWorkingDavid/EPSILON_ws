// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vehicle_msgs:msg/OccupancyGridFloat.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__OCCUPANCY_GRID_FLOAT__BUILDER_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__OCCUPANCY_GRID_FLOAT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vehicle_msgs/msg/detail/occupancy_grid_float__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vehicle_msgs
{

namespace msg
{

namespace builder
{

class Init_OccupancyGridFloat_data
{
public:
  explicit Init_OccupancyGridFloat_data(::vehicle_msgs::msg::OccupancyGridFloat & msg)
  : msg_(msg)
  {}
  ::vehicle_msgs::msg::OccupancyGridFloat data(::vehicle_msgs::msg::OccupancyGridFloat::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vehicle_msgs::msg::OccupancyGridFloat msg_;
};

class Init_OccupancyGridFloat_origin
{
public:
  explicit Init_OccupancyGridFloat_origin(::vehicle_msgs::msg::OccupancyGridFloat & msg)
  : msg_(msg)
  {}
  Init_OccupancyGridFloat_data origin(::vehicle_msgs::msg::OccupancyGridFloat::_origin_type arg)
  {
    msg_.origin = std::move(arg);
    return Init_OccupancyGridFloat_data(msg_);
  }

private:
  ::vehicle_msgs::msg::OccupancyGridFloat msg_;
};

class Init_OccupancyGridFloat_resolution
{
public:
  explicit Init_OccupancyGridFloat_resolution(::vehicle_msgs::msg::OccupancyGridFloat & msg)
  : msg_(msg)
  {}
  Init_OccupancyGridFloat_origin resolution(::vehicle_msgs::msg::OccupancyGridFloat::_resolution_type arg)
  {
    msg_.resolution = std::move(arg);
    return Init_OccupancyGridFloat_origin(msg_);
  }

private:
  ::vehicle_msgs::msg::OccupancyGridFloat msg_;
};

class Init_OccupancyGridFloat_height
{
public:
  explicit Init_OccupancyGridFloat_height(::vehicle_msgs::msg::OccupancyGridFloat & msg)
  : msg_(msg)
  {}
  Init_OccupancyGridFloat_resolution height(::vehicle_msgs::msg::OccupancyGridFloat::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_OccupancyGridFloat_resolution(msg_);
  }

private:
  ::vehicle_msgs::msg::OccupancyGridFloat msg_;
};

class Init_OccupancyGridFloat_width
{
public:
  explicit Init_OccupancyGridFloat_width(::vehicle_msgs::msg::OccupancyGridFloat & msg)
  : msg_(msg)
  {}
  Init_OccupancyGridFloat_height width(::vehicle_msgs::msg::OccupancyGridFloat::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_OccupancyGridFloat_height(msg_);
  }

private:
  ::vehicle_msgs::msg::OccupancyGridFloat msg_;
};

class Init_OccupancyGridFloat_header
{
public:
  Init_OccupancyGridFloat_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OccupancyGridFloat_width header(::vehicle_msgs::msg::OccupancyGridFloat::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_OccupancyGridFloat_width(msg_);
  }

private:
  ::vehicle_msgs::msg::OccupancyGridFloat msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vehicle_msgs::msg::OccupancyGridFloat>()
{
  return vehicle_msgs::msg::builder::Init_OccupancyGridFloat_header();
}

}  // namespace vehicle_msgs

#endif  // VEHICLE_MSGS__MSG__DETAIL__OCCUPANCY_GRID_FLOAT__BUILDER_HPP_
