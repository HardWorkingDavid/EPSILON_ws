// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vehicle_msgs:msg/LaneNet.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__LANE_NET__BUILDER_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__LANE_NET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vehicle_msgs/msg/detail/lane_net__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vehicle_msgs
{

namespace msg
{

namespace builder
{

class Init_LaneNet_lanes
{
public:
  explicit Init_LaneNet_lanes(::vehicle_msgs::msg::LaneNet & msg)
  : msg_(msg)
  {}
  ::vehicle_msgs::msg::LaneNet lanes(::vehicle_msgs::msg::LaneNet::_lanes_type arg)
  {
    msg_.lanes = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vehicle_msgs::msg::LaneNet msg_;
};

class Init_LaneNet_header
{
public:
  Init_LaneNet_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LaneNet_lanes header(::vehicle_msgs::msg::LaneNet::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_LaneNet_lanes(msg_);
  }

private:
  ::vehicle_msgs::msg::LaneNet msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vehicle_msgs::msg::LaneNet>()
{
  return vehicle_msgs::msg::builder::Init_LaneNet_header();
}

}  // namespace vehicle_msgs

#endif  // VEHICLE_MSGS__MSG__DETAIL__LANE_NET__BUILDER_HPP_
