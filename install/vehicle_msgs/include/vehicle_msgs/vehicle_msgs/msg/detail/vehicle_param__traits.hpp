// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vehicle_msgs:msg/VehicleParam.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__VEHICLE_PARAM__TRAITS_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__VEHICLE_PARAM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vehicle_msgs/msg/detail/vehicle_param__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vehicle_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const VehicleParam & msg,
  std::ostream & out)
{
  out << "{";
  // member: width
  {
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << ", ";
  }

  // member: length
  {
    out << "length: ";
    rosidl_generator_traits::value_to_yaml(msg.length, out);
    out << ", ";
  }

  // member: wheel_base
  {
    out << "wheel_base: ";
    rosidl_generator_traits::value_to_yaml(msg.wheel_base, out);
    out << ", ";
  }

  // member: front_suspension
  {
    out << "front_suspension: ";
    rosidl_generator_traits::value_to_yaml(msg.front_suspension, out);
    out << ", ";
  }

  // member: rear_suspension
  {
    out << "rear_suspension: ";
    rosidl_generator_traits::value_to_yaml(msg.rear_suspension, out);
    out << ", ";
  }

  // member: max_steering_angle
  {
    out << "max_steering_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.max_steering_angle, out);
    out << ", ";
  }

  // member: d_cr
  {
    out << "d_cr: ";
    rosidl_generator_traits::value_to_yaml(msg.d_cr, out);
    out << ", ";
  }

  // member: max_longitudinal_acc
  {
    out << "max_longitudinal_acc: ";
    rosidl_generator_traits::value_to_yaml(msg.max_longitudinal_acc, out);
    out << ", ";
  }

  // member: max_lateral_acc
  {
    out << "max_lateral_acc: ";
    rosidl_generator_traits::value_to_yaml(msg.max_lateral_acc, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const VehicleParam & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
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

  // member: wheel_base
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "wheel_base: ";
    rosidl_generator_traits::value_to_yaml(msg.wheel_base, out);
    out << "\n";
  }

  // member: front_suspension
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "front_suspension: ";
    rosidl_generator_traits::value_to_yaml(msg.front_suspension, out);
    out << "\n";
  }

  // member: rear_suspension
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rear_suspension: ";
    rosidl_generator_traits::value_to_yaml(msg.rear_suspension, out);
    out << "\n";
  }

  // member: max_steering_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_steering_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.max_steering_angle, out);
    out << "\n";
  }

  // member: d_cr
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "d_cr: ";
    rosidl_generator_traits::value_to_yaml(msg.d_cr, out);
    out << "\n";
  }

  // member: max_longitudinal_acc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_longitudinal_acc: ";
    rosidl_generator_traits::value_to_yaml(msg.max_longitudinal_acc, out);
    out << "\n";
  }

  // member: max_lateral_acc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_lateral_acc: ";
    rosidl_generator_traits::value_to_yaml(msg.max_lateral_acc, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const VehicleParam & msg, bool use_flow_style = false)
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
  const vehicle_msgs::msg::VehicleParam & msg,
  std::ostream & out, size_t indentation = 0)
{
  vehicle_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vehicle_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vehicle_msgs::msg::VehicleParam & msg)
{
  return vehicle_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vehicle_msgs::msg::VehicleParam>()
{
  return "vehicle_msgs::msg::VehicleParam";
}

template<>
inline const char * name<vehicle_msgs::msg::VehicleParam>()
{
  return "vehicle_msgs/msg/VehicleParam";
}

template<>
struct has_fixed_size<vehicle_msgs::msg::VehicleParam>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<vehicle_msgs::msg::VehicleParam>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<vehicle_msgs::msg::VehicleParam>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VEHICLE_MSGS__MSG__DETAIL__VEHICLE_PARAM__TRAITS_HPP_
