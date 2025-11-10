// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vehicle_msgs:msg/Vehicle.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__VEHICLE__TRAITS_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__VEHICLE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vehicle_msgs/msg/detail/vehicle__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'id'
#include "std_msgs/msg/detail/int32__traits.hpp"
// Member 'subclass'
// Member 'type'
#include "std_msgs/msg/detail/string__traits.hpp"
// Member 'param'
#include "vehicle_msgs/msg/detail/vehicle_param__traits.hpp"
// Member 'state'
#include "vehicle_msgs/msg/detail/state__traits.hpp"

namespace vehicle_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Vehicle & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: id
  {
    out << "id: ";
    to_flow_style_yaml(msg.id, out);
    out << ", ";
  }

  // member: subclass
  {
    out << "subclass: ";
    to_flow_style_yaml(msg.subclass, out);
    out << ", ";
  }

  // member: type
  {
    out << "type: ";
    to_flow_style_yaml(msg.type, out);
    out << ", ";
  }

  // member: param
  {
    out << "param: ";
    to_flow_style_yaml(msg.param, out);
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
  const Vehicle & msg,
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

  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id:\n";
    to_block_style_yaml(msg.id, out, indentation + 2);
  }

  // member: subclass
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "subclass:\n";
    to_block_style_yaml(msg.subclass, out, indentation + 2);
  }

  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type:\n";
    to_block_style_yaml(msg.type, out, indentation + 2);
  }

  // member: param
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "param:\n";
    to_block_style_yaml(msg.param, out, indentation + 2);
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

inline std::string to_yaml(const Vehicle & msg, bool use_flow_style = false)
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
  const vehicle_msgs::msg::Vehicle & msg,
  std::ostream & out, size_t indentation = 0)
{
  vehicle_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vehicle_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vehicle_msgs::msg::Vehicle & msg)
{
  return vehicle_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vehicle_msgs::msg::Vehicle>()
{
  return "vehicle_msgs::msg::Vehicle";
}

template<>
inline const char * name<vehicle_msgs::msg::Vehicle>()
{
  return "vehicle_msgs/msg/Vehicle";
}

template<>
struct has_fixed_size<vehicle_msgs::msg::Vehicle>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value && has_fixed_size<std_msgs::msg::Int32>::value && has_fixed_size<std_msgs::msg::String>::value && has_fixed_size<vehicle_msgs::msg::State>::value && has_fixed_size<vehicle_msgs::msg::VehicleParam>::value> {};

template<>
struct has_bounded_size<vehicle_msgs::msg::Vehicle>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value && has_bounded_size<std_msgs::msg::Int32>::value && has_bounded_size<std_msgs::msg::String>::value && has_bounded_size<vehicle_msgs::msg::State>::value && has_bounded_size<vehicle_msgs::msg::VehicleParam>::value> {};

template<>
struct is_message<vehicle_msgs::msg::Vehicle>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VEHICLE_MSGS__MSG__DETAIL__VEHICLE__TRAITS_HPP_
