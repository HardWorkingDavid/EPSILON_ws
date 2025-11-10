// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vehicle_msgs:msg/CircleObstacle.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__CIRCLE_OBSTACLE__STRUCT_H_
#define VEHICLE_MSGS__MSG__DETAIL__CIRCLE_OBSTACLE__STRUCT_H_

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
// Member 'circle'
#include "vehicle_msgs/msg/detail/circle__struct.h"

/// Struct defined in msg/CircleObstacle in the package vehicle_msgs.
typedef struct vehicle_msgs__msg__CircleObstacle
{
  std_msgs__msg__Header header;
  int32_t id;
  vehicle_msgs__msg__Circle circle;
} vehicle_msgs__msg__CircleObstacle;

// Struct for a sequence of vehicle_msgs__msg__CircleObstacle.
typedef struct vehicle_msgs__msg__CircleObstacle__Sequence
{
  vehicle_msgs__msg__CircleObstacle * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vehicle_msgs__msg__CircleObstacle__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VEHICLE_MSGS__MSG__DETAIL__CIRCLE_OBSTACLE__STRUCT_H_
