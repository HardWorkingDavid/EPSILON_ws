// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from vehicle_msgs:msg/PolygonObstacle.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__POLYGON_OBSTACLE__FUNCTIONS_H_
#define VEHICLE_MSGS__MSG__DETAIL__POLYGON_OBSTACLE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "vehicle_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "vehicle_msgs/msg/detail/polygon_obstacle__struct.h"

/// Initialize msg/PolygonObstacle message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * vehicle_msgs__msg__PolygonObstacle
 * )) before or use
 * vehicle_msgs__msg__PolygonObstacle__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_vehicle_msgs
bool
vehicle_msgs__msg__PolygonObstacle__init(vehicle_msgs__msg__PolygonObstacle * msg);

/// Finalize msg/PolygonObstacle message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vehicle_msgs
void
vehicle_msgs__msg__PolygonObstacle__fini(vehicle_msgs__msg__PolygonObstacle * msg);

/// Create msg/PolygonObstacle message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * vehicle_msgs__msg__PolygonObstacle__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vehicle_msgs
vehicle_msgs__msg__PolygonObstacle *
vehicle_msgs__msg__PolygonObstacle__create();

/// Destroy msg/PolygonObstacle message.
/**
 * It calls
 * vehicle_msgs__msg__PolygonObstacle__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vehicle_msgs
void
vehicle_msgs__msg__PolygonObstacle__destroy(vehicle_msgs__msg__PolygonObstacle * msg);

/// Check for msg/PolygonObstacle message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vehicle_msgs
bool
vehicle_msgs__msg__PolygonObstacle__are_equal(const vehicle_msgs__msg__PolygonObstacle * lhs, const vehicle_msgs__msg__PolygonObstacle * rhs);

/// Copy a msg/PolygonObstacle message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_vehicle_msgs
bool
vehicle_msgs__msg__PolygonObstacle__copy(
  const vehicle_msgs__msg__PolygonObstacle * input,
  vehicle_msgs__msg__PolygonObstacle * output);

/// Initialize array of msg/PolygonObstacle messages.
/**
 * It allocates the memory for the number of elements and calls
 * vehicle_msgs__msg__PolygonObstacle__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_vehicle_msgs
bool
vehicle_msgs__msg__PolygonObstacle__Sequence__init(vehicle_msgs__msg__PolygonObstacle__Sequence * array, size_t size);

/// Finalize array of msg/PolygonObstacle messages.
/**
 * It calls
 * vehicle_msgs__msg__PolygonObstacle__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vehicle_msgs
void
vehicle_msgs__msg__PolygonObstacle__Sequence__fini(vehicle_msgs__msg__PolygonObstacle__Sequence * array);

/// Create array of msg/PolygonObstacle messages.
/**
 * It allocates the memory for the array and calls
 * vehicle_msgs__msg__PolygonObstacle__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vehicle_msgs
vehicle_msgs__msg__PolygonObstacle__Sequence *
vehicle_msgs__msg__PolygonObstacle__Sequence__create(size_t size);

/// Destroy array of msg/PolygonObstacle messages.
/**
 * It calls
 * vehicle_msgs__msg__PolygonObstacle__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vehicle_msgs
void
vehicle_msgs__msg__PolygonObstacle__Sequence__destroy(vehicle_msgs__msg__PolygonObstacle__Sequence * array);

/// Check for msg/PolygonObstacle message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vehicle_msgs
bool
vehicle_msgs__msg__PolygonObstacle__Sequence__are_equal(const vehicle_msgs__msg__PolygonObstacle__Sequence * lhs, const vehicle_msgs__msg__PolygonObstacle__Sequence * rhs);

/// Copy an array of msg/PolygonObstacle messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_vehicle_msgs
bool
vehicle_msgs__msg__PolygonObstacle__Sequence__copy(
  const vehicle_msgs__msg__PolygonObstacle__Sequence * input,
  vehicle_msgs__msg__PolygonObstacle__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // VEHICLE_MSGS__MSG__DETAIL__POLYGON_OBSTACLE__FUNCTIONS_H_
