// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vehicle_msgs:msg/CircleObstacle.idl
// generated code does not contain a copyright notice
#include "vehicle_msgs/msg/detail/circle_obstacle__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `circle`
#include "vehicle_msgs/msg/detail/circle__functions.h"

bool
vehicle_msgs__msg__CircleObstacle__init(vehicle_msgs__msg__CircleObstacle * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    vehicle_msgs__msg__CircleObstacle__fini(msg);
    return false;
  }
  // id
  // circle
  if (!vehicle_msgs__msg__Circle__init(&msg->circle)) {
    vehicle_msgs__msg__CircleObstacle__fini(msg);
    return false;
  }
  return true;
}

void
vehicle_msgs__msg__CircleObstacle__fini(vehicle_msgs__msg__CircleObstacle * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // id
  // circle
  vehicle_msgs__msg__Circle__fini(&msg->circle);
}

bool
vehicle_msgs__msg__CircleObstacle__are_equal(const vehicle_msgs__msg__CircleObstacle * lhs, const vehicle_msgs__msg__CircleObstacle * rhs)
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
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // circle
  if (!vehicle_msgs__msg__Circle__are_equal(
      &(lhs->circle), &(rhs->circle)))
  {
    return false;
  }
  return true;
}

bool
vehicle_msgs__msg__CircleObstacle__copy(
  const vehicle_msgs__msg__CircleObstacle * input,
  vehicle_msgs__msg__CircleObstacle * output)
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
  // id
  output->id = input->id;
  // circle
  if (!vehicle_msgs__msg__Circle__copy(
      &(input->circle), &(output->circle)))
  {
    return false;
  }
  return true;
}

vehicle_msgs__msg__CircleObstacle *
vehicle_msgs__msg__CircleObstacle__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vehicle_msgs__msg__CircleObstacle * msg = (vehicle_msgs__msg__CircleObstacle *)allocator.allocate(sizeof(vehicle_msgs__msg__CircleObstacle), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vehicle_msgs__msg__CircleObstacle));
  bool success = vehicle_msgs__msg__CircleObstacle__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vehicle_msgs__msg__CircleObstacle__destroy(vehicle_msgs__msg__CircleObstacle * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vehicle_msgs__msg__CircleObstacle__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vehicle_msgs__msg__CircleObstacle__Sequence__init(vehicle_msgs__msg__CircleObstacle__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vehicle_msgs__msg__CircleObstacle * data = NULL;

  if (size) {
    data = (vehicle_msgs__msg__CircleObstacle *)allocator.zero_allocate(size, sizeof(vehicle_msgs__msg__CircleObstacle), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vehicle_msgs__msg__CircleObstacle__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vehicle_msgs__msg__CircleObstacle__fini(&data[i - 1]);
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
vehicle_msgs__msg__CircleObstacle__Sequence__fini(vehicle_msgs__msg__CircleObstacle__Sequence * array)
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
      vehicle_msgs__msg__CircleObstacle__fini(&array->data[i]);
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

vehicle_msgs__msg__CircleObstacle__Sequence *
vehicle_msgs__msg__CircleObstacle__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vehicle_msgs__msg__CircleObstacle__Sequence * array = (vehicle_msgs__msg__CircleObstacle__Sequence *)allocator.allocate(sizeof(vehicle_msgs__msg__CircleObstacle__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vehicle_msgs__msg__CircleObstacle__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vehicle_msgs__msg__CircleObstacle__Sequence__destroy(vehicle_msgs__msg__CircleObstacle__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vehicle_msgs__msg__CircleObstacle__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vehicle_msgs__msg__CircleObstacle__Sequence__are_equal(const vehicle_msgs__msg__CircleObstacle__Sequence * lhs, const vehicle_msgs__msg__CircleObstacle__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vehicle_msgs__msg__CircleObstacle__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vehicle_msgs__msg__CircleObstacle__Sequence__copy(
  const vehicle_msgs__msg__CircleObstacle__Sequence * input,
  vehicle_msgs__msg__CircleObstacle__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vehicle_msgs__msg__CircleObstacle);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vehicle_msgs__msg__CircleObstacle * data =
      (vehicle_msgs__msg__CircleObstacle *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vehicle_msgs__msg__CircleObstacle__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vehicle_msgs__msg__CircleObstacle__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vehicle_msgs__msg__CircleObstacle__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
