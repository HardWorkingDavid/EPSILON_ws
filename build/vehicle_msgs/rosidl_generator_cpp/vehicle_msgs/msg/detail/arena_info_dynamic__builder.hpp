// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vehicle_msgs:msg/ArenaInfoDynamic.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__ARENA_INFO_DYNAMIC__BUILDER_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__ARENA_INFO_DYNAMIC__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vehicle_msgs/msg/detail/arena_info_dynamic__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vehicle_msgs
{

namespace msg
{

namespace builder
{

class Init_ArenaInfoDynamic_vehicle_set
{
public:
  explicit Init_ArenaInfoDynamic_vehicle_set(::vehicle_msgs::msg::ArenaInfoDynamic & msg)
  : msg_(msg)
  {}
  ::vehicle_msgs::msg::ArenaInfoDynamic vehicle_set(::vehicle_msgs::msg::ArenaInfoDynamic::_vehicle_set_type arg)
  {
    msg_.vehicle_set = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vehicle_msgs::msg::ArenaInfoDynamic msg_;
};

class Init_ArenaInfoDynamic_header
{
public:
  Init_ArenaInfoDynamic_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArenaInfoDynamic_vehicle_set header(::vehicle_msgs::msg::ArenaInfoDynamic::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ArenaInfoDynamic_vehicle_set(msg_);
  }

private:
  ::vehicle_msgs::msg::ArenaInfoDynamic msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vehicle_msgs::msg::ArenaInfoDynamic>()
{
  return vehicle_msgs::msg::builder::Init_ArenaInfoDynamic_header();
}

}  // namespace vehicle_msgs

#endif  // VEHICLE_MSGS__MSG__DETAIL__ARENA_INFO_DYNAMIC__BUILDER_HPP_
