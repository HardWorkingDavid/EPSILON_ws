// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vehicle_msgs:msg/ControlSignal.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__CONTROL_SIGNAL__TRAITS_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__CONTROL_SIGNAL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vehicle_msgs/msg/detail/control_signal__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'is_openloop'
#include "std_msgs/msg/detail/bool__traits.hpp"
// Member 'state'
#include "vehicle_msgs/msg/detail/state__traits.hpp"

namespace vehicle_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ControlSignal & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: acc
  {
    out << "acc: ";
    rosidl_generator_traits::value_to_yaml(msg.acc, out);
    out << ", ";
  }

  // member: steer_rate
  {
    out << "steer_rate: ";
    rosidl_generator_traits::value_to_yaml(msg.steer_rate, out);
    out << ", ";
  }

  // member: is_openloop
  {
    out << "is_openloop: ";
    to_flow_style_yaml(msg.is_openloop, out);
    out << ", ";
  }

  // member: state
  {
    out << "state: ";
    to_flow_style_yaml(msg.state, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ControlSignal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: acc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "acc: ";
    rosidl_generator_traits::value_to_yaml(msg.acc, out);
    out << "\n";
  }

  // member: steer_rate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "steer_rate: ";
    rosidl_generator_traits::value_to_yaml(msg.steer_rate, out);
    out << "\n";
  }

  // member: is_openloop
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_openloop:\n";
    to_block_style_yaml(msg.is_openloop, out, indentation + 2);
  }

  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state:\n";
    to_block_style_yaml(msg.state, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ControlSignal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace vehicle_msgs

namespace rosidl_generator_traits
{

[[deprecated("use vehicle_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const vehicle_msgs::msg::ControlSignal & msg,
  std::ostream & out, size_t indentation = 0)
{
  vehicle_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vehicle_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vehicle_msgs::msg::ControlSignal & msg)
{
  return vehicle_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vehicle_msgs::msg::ControlSignal>()
{
  return "vehicle_msgs::msg::ControlSignal";
}

template<>
inline const char * name<vehicle_msgs::msg::ControlSignal>()
{
  return "vehicle_msgs/msg/ControlSignal";
}

template<>
struct has_fixed_size<vehicle_msgs::msg::ControlSignal>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Bool>::value && has_fixed_size<std_msgs::msg::Header>::value && has_fixed_size<vehicle_msgs::msg::State>::value> {};

template<>
struct has_bounded_size<vehicle_msgs::msg::ControlSignal>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Bool>::value && has_bounded_size<std_msgs::msg::Header>::value && has_bounded_size<vehicle_msgs::msg::State>::value> {};

template<>
struct is_message<vehicle_msgs::msg::ControlSignal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VEHICLE_MSGS__MSG__DETAIL__CONTROL_SIGNAL__TRAITS_HPP_
