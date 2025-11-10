// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vehicle_msgs:msg/ArenaInfoDynamic.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__ARENA_INFO_DYNAMIC__STRUCT_H_
#define VEHICLE_MSGS__MSG__DETAIL__ARENA_INFO_DYNAMIC__STRUCT_H_

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
// Member 'vehicle_set'
#include "vehicle_msgs/msg/detail/vehicle_set__struct.h"

/// Struct defined in msg/ArenaInfoDynamic in the package vehicle_msgs.
typedef struct vehicle_msgs__msg__ArenaInfoDynamic
{
  std_msgs__msg__Header header;
  vehicle_msgs__msg__VehicleSet vehicle_set;
} vehicle_msgs__msg__ArenaInfoDynamic;

// Struct for a sequence of vehicle_msgs__msg__ArenaInfoDynamic.
typedef struct vehicle_msgs__msg__ArenaInfoDynamic__Sequence
{
  vehicle_msgs__msg__ArenaInfoDynamic * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vehicle_msgs__msg__ArenaInfoDynamic__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VEHICLE_MSGS__MSG__DETAIL__ARENA_INFO_DYNAMIC__STRUCT_H_
