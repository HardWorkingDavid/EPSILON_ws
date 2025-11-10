// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vehicle_msgs:msg/ArenaInfo.idl
// generated code does not contain a copyright notice
#include "vehicle_msgs/msg/detail/arena_info__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `lane_net`
#include "vehicle_msgs/msg/detail/lane_net__functions.h"
// Member `obstacle_set`
#include "vehicle_msgs/msg/detail/obstacle_set__functions.h"
// Member `vehicle_set`
#include "vehicle_msgs/msg/detail/vehicle_set__functions.h"

bool
vehicle_msgs__msg__ArenaInfo__init(vehicle_msgs__msg__ArenaInfo * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    vehicle_msgs__msg__ArenaInfo__fini(msg);
    return false;
  }
  // lane_net
  if (!vehicle_msgs__msg__LaneNet__init(&msg->lane_net)) {
    vehicle_msgs__msg__ArenaInfo__fini(msg);
    return false;
  }
  // obstacle_set
  if (!vehicle_msgs__msg__ObstacleSet__init(&msg->obstacle_set)) {
    vehicle_msgs__msg__ArenaInfo__fini(msg);
    return false;
  }
  // vehicle_set
  if (!vehicle_msgs__msg__VehicleSet__init(&msg->vehicle_set)) {
    vehicle_msgs__msg__ArenaInfo__fini(msg);
    return false;
  }
  return true;
}

void
vehicle_msgs__msg__ArenaInfo__fini(vehicle_msgs__msg__ArenaInfo * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // lane_net
  vehicle_msgs__msg__LaneNet__fini(&msg->lane_net);
  // obstacle_set
  vehicle_msgs__msg__ObstacleSet__fini(&msg->obstacle_set);
  // vehicle_set
  vehicle_msgs__msg__VehicleSet__fini(&msg->vehicle_set);
}

bool
vehicle_msgs__msg__ArenaInfo__are_equal(const vehicle_msgs__msg__ArenaInfo * lhs, const vehicle_msgs__msg__ArenaInfo * rhs)
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
  // lane_net
  if (!vehicle_msgs__msg__LaneNet__are_equal(
      &(lhs->lane_net), &(rhs->lane_net)))
  {
    return false;
  }
  // obstacle_set
  if (!vehicle_msgs__msg__ObstacleSet__are_equal(
      &(lhs->obstacle_set), &(rhs->obstacle_set)))
  {
    return false;
  }
  // vehicle_set
  if (!vehicle_msgs__msg__VehicleSet__are_equal(
      &(lhs->vehicle_set), &(rhs->vehicle_set)))
  {
    return false;
  }
  return true;
}

bool
vehicle_msgs__msg__ArenaInfo__copy(
  const vehicle_msgs__msg__ArenaInfo * input,
  vehicle_msgs__msg__ArenaInfo * output)
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
  // lane_net
  if (!vehicle_msgs__msg__LaneNet__copy(
      &(input->lane_net), &(output->lane_net)))
  {
    return false;
  }
  // obstacle_set
  if (!vehicle_msgs__msg__ObstacleSet__copy(
      &(input->obstacle_set), &(output->obstacle_set)))
  {
    return false;
  }
  // vehicle_set
  if (!vehicle_msgs__msg__VehicleSet__copy(
      &(input->vehicle_set), &(output->vehicle_set)))
  {
    return false;
  }
  return true;
}

vehicle_msgs__msg__ArenaInfo *
vehicle_msgs__msg__ArenaInfo__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vehicle_msgs__msg__ArenaInfo * msg = (vehicle_msgs__msg__ArenaInfo *)allocator.allocate(sizeof(vehicle_msgs__msg__ArenaInfo), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vehicle_msgs__msg__ArenaInfo));
  bool success = vehicle_msgs__msg__ArenaInfo__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vehicle_msgs__msg__ArenaInfo__destroy(vehicle_msgs__msg__ArenaInfo * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vehicle_msgs__msg__ArenaInfo__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vehicle_msgs__msg__ArenaInfo__Sequence__init(vehicle_msgs__msg__ArenaInfo__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vehicle_msgs__msg__ArenaInfo * data = NULL;

  if (size) {
    data = (vehicle_msgs__msg__ArenaInfo *)allocator.zero_allocate(size, sizeof(vehicle_msgs__msg__ArenaInfo), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vehicle_msgs__msg__ArenaInfo__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vehicle_msgs__msg__ArenaInfo__fini(&data[i - 1]);
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
vehicle_msgs__msg__ArenaInfo__Sequence__fini(vehicle_msgs__msg__ArenaInfo__Sequence * array)
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
      vehicle_msgs__msg__ArenaInfo__fini(&array->data[i]);
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

vehicle_msgs__msg__ArenaInfo__Sequence *
vehicle_msgs__msg__ArenaInfo__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vehicle_msgs__msg__ArenaInfo__Sequence * array = (vehicle_msgs__msg__ArenaInfo__Sequence *)allocator.allocate(sizeof(vehicle_msgs__msg__ArenaInfo__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vehicle_msgs__msg__ArenaInfo__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vehicle_msgs__msg__ArenaInfo__Sequence__destroy(vehicle_msgs__msg__ArenaInfo__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vehicle_msgs__msg__ArenaInfo__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vehicle_msgs__msg__ArenaInfo__Sequence__are_equal(const vehicle_msgs__msg__ArenaInfo__Sequence * lhs, const vehicle_msgs__msg__ArenaInfo__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vehicle_msgs__msg__ArenaInfo__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vehicle_msgs__msg__ArenaInfo__Sequence__copy(
  const vehicle_msgs__msg__ArenaInfo__Sequence * input,
  vehicle_msgs__msg__ArenaInfo__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vehicle_msgs__msg__ArenaInfo);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vehicle_msgs__msg__ArenaInfo * data =
      (vehicle_msgs__msg__ArenaInfo *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vehicle_msgs__msg__ArenaInfo__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vehicle_msgs__msg__ArenaInfo__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vehicle_msgs__msg__ArenaInfo__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
