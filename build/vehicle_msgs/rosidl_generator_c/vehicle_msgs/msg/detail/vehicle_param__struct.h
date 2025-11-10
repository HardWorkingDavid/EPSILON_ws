// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vehicle_msgs:msg/VehicleParam.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__VEHICLE_PARAM__STRUCT_H_
#define VEHICLE_MSGS__MSG__DETAIL__VEHICLE_PARAM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/VehicleParam in the package vehicle_msgs.
/**
  * Kinematic
 */
typedef struct vehicle_msgs__msg__VehicleParam
{
  float width;
  float length;
  float wheel_base;
  float front_suspension;
  float rear_suspension;
  float max_steering_angle;
  /// Length between rear axle to center of vehicle
  float d_cr;
  /// Dynamic
  float max_longitudinal_acc;
  float max_lateral_acc;
} vehicle_msgs__msg__VehicleParam;

// Struct for a sequence of vehicle_msgs__msg__VehicleParam.
typedef struct vehicle_msgs__msg__VehicleParam__Sequence
{
  vehicle_msgs__msg__VehicleParam * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vehicle_msgs__msg__VehicleParam__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VEHICLE_MSGS__MSG__DETAIL__VEHICLE_PARAM__STRUCT_H_
