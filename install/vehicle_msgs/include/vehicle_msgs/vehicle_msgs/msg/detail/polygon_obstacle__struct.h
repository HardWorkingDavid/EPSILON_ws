// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vehicle_msgs:msg/PolygonObstacle.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__POLYGON_OBSTACLE__STRUCT_H_
#define VEHICLE_MSGS__MSG__DETAIL__POLYGON_OBSTACLE__STRUCT_H_

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
// Member 'polygon'
#include "geometry_msgs/msg/detail/polygon__struct.h"

/// Struct defined in msg/PolygonObstacle in the package vehicle_msgs.
typedef struct vehicle_msgs__msg__PolygonObstacle
{
  std_msgs__msg__Header header;
  int32_t id;
  geometry_msgs__msg__Polygon polygon;
} vehicle_msgs__msg__PolygonObstacle;

// Struct for a sequence of vehicle_msgs__msg__PolygonObstacle.
typedef struct vehicle_msgs__msg__PolygonObstacle__Sequence
{
  vehicle_msgs__msg__PolygonObstacle * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vehicle_msgs__msg__PolygonObstacle__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VEHICLE_MSGS__MSG__DETAIL__POLYGON_OBSTACLE__STRUCT_H_
