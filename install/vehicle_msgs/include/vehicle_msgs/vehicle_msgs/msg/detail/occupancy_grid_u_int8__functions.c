// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vehicle_msgs:msg/OccupancyGridUInt8.idl
// generated code does not contain a copyright notice
#include "vehicle_msgs/msg/detail/occupancy_grid_u_int8__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `origin`
#include "geometry_msgs/msg/detail/pose__functions.h"
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
vehicle_msgs__msg__OccupancyGridUInt8__init(vehicle_msgs__msg__OccupancyGridUInt8 * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    vehicle_msgs__msg__OccupancyGridUInt8__fini(msg);
    return false;
  }
  // width
  // height
  // resolution
  // origin
  if (!geometry_msgs__msg__Pose__init(&msg->origin)) {
    vehicle_msgs__msg__OccupancyGridUInt8__fini(msg);
    return false;
  }
  // data
  if (!rosidl_runtime_c__uint8__Sequence__init(&msg->data, 0)) {
    vehicle_msgs__msg__OccupancyGridUInt8__fini(msg);
    return false;
  }
  return true;
}

void
vehicle_msgs__msg__OccupancyGridUInt8__fini(vehicle_msgs__msg__OccupancyGridUInt8 * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // width
  // height
  // resolution
  // origin
  geometry_msgs__msg__Pose__fini(&msg->origin);
  // data
  rosidl_runtime_c__uint8__Sequence__fini(&msg->data);
}

bool
vehicle_msgs__msg__OccupancyGridUInt8__are_equal(const vehicle_msgs__msg__OccupancyGridUInt8 * lhs, const vehicle_msgs__msg__OccupancyGridUInt8 * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // width
  if (lhs->width != rhs->width) {
    return false;
  }
  // height
  if (lhs->height != rhs->height) {
    return false;
  }
  // resolution
  if (lhs->resolution != rhs->resolution) {
    return false;
  }
  // origin
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->origin), &(rhs->origin)))
  {
    return false;
  }
  // data
  if (!rosidl_runtime_c__uint8__Sequence__are_equal(
      &(lhs->data), &(rhs->data)))
  {
    return false;
  }
  return true;
}

bool
vehicle_msgs__msg__OccupancyGridUInt8__copy(
  const vehicle_msgs__msg__OccupancyGridUInt8 * input,
  vehicle_msgs__msg__OccupancyGridUInt8 * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // width
  output->width = input->width;
  // height
  output->height = input->height;
  // resolution
  output->resolution = input->resolution;
  // origin
  if (!geometry_msgs__msg__Pose__copy(
      &(input->origin), &(output->origin)))
  {
    return false;
  }
  // data
  if (!rosidl_runtime_c__uint8__Sequence__copy(
      &(input->data), &(output->data)))
  {
    return false;
  }
  return true;
}

vehicle_msgs__msg__OccupancyGridUInt8 *
vehicle_msgs__msg__OccupancyGridUInt8__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vehicle_msgs__msg__OccupancyGridUInt8 * msg = (vehicle_msgs__msg__OccupancyGridUInt8 *)allocator.allocate(sizeof(vehicle_msgs__msg__OccupancyGridUInt8), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vehicle_msgs__msg__OccupancyGridUInt8));
  bool success = vehicle_msgs__msg__OccupancyGridUInt8__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vehicle_msgs__msg__OccupancyGridUInt8__destroy(vehicle_msgs__msg__OccupancyGridUInt8 * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vehicle_msgs__msg__OccupancyGridUInt8__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vehicle_msgs__msg__OccupancyGridUInt8__Sequence__init(vehicle_msgs__msg__OccupancyGridUInt8__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vehicle_msgs__msg__OccupancyGridUInt8 * data = NULL;

  if (size) {
    data = (vehicle_msgs__msg__OccupancyGridUInt8 *)allocator.zero_allocate(size, sizeof(vehicle_msgs__msg__OccupancyGridUInt8), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vehicle_msgs__msg__OccupancyGridUInt8__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vehicle_msgs__msg__OccupancyGridUInt8__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
vehicle_msgs__msg__OccupancyGridUInt8__Sequence__fini(vehicle_msgs__msg__OccupancyGridUInt8__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      vehicle_msgs__msg__OccupancyGridUInt8__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

vehicle_msgs__msg__OccupancyGridUInt8__Sequence *
vehicle_msgs__msg__OccupancyGridUInt8__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vehicle_msgs__msg__OccupancyGridUInt8__Sequence * array = (vehicle_msgs__msg__OccupancyGridUInt8__Sequence *)allocator.allocate(sizeof(vehicle_msgs__msg__OccupancyGridUInt8__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vehicle_msgs__msg__OccupancyGridUInt8__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vehicle_msgs__msg__OccupancyGridUInt8__Sequence__destroy(vehicle_msgs__msg__OccupancyGridUInt8__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vehicle_msgs__msg__OccupancyGridUInt8__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vehicle_msgs__msg__OccupancyGridUInt8__Sequence__are_equal(const vehicle_msgs__msg__OccupancyGridUInt8__Sequence * lhs, const vehicle_msgs__msg__OccupancyGridUInt8__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vehicle_msgs__msg__OccupancyGridUInt8__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vehicle_msgs__msg__OccupancyGridUInt8__Sequence__copy(
  const vehicle_msgs__msg__OccupancyGridUInt8__Sequence * input,
  vehicle_msgs__msg__OccupancyGridUInt8__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vehicle_msgs__msg__OccupancyGridUInt8);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vehicle_msgs__msg__OccupancyGridUInt8 * data =
      (vehicle_msgs__msg__OccupancyGridUInt8 *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vehicle_msgs__msg__OccupancyGridUInt8__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vehicle_msgs__msg__OccupancyGridUInt8__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vehicle_msgs__msg__OccupancyGridUInt8__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
