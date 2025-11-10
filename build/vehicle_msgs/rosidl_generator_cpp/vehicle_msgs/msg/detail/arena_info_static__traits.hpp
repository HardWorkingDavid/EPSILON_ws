// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vehicle_msgs:msg/ArenaInfoStatic.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__ARENA_INFO_STATIC__TRAITS_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__ARENA_INFO_STATIC__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vehicle_msgs/msg/detail/arena_info_static__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'lane_net'
#include "vehicle_msgs/msg/detail/lane_net__traits.hpp"
// Member 'obstacle_set'
#include "vehicle_msgs/msg/detail/obstacle_set__traits.hpp"

namespace vehicle_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ArenaInfoStatic & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: lane_net
  {
    out << "lane_net: ";
    to_flow_style_yaml(msg.lane_net, out);
    out << ", ";
  }

  // member: obstacle_set
  {
    out << "obstacle_set: ";
    to_flow_style_yaml(msg.obstacle_set, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ArenaInfoStatic & msg,
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

  // member: lane_net
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lane_net:\n";
    to_block_style_yaml(msg.lane_net, out, indentation + 2);
  }

  // member: obstacle_set
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "obstacle_set:\n";
    to_block_style_yaml(msg.obstacle_set, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ArenaInfoStatic & msg, bool use_flow_style = false)
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
  const vehicle_msgs::msg::ArenaInfoStatic & msg,
  std::ostream & out, size_t indentation = 0)
{
  vehicle_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vehicle_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vehicle_msgs::msg::ArenaInfoStatic & msg)
{
  return vehicle_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vehicle_msgs::msg::ArenaInfoStatic>()
{
  return "vehicle_msgs::msg::ArenaInfoStatic";
}

template<>
inline const char * name<vehicle_msgs::msg::ArenaInfoStatic>()
{
  return "vehicle_msgs/msg/ArenaInfoStatic";
}

template<>
struct has_fixed_size<vehicle_msgs::msg::ArenaInfoStatic>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value && has_fixed_size<vehicle_msgs::msg::LaneNet>::value && has_fixed_size<vehicle_msgs::msg::ObstacleSet>::value> {};

template<>
struct has_bounded_size<vehicle_msgs::msg::ArenaInfoStatic>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value && has_bounded_size<vehicle_msgs::msg::LaneNet>::value && has_bounded_size<vehicle_msgs::msg::ObstacleSet>::value> {};

template<>
struct is_message<vehicle_msgs::msg::ArenaInfoStatic>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VEHICLE_MSGS__MSG__DETAIL__ARENA_INFO_STATIC__TRAITS_HPP_
