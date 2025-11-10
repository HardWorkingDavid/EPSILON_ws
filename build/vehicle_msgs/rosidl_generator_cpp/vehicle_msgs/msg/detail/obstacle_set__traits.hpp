// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vehicle_msgs:msg/ObstacleSet.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__OBSTACLE_SET__TRAITS_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__OBSTACLE_SET__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vehicle_msgs/msg/detail/obstacle_set__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'obs_circle'
#include "vehicle_msgs/msg/detail/circle_obstacle__traits.hpp"
// Member 'obs_polygon'
#include "vehicle_msgs/msg/detail/polygon_obstacle__traits.hpp"

namespace vehicle_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ObstacleSet & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: obs_circle
  {
    if (msg.obs_circle.size() == 0) {
      out << "obs_circle: []";
    } else {
      out << "obs_circle: [";
      size_t pending_items = msg.obs_circle.size();
      for (auto item : msg.obs_circle) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: obs_polygon
  {
    if (msg.obs_polygon.size() == 0) {
      out << "obs_polygon: []";
    } else {
      out << "obs_polygon: [";
      size_t pending_items = msg.obs_polygon.size();
      for (auto item : msg.obs_polygon) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ObstacleSet & msg,
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

  // member: obs_circle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.obs_circle.size() == 0) {
      out << "obs_circle: []\n";
    } else {
      out << "obs_circle:\n";
      for (auto item : msg.obs_circle) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: obs_polygon
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.obs_polygon.size() == 0) {
      out << "obs_polygon: []\n";
    } else {
      out << "obs_polygon:\n";
      for (auto item : msg.obs_polygon) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ObstacleSet & msg, bool use_flow_style = false)
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
  const vehicle_msgs::msg::ObstacleSet & msg,
  std::ostream & out, size_t indentation = 0)
{
  vehicle_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vehicle_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vehicle_msgs::msg::ObstacleSet & msg)
{
  return vehicle_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vehicle_msgs::msg::ObstacleSet>()
{
  return "vehicle_msgs::msg::ObstacleSet";
}

template<>
inline const char * name<vehicle_msgs::msg::ObstacleSet>()
{
  return "vehicle_msgs/msg/ObstacleSet";
}

template<>
struct has_fixed_size<vehicle_msgs::msg::ObstacleSet>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vehicle_msgs::msg::ObstacleSet>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vehicle_msgs::msg::ObstacleSet>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VEHICLE_MSGS__MSG__DETAIL__OBSTACLE_SET__TRAITS_HPP_
