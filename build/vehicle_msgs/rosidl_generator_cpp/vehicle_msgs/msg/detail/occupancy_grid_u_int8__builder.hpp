// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vehicle_msgs:msg/OccupancyGridUInt8.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__OCCUPANCY_GRID_U_INT8__BUILDER_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__OCCUPANCY_GRID_U_INT8__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vehicle_msgs/msg/detail/occupancy_grid_u_int8__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vehicle_msgs
{

namespace msg
{

namespace builder
{

class Init_OccupancyGridUInt8_data
{
public:
  explicit Init_OccupancyGridUInt8_data(::vehicle_msgs::msg::OccupancyGridUInt8 & msg)
  : msg_(msg)
  {}
  ::vehicle_msgs::msg::OccupancyGridUInt8 data(::vehicle_msgs::msg::OccupancyGridUInt8::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vehicle_msgs::msg::OccupancyGridUInt8 msg_;
};

class Init_OccupancyGridUInt8_origin
{
public:
  explicit Init_OccupancyGridUInt8_origin(::vehicle_msgs::msg::OccupancyGridUInt8 & msg)
  : msg_(msg)
  {}
  Init_OccupancyGridUInt8_data origin(::vehicle_msgs::msg::OccupancyGridUInt8::_origin_type arg)
  {
    msg_.origin = std::move(arg);
    return Init_OccupancyGridUInt8_data(msg_);
  }

private:
  ::vehicle_msgs::msg::OccupancyGridUInt8 msg_;
};

class Init_OccupancyGridUInt8_resolution
{
public:
  explicit Init_OccupancyGridUInt8_resolution(::vehicle_msgs::msg::OccupancyGridUInt8 & msg)
  : msg_(msg)
  {}
  Init_OccupancyGridUInt8_origin resolution(::vehicle_msgs::msg::OccupancyGridUInt8::_resolution_type arg)
  {
    msg_.resolution = std::move(arg);
    return Init_OccupancyGridUInt8_origin(msg_);
  }

private:
  ::vehicle_msgs::msg::OccupancyGridUInt8 msg_;
};

class Init_OccupancyGridUInt8_height
{
public:
  explicit Init_OccupancyGridUInt8_height(::vehicle_msgs::msg::OccupancyGridUInt8 & msg)
  : msg_(msg)
  {}
  Init_OccupancyGridUInt8_resolution height(::vehicle_msgs::msg::OccupancyGridUInt8::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_OccupancyGridUInt8_resolution(msg_);
  }

private:
  ::vehicle_msgs::msg::OccupancyGridUInt8 msg_;
};

class Init_OccupancyGridUInt8_width
{
public:
  explicit Init_OccupancyGridUInt8_width(::vehicle_msgs::msg::OccupancyGridUInt8 & msg)
  : msg_(msg)
  {}
  Init_OccupancyGridUInt8_height width(::vehicle_msgs::msg::OccupancyGridUInt8::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_OccupancyGridUInt8_height(msg_);
  }

private:
  ::vehicle_msgs::msg::OccupancyGridUInt8 msg_;
};

class Init_OccupancyGridUInt8_header
{
public:
  Init_OccupancyGridUInt8_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OccupancyGridUInt8_width header(::vehicle_msgs::msg::OccupancyGridUInt8::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_OccupancyGridUInt8_width(msg_);
  }

private:
  ::vehicle_msgs::msg::OccupancyGridUInt8 msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vehicle_msgs::msg::OccupancyGridUInt8>()
{
  return vehicle_msgs::msg::builder::Init_OccupancyGridUInt8_header();
}

}  // namespace vehicle_msgs

#endif  // VEHICLE_MSGS__MSG__DETAIL__OCCUPANCY_GRID_U_INT8__BUILDER_HPP_
