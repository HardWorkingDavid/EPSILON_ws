// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vehicle_msgs:msg/Vehicle.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__VEHICLE__STRUCT_H_
#define VEHICLE_MSGS__MSG__DETAIL__VEHICLE__STRUCT_H_

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
// Member 'id'
#include "std_msgs/msg/detail/int32__struct.h"
// Member 'subclass'
// Member 'type'
#include "std_msgs/msg/detail/string__struct.h"
// Member 'param'
#include "vehicle_msgs/msg/detail/vehicle_param__struct.h"
// Member 'state'
#include "vehicle_msgs/msg/detail/state__struct.h"

/// Struct defined in msg/Vehicle in the package vehicle_msgs.
typedef struct vehicle_msgs__msg__Vehicle
{
  std_msgs__msg__Header header;
  std_msgs__msg__Int32 id;
  std_msgs__msg__String subclass;
  std_msgs__msg__String type;
  vehicle_msgs__msg__VehicleParam param;
  vehicle_msgs__msg__State state;
} vehicle_msgs__msg__Vehicle;

// Struct for a sequence of vehicle_msgs__msg__Vehicle.
typedef struct vehicle_msgs__msg__Vehicle__Sequence
{
  vehicle_msgs__msg__Vehicle * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vehicle_msgs__msg__Vehicle__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VEHICLE_MSGS__MSG__DETAIL__VEHICLE__STRUCT_H_
