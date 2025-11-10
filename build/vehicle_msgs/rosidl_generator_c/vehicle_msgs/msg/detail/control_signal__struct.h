// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vehicle_msgs:msg/ControlSignal.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__CONTROL_SIGNAL__STRUCT_H_
#define VEHICLE_MSGS__MSG__DETAIL__CONTROL_SIGNAL__STRUCT_H_

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
// Member 'is_openloop'
#include "std_msgs/msg/detail/bool__struct.h"
// Member 'state'
#include "vehicle_msgs/msg/detail/state__struct.h"

/// Struct defined in msg/ControlSignal in the package vehicle_msgs.
typedef struct vehicle_msgs__msg__ControlSignal
{
  std_msgs__msg__Header header;
  double acc;
  double steer_rate;
  /// if open_loop is set, use the state as desired state
  /// and omit the control loop
  std_msgs__msg__Bool is_openloop;
  vehicle_msgs__msg__State state;
} vehicle_msgs__msg__ControlSignal;

// Struct for a sequence of vehicle_msgs__msg__ControlSignal.
typedef struct vehicle_msgs__msg__ControlSignal__Sequence
{
  vehicle_msgs__msg__ControlSignal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vehicle_msgs__msg__ControlSignal__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VEHICLE_MSGS__MSG__DETAIL__CONTROL_SIGNAL__STRUCT_H_
