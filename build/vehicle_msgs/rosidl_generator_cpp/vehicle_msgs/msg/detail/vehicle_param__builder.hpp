// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vehicle_msgs:msg/VehicleParam.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__VEHICLE_PARAM__BUILDER_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__VEHICLE_PARAM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vehicle_msgs/msg/detail/vehicle_param__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vehicle_msgs
{

namespace msg
{

namespace builder
{

class Init_VehicleParam_max_lateral_acc
{
public:
  explicit Init_VehicleParam_max_lateral_acc(::vehicle_msgs::msg::VehicleParam & msg)
  : msg_(msg)
  {}
  ::vehicle_msgs::msg::VehicleParam max_lateral_acc(::vehicle_msgs::msg::VehicleParam::_max_lateral_acc_type arg)
  {
    msg_.max_lateral_acc = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vehicle_msgs::msg::VehicleParam msg_;
};

class Init_VehicleParam_max_longitudinal_acc
{
public:
  explicit Init_VehicleParam_max_longitudinal_acc(::vehicle_msgs::msg::VehicleParam & msg)
  : msg_(msg)
  {}
  Init_VehicleParam_max_lateral_acc max_longitudinal_acc(::vehicle_msgs::msg::VehicleParam::_max_longitudinal_acc_type arg)
  {
    msg_.max_longitudinal_acc = std::move(arg);
    return Init_VehicleParam_max_lateral_acc(msg_);
  }

private:
  ::vehicle_msgs::msg::VehicleParam msg_;
};

class Init_VehicleParam_d_cr
{
public:
  explicit Init_VehicleParam_d_cr(::vehicle_msgs::msg::VehicleParam & msg)
  : msg_(msg)
  {}
  Init_VehicleParam_max_longitudinal_acc d_cr(::vehicle_msgs::msg::VehicleParam::_d_cr_type arg)
  {
    msg_.d_cr = std::move(arg);
    return Init_VehicleParam_max_longitudinal_acc(msg_);
  }

private:
  ::vehicle_msgs::msg::VehicleParam msg_;
};

class Init_VehicleParam_max_steering_angle
{
public:
  explicit Init_VehicleParam_max_steering_angle(::vehicle_msgs::msg::VehicleParam & msg)
  : msg_(msg)
  {}
  Init_VehicleParam_d_cr max_steering_angle(::vehicle_msgs::msg::VehicleParam::_max_steering_angle_type arg)
  {
    msg_.max_steering_angle = std::move(arg);
    return Init_VehicleParam_d_cr(msg_);
  }

private:
  ::vehicle_msgs::msg::VehicleParam msg_;
};

class Init_VehicleParam_rear_suspension
{
public:
  explicit Init_VehicleParam_rear_suspension(::vehicle_msgs::msg::VehicleParam & msg)
  : msg_(msg)
  {}
  Init_VehicleParam_max_steering_angle rear_suspension(::vehicle_msgs::msg::VehicleParam::_rear_suspension_type arg)
  {
    msg_.rear_suspension = std::move(arg);
    return Init_VehicleParam_max_steering_angle(msg_);
  }

private:
  ::vehicle_msgs::msg::VehicleParam msg_;
};

class Init_VehicleParam_front_suspension
{
public:
  explicit Init_VehicleParam_front_suspension(::vehicle_msgs::msg::VehicleParam & msg)
  : msg_(msg)
  {}
  Init_VehicleParam_rear_suspension front_suspension(::vehicle_msgs::msg::VehicleParam::_front_suspension_type arg)
  {
    msg_.front_suspension = std::move(arg);
    return Init_VehicleParam_rear_suspension(msg_);
  }

private:
  ::vehicle_msgs::msg::VehicleParam msg_;
};

class Init_VehicleParam_wheel_base
{
public:
  explicit Init_VehicleParam_wheel_base(::vehicle_msgs::msg::VehicleParam & msg)
  : msg_(msg)
  {}
  Init_VehicleParam_front_suspension wheel_base(::vehicle_msgs::msg::VehicleParam::_wheel_base_type arg)
  {
    msg_.wheel_base = std::move(arg);
    return Init_VehicleParam_front_suspension(msg_);
  }

private:
  ::vehicle_msgs::msg::VehicleParam msg_;
};

class Init_VehicleParam_length
{
public:
  explicit Init_VehicleParam_length(::vehicle_msgs::msg::VehicleParam & msg)
  : msg_(msg)
  {}
  Init_VehicleParam_wheel_base length(::vehicle_msgs::msg::VehicleParam::_length_type arg)
  {
    msg_.length = std::move(arg);
    return Init_VehicleParam_wheel_base(msg_);
  }

private:
  ::vehicle_msgs::msg::VehicleParam msg_;
};

class Init_VehicleParam_width
{
public:
  Init_VehicleParam_width()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VehicleParam_length width(::vehicle_msgs::msg::VehicleParam::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_VehicleParam_length(msg_);
  }

private:
  ::vehicle_msgs::msg::VehicleParam msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vehicle_msgs::msg::VehicleParam>()
{
  return vehicle_msgs::msg::builder::Init_VehicleParam_width();
}

}  // namespace vehicle_msgs

#endif  // VEHICLE_MSGS__MSG__DETAIL__VEHICLE_PARAM__BUILDER_HPP_
