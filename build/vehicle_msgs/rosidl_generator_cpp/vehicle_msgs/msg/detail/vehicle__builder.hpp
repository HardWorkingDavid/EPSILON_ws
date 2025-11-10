// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vehicle_msgs:msg/Vehicle.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__VEHICLE__BUILDER_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__VEHICLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vehicle_msgs/msg/detail/vehicle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vehicle_msgs
{

namespace msg
{

namespace builder
{

class Init_Vehicle_state
{
public:
  explicit Init_Vehicle_state(::vehicle_msgs::msg::Vehicle & msg)
  : msg_(msg)
  {}
  ::vehicle_msgs::msg::Vehicle state(::vehicle_msgs::msg::Vehicle::_state_type arg)
  {
    msg_.state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vehicle_msgs::msg::Vehicle msg_;
};

class Init_Vehicle_param
{
public:
  explicit Init_Vehicle_param(::vehicle_msgs::msg::Vehicle & msg)
  : msg_(msg)
  {}
  Init_Vehicle_state param(::vehicle_msgs::msg::Vehicle::_param_type arg)
  {
    msg_.param = std::move(arg);
    return Init_Vehicle_state(msg_);
  }

private:
  ::vehicle_msgs::msg::Vehicle msg_;
};

class Init_Vehicle_type
{
public:
  explicit Init_Vehicle_type(::vehicle_msgs::msg::Vehicle & msg)
  : msg_(msg)
  {}
  Init_Vehicle_param type(::vehicle_msgs::msg::Vehicle::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_Vehicle_param(msg_);
  }

private:
  ::vehicle_msgs::msg::Vehicle msg_;
};

class Init_Vehicle_subclass
{
public:
  explicit Init_Vehicle_subclass(::vehicle_msgs::msg::Vehicle & msg)
  : msg_(msg)
  {}
  Init_Vehicle_type subclass(::vehicle_msgs::msg::Vehicle::_subclass_type arg)
  {
    msg_.subclass = std::move(arg);
    return Init_Vehicle_type(msg_);
  }

private:
  ::vehicle_msgs::msg::Vehicle msg_;
};

class Init_Vehicle_id
{
public:
  explicit Init_Vehicle_id(::vehicle_msgs::msg::Vehicle & msg)
  : msg_(msg)
  {}
  Init_Vehicle_subclass id(::vehicle_msgs::msg::Vehicle::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Vehicle_subclass(msg_);
  }

private:
  ::vehicle_msgs::msg::Vehicle msg_;
};

class Init_Vehicle_header
{
public:
  Init_Vehicle_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Vehicle_id header(::vehicle_msgs::msg::Vehicle::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Vehicle_id(msg_);
  }

private:
  ::vehicle_msgs::msg::Vehicle msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vehicle_msgs::msg::Vehicle>()
{
  return vehicle_msgs::msg::builder::Init_Vehicle_header();
}

}  // namespace vehicle_msgs

#endif  // VEHICLE_MSGS__MSG__DETAIL__VEHICLE__BUILDER_HPP_
