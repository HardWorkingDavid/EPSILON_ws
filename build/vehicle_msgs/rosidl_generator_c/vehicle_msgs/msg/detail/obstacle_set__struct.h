// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vehicle_msgs:msg/ObstacleSet.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__OBSTACLE_SET__STRUCT_H_
#define VEHICLE_MSGS__MSG__DETAIL__OBSTACLE_SET__STRUCT_H_

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
// Member 'obs_circle'
#include "vehicle_msgs/msg/detail/circle_obstacle__struct.h"
// Member 'obs_polygon'
#include "vehicle_msgs/msg/detail/polygon_obstacle__struct.h"

/// Struct defined in msg/ObstacleSet in the package vehicle_msgs.
typedef struct vehicle_msgs__msg__ObstacleSet
{
  std_msgs__msg__Header header;
  vehicle_msgs__msg__CircleObstacle__Sequence obs_circle;
  vehicle_msgs__msg__PolygonObstacle__Sequence obs_polygon;
} vehicle_msgs__msg__ObstacleSet;

// Struct for a sequence of vehicle_msgs__msg__ObstacleSet.
typedef struct vehicle_msgs__msg__ObstacleSet__Sequence
{
  vehicle_msgs__msg__ObstacleSet * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vehicle_msgs__msg__ObstacleSet__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VEHICLE_MSGS__MSG__DETAIL__OBSTACLE_SET__STRUCT_H_
