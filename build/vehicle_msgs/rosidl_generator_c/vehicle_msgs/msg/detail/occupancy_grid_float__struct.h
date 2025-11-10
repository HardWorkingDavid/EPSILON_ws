// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vehicle_msgs:msg/OccupancyGridFloat.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__OCCUPANCY_GRID_FLOAT__STRUCT_H_
#define VEHICLE_MSGS__MSG__DETAIL__OCCUPANCY_GRID_FLOAT__STRUCT_H_

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
// Member 'origin'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/OccupancyGridFloat in the package vehicle_msgs.
typedef struct vehicle_msgs__msg__OccupancyGridFloat
{
  std_msgs__msg__Header header;
  /// Map width
  uint32_t width;
  /// Map height
  uint32_t height;
  /// The map resolution
  float resolution;
  /// The origin of the map [m, m, rad].  This is the real-world pose of the
  /// cell (0,0) in the map.
  geometry_msgs__msg__Pose origin;
  /// The map data, in row-major order, starting with (0,0).  Occupancy
  /// probabilities are in the range [0,100].  Unknown is -1.
  rosidl_runtime_c__double__Sequence data;
} vehicle_msgs__msg__OccupancyGridFloat;

// Struct for a sequence of vehicle_msgs__msg__OccupancyGridFloat.
typedef struct vehicle_msgs__msg__OccupancyGridFloat__Sequence
{
  vehicle_msgs__msg__OccupancyGridFloat * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vehicle_msgs__msg__OccupancyGridFloat__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VEHICLE_MSGS__MSG__DETAIL__OCCUPANCY_GRID_FLOAT__STRUCT_H_
