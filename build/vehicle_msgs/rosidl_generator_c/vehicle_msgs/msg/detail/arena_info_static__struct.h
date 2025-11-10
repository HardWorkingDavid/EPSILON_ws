// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vehicle_msgs:msg/ArenaInfoStatic.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__ARENA_INFO_STATIC__STRUCT_H_
#define VEHICLE_MSGS__MSG__DETAIL__ARENA_INFO_STATIC__STRUCT_H_

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
// Member 'lane_net'
#include "vehicle_msgs/msg/detail/lane_net__struct.h"
// Member 'obstacle_set'
#include "vehicle_msgs/msg/detail/obstacle_set__struct.h"

/// Struct defined in msg/ArenaInfoStatic in the package vehicle_msgs.
typedef struct vehicle_msgs__msg__ArenaInfoStatic
{
  std_msgs__msg__Header header;
  vehicle_msgs__msg__LaneNet lane_net;
  vehicle_msgs__msg__ObstacleSet obstacle_set;
} vehicle_msgs__msg__ArenaInfoStatic;

// Struct for a sequence of vehicle_msgs__msg__ArenaInfoStatic.
typedef struct vehicle_msgs__msg__ArenaInfoStatic__Sequence
{
  vehicle_msgs__msg__ArenaInfoStatic * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vehicle_msgs__msg__ArenaInfoStatic__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VEHICLE_MSGS__MSG__DETAIL__ARENA_INFO_STATIC__STRUCT_H_
