// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vehicle_msgs:msg/Circle.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__CIRCLE__STRUCT_H_
#define VEHICLE_MSGS__MSG__DETAIL__CIRCLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'center'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/Circle in the package vehicle_msgs.
typedef struct vehicle_msgs__msg__Circle
{
  geometry_msgs__msg__Point center;
  float radius;
} vehicle_msgs__msg__Circle;

// Struct for a sequence of vehicle_msgs__msg__Circle.
typedef struct vehicle_msgs__msg__Circle__Sequence
{
  vehicle_msgs__msg__Circle * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vehicle_msgs__msg__Circle__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VEHICLE_MSGS__MSG__DETAIL__CIRCLE__STRUCT_H_
