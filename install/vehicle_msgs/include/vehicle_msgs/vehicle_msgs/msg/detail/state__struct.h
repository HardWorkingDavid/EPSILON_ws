// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vehicle_msgs:msg/State.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__STATE__STRUCT_H_
#define VEHICLE_MSGS__MSG__DETAIL__STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'vec_position'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/State in the package vehicle_msgs.
typedef struct vehicle_msgs__msg__State
{
  std_msgs__msg__Header header;
  geometry_msgs__msg__Point vec_position;
  double angle;
  double curvature;
  double velocity;
  double acceleration;
  double steer;
} vehicle_msgs__msg__State;

// Struct for a sequence of vehicle_msgs__msg__State.
typedef struct vehicle_msgs__msg__State__Sequence
{
  vehicle_msgs__msg__State * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vehicle_msgs__msg__State__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VEHICLE_MSGS__MSG__DETAIL__STATE__STRUCT_H_
