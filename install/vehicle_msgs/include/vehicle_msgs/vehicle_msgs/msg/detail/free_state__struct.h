// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vehicle_msgs:msg/FreeState.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__FREE_STATE__STRUCT_H_
#define VEHICLE_MSGS__MSG__DETAIL__FREE_STATE__STRUCT_H_

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
// Member 'pos'
// Member 'vel'
// Member 'acc'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/FreeState in the package vehicle_msgs.
typedef struct vehicle_msgs__msg__FreeState
{
  std_msgs__msg__Header header;
  geometry_msgs__msg__Point pos;
  geometry_msgs__msg__Point vel;
  geometry_msgs__msg__Point acc;
  double angle;
} vehicle_msgs__msg__FreeState;

// Struct for a sequence of vehicle_msgs__msg__FreeState.
typedef struct vehicle_msgs__msg__FreeState__Sequence
{
  vehicle_msgs__msg__FreeState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vehicle_msgs__msg__FreeState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VEHICLE_MSGS__MSG__DETAIL__FREE_STATE__STRUCT_H_
