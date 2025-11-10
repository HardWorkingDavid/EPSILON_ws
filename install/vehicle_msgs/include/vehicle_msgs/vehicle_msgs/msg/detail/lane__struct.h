// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vehicle_msgs:msg/Lane.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__LANE__STRUCT_H_
#define VEHICLE_MSGS__MSG__DETAIL__LANE__STRUCT_H_

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
// Member 'child_id'
// Member 'father_id'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'behavior'
#include "rosidl_runtime_c/string.h"
// Member 'start_point'
// Member 'final_point'
// Member 'points'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/Lane in the package vehicle_msgs.
typedef struct vehicle_msgs__msg__Lane
{
  std_msgs__msg__Header header;
  int32_t id;
  int32_t dir;
  rosidl_runtime_c__int32__Sequence child_id;
  rosidl_runtime_c__int32__Sequence father_id;
  int32_t l_lane_id;
  bool l_change_avbl;
  int32_t r_lane_id;
  bool r_change_avbl;
  rosidl_runtime_c__String behavior;
  float length;
  geometry_msgs__msg__Point start_point;
  geometry_msgs__msg__Point final_point;
  geometry_msgs__msg__Point__Sequence points;
} vehicle_msgs__msg__Lane;

// Struct for a sequence of vehicle_msgs__msg__Lane.
typedef struct vehicle_msgs__msg__Lane__Sequence
{
  vehicle_msgs__msg__Lane * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vehicle_msgs__msg__Lane__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VEHICLE_MSGS__MSG__DETAIL__LANE__STRUCT_H_
