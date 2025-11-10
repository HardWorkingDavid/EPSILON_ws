// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vehicle_msgs:msg/Lane.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__LANE__BUILDER_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__LANE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vehicle_msgs/msg/detail/lane__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vehicle_msgs
{

namespace msg
{

namespace builder
{

class Init_Lane_points
{
public:
  explicit Init_Lane_points(::vehicle_msgs::msg::Lane & msg)
  : msg_(msg)
  {}
  ::vehicle_msgs::msg::Lane points(::vehicle_msgs::msg::Lane::_points_type arg)
  {
    msg_.points = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vehicle_msgs::msg::Lane msg_;
};

class Init_Lane_final_point
{
public:
  explicit Init_Lane_final_point(::vehicle_msgs::msg::Lane & msg)
  : msg_(msg)
  {}
  Init_Lane_points final_point(::vehicle_msgs::msg::Lane::_final_point_type arg)
  {
    msg_.final_point = std::move(arg);
    return Init_Lane_points(msg_);
  }

private:
  ::vehicle_msgs::msg::Lane msg_;
};

class Init_Lane_start_point
{
public:
  explicit Init_Lane_start_point(::vehicle_msgs::msg::Lane & msg)
  : msg_(msg)
  {}
  Init_Lane_final_point start_point(::vehicle_msgs::msg::Lane::_start_point_type arg)
  {
    msg_.start_point = std::move(arg);
    return Init_Lane_final_point(msg_);
  }

private:
  ::vehicle_msgs::msg::Lane msg_;
};

class Init_Lane_length
{
public:
  explicit Init_Lane_length(::vehicle_msgs::msg::Lane & msg)
  : msg_(msg)
  {}
  Init_Lane_start_point length(::vehicle_msgs::msg::Lane::_length_type arg)
  {
    msg_.length = std::move(arg);
    return Init_Lane_start_point(msg_);
  }

private:
  ::vehicle_msgs::msg::Lane msg_;
};

class Init_Lane_behavior
{
public:
  explicit Init_Lane_behavior(::vehicle_msgs::msg::Lane & msg)
  : msg_(msg)
  {}
  Init_Lane_length behavior(::vehicle_msgs::msg::Lane::_behavior_type arg)
  {
    msg_.behavior = std::move(arg);
    return Init_Lane_length(msg_);
  }

private:
  ::vehicle_msgs::msg::Lane msg_;
};

class Init_Lane_r_change_avbl
{
public:
  explicit Init_Lane_r_change_avbl(::vehicle_msgs::msg::Lane & msg)
  : msg_(msg)
  {}
  Init_Lane_behavior r_change_avbl(::vehicle_msgs::msg::Lane::_r_change_avbl_type arg)
  {
    msg_.r_change_avbl = std::move(arg);
    return Init_Lane_behavior(msg_);
  }

private:
  ::vehicle_msgs::msg::Lane msg_;
};

class Init_Lane_r_lane_id
{
public:
  explicit Init_Lane_r_lane_id(::vehicle_msgs::msg::Lane & msg)
  : msg_(msg)
  {}
  Init_Lane_r_change_avbl r_lane_id(::vehicle_msgs::msg::Lane::_r_lane_id_type arg)
  {
    msg_.r_lane_id = std::move(arg);
    return Init_Lane_r_change_avbl(msg_);
  }

private:
  ::vehicle_msgs::msg::Lane msg_;
};

class Init_Lane_l_change_avbl
{
public:
  explicit Init_Lane_l_change_avbl(::vehicle_msgs::msg::Lane & msg)
  : msg_(msg)
  {}
  Init_Lane_r_lane_id l_change_avbl(::vehicle_msgs::msg::Lane::_l_change_avbl_type arg)
  {
    msg_.l_change_avbl = std::move(arg);
    return Init_Lane_r_lane_id(msg_);
  }

private:
  ::vehicle_msgs::msg::Lane msg_;
};

class Init_Lane_l_lane_id
{
public:
  explicit Init_Lane_l_lane_id(::vehicle_msgs::msg::Lane & msg)
  : msg_(msg)
  {}
  Init_Lane_l_change_avbl l_lane_id(::vehicle_msgs::msg::Lane::_l_lane_id_type arg)
  {
    msg_.l_lane_id = std::move(arg);
    return Init_Lane_l_change_avbl(msg_);
  }

private:
  ::vehicle_msgs::msg::Lane msg_;
};

class Init_Lane_father_id
{
public:
  explicit Init_Lane_father_id(::vehicle_msgs::msg::Lane & msg)
  : msg_(msg)
  {}
  Init_Lane_l_lane_id father_id(::vehicle_msgs::msg::Lane::_father_id_type arg)
  {
    msg_.father_id = std::move(arg);
    return Init_Lane_l_lane_id(msg_);
  }

private:
  ::vehicle_msgs::msg::Lane msg_;
};

class Init_Lane_child_id
{
public:
  explicit Init_Lane_child_id(::vehicle_msgs::msg::Lane & msg)
  : msg_(msg)
  {}
  Init_Lane_father_id child_id(::vehicle_msgs::msg::Lane::_child_id_type arg)
  {
    msg_.child_id = std::move(arg);
    return Init_Lane_father_id(msg_);
  }

private:
  ::vehicle_msgs::msg::Lane msg_;
};

class Init_Lane_dir
{
public:
  explicit Init_Lane_dir(::vehicle_msgs::msg::Lane & msg)
  : msg_(msg)
  {}
  Init_Lane_child_id dir(::vehicle_msgs::msg::Lane::_dir_type arg)
  {
    msg_.dir = std::move(arg);
    return Init_Lane_child_id(msg_);
  }

private:
  ::vehicle_msgs::msg::Lane msg_;
};

class Init_Lane_id
{
public:
  explicit Init_Lane_id(::vehicle_msgs::msg::Lane & msg)
  : msg_(msg)
  {}
  Init_Lane_dir id(::vehicle_msgs::msg::Lane::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Lane_dir(msg_);
  }

private:
  ::vehicle_msgs::msg::Lane msg_;
};

class Init_Lane_header
{
public:
  Init_Lane_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Lane_id header(::vehicle_msgs::msg::Lane::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Lane_id(msg_);
  }

private:
  ::vehicle_msgs::msg::Lane msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vehicle_msgs::msg::Lane>()
{
  return vehicle_msgs::msg::builder::Init_Lane_header();
}

}  // namespace vehicle_msgs

#endif  // VEHICLE_MSGS__MSG__DETAIL__LANE__BUILDER_HPP_
