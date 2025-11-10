// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vehicle_msgs:msg/VehicleSet.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__VEHICLE_SET__BUILDER_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__VEHICLE_SET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vehicle_msgs/msg/detail/vehicle_set__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vehicle_msgs
{

namespace msg
{

namespace builder
{

class Init_VehicleSet_vehicles
{
public:
  explicit Init_VehicleSet_vehicles(::vehicle_msgs::msg::VehicleSet & msg)
  : msg_(msg)
  {}
  ::vehicle_msgs::msg::VehicleSet vehicles(::vehicle_msgs::msg::VehicleSet::_vehicles_type arg)
  {
    msg_.vehicles = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vehicle_msgs::msg::VehicleSet msg_;
};

class Init_VehicleSet_header
{
public:
  Init_VehicleSet_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VehicleSet_vehicles header(::vehicle_msgs::msg::VehicleSet::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_VehicleSet_vehicles(msg_);
  }

private:
  ::vehicle_msgs::msg::VehicleSet msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vehicle_msgs::msg::VehicleSet>()
{
  return vehicle_msgs::msg::builder::Init_VehicleSet_header();
}

}  // namespace vehicle_msgs

#endif  // VEHICLE_MSGS__MSG__DETAIL__VEHICLE_SET__BUILDER_HPP_
