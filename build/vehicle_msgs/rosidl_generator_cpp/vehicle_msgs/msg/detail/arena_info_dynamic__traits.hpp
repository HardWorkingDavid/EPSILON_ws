// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vehicle_msgs:msg/ArenaInfoDynamic.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__ARENA_INFO_DYNAMIC__TRAITS_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__ARENA_INFO_DYNAMIC__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vehicle_msgs/msg/detail/arena_info_dynamic__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'vehicle_set'
#include "vehicle_msgs/msg/detail/vehicle_set__traits.hpp"

namespace vehicle_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ArenaInfoDynamic & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: vehicle_set
  {
    out << "vehicle_set: ";
    to_flow_style_yaml(msg.vehicle_set, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ArenaInfoDynamic & msg,
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

  // member: vehicle_set
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vehicle_set:\n";
    to_block_style_yaml(msg.vehicle_set, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ArenaInfoDynamic & msg, bool use_flow_style = false)
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
  const vehicle_msgs::msg::ArenaInfoDynamic & msg,
  std::ostream & out, size_t indentation = 0)
{
  vehicle_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vehicle_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vehicle_msgs::msg::ArenaInfoDynamic & msg)
{
  return vehicle_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vehicle_msgs::msg::ArenaInfoDynamic>()
{
  return "vehicle_msgs::msg::ArenaInfoDynamic";
}

template<>
inline const char * name<vehicle_msgs::msg::ArenaInfoDynamic>()
{
  return "vehicle_msgs/msg/ArenaInfoDynamic";
}

template<>
struct has_fixed_size<vehicle_msgs::msg::ArenaInfoDynamic>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value && has_fixed_size<vehicle_msgs::msg::VehicleSet>::value> {};

template<>
struct has_bounded_size<vehicle_msgs::msg::ArenaInfoDynamic>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value && has_bounded_size<vehicle_msgs::msg::VehicleSet>::value> {};

template<>
struct is_message<vehicle_msgs::msg::ArenaInfoDynamic>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VEHICLE_MSGS__MSG__DETAIL__ARENA_INFO_DYNAMIC__TRAITS_HPP_
