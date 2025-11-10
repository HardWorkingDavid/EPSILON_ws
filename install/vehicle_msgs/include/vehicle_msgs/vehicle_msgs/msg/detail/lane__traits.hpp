// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vehicle_msgs:msg/Lane.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__LANE__TRAITS_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__LANE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vehicle_msgs/msg/detail/lane__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'start_point'
// Member 'final_point'
// Member 'points'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace vehicle_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Lane & msg,
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
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: dir
  {
    out << "dir: ";
    rosidl_generator_traits::value_to_yaml(msg.dir, out);
    out << ", ";
  }

  // member: child_id
  {
    if (msg.child_id.size() == 0) {
      out << "child_id: []";
    } else {
      out << "child_id: [";
      size_t pending_items = msg.child_id.size();
      for (auto item : msg.child_id) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: father_id
  {
    if (msg.father_id.size() == 0) {
      out << "father_id: []";
    } else {
      out << "father_id: [";
      size_t pending_items = msg.father_id.size();
      for (auto item : msg.father_id) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: l_lane_id
  {
    out << "l_lane_id: ";
    rosidl_generator_traits::value_to_yaml(msg.l_lane_id, out);
    out << ", ";
  }

  // member: l_change_avbl
  {
    out << "l_change_avbl: ";
    rosidl_generator_traits::value_to_yaml(msg.l_change_avbl, out);
    out << ", ";
  }

  // member: r_lane_id
  {
    out << "r_lane_id: ";
    rosidl_generator_traits::value_to_yaml(msg.r_lane_id, out);
    out << ", ";
  }

  // member: r_change_avbl
  {
    out << "r_change_avbl: ";
    rosidl_generator_traits::value_to_yaml(msg.r_change_avbl, out);
    out << ", ";
  }

  // member: behavior
  {
    out << "behavior: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior, out);
    out << ", ";
  }

  // member: length
  {
    out << "length: ";
    rosidl_generator_traits::value_to_yaml(msg.length, out);
    out << ", ";
  }

  // member: start_point
  {
    out << "start_point: ";
    to_flow_style_yaml(msg.start_point, out);
    out << ", ";
  }

  // member: final_point
  {
    out << "final_point: ";
    to_flow_style_yaml(msg.final_point, out);
    out << ", ";
  }

  // member: points
  {
    if (msg.points.size() == 0) {
      out << "points: []";
    } else {
      out << "points: [";
      size_t pending_items = msg.points.size();
      for (auto item : msg.points) {
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
  const Lane & msg,
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
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: dir
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dir: ";
    rosidl_generator_traits::value_to_yaml(msg.dir, out);
    out << "\n";
  }

  // member: child_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.child_id.size() == 0) {
      out << "child_id: []\n";
    } else {
      out << "child_id:\n";
      for (auto item : msg.child_id) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: father_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.father_id.size() == 0) {
      out << "father_id: []\n";
    } else {
      out << "father_id:\n";
      for (auto item : msg.father_id) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: l_lane_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "l_lane_id: ";
    rosidl_generator_traits::value_to_yaml(msg.l_lane_id, out);
    out << "\n";
  }

  // member: l_change_avbl
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "l_change_avbl: ";
    rosidl_generator_traits::value_to_yaml(msg.l_change_avbl, out);
    out << "\n";
  }

  // member: r_lane_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "r_lane_id: ";
    rosidl_generator_traits::value_to_yaml(msg.r_lane_id, out);
    out << "\n";
  }

  // member: r_change_avbl
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "r_change_avbl: ";
    rosidl_generator_traits::value_to_yaml(msg.r_change_avbl, out);
    out << "\n";
  }

  // member: behavior
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "behavior: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior, out);
    out << "\n";
  }

  // member: length
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "length: ";
    rosidl_generator_traits::value_to_yaml(msg.length, out);
    out << "\n";
  }

  // member: start_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start_point:\n";
    to_block_style_yaml(msg.start_point, out, indentation + 2);
  }

  // member: final_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "final_point:\n";
    to_block_style_yaml(msg.final_point, out, indentation + 2);
  }

  // member: points
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.points.size() == 0) {
      out << "points: []\n";
    } else {
      out << "points:\n";
      for (auto item : msg.points) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Lane & msg, bool use_flow_style = false)
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
  const vehicle_msgs::msg::Lane & msg,
  std::ostream & out, size_t indentation = 0)
{
  vehicle_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vehicle_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vehicle_msgs::msg::Lane & msg)
{
  return vehicle_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vehicle_msgs::msg::Lane>()
{
  return "vehicle_msgs::msg::Lane";
}

template<>
inline const char * name<vehicle_msgs::msg::Lane>()
{
  return "vehicle_msgs/msg/Lane";
}

template<>
struct has_fixed_size<vehicle_msgs::msg::Lane>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vehicle_msgs::msg::Lane>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vehicle_msgs::msg::Lane>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VEHICLE_MSGS__MSG__DETAIL__LANE__TRAITS_HPP_
