// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vehicle_msgs:msg/Circle.idl
// generated code does not contain a copyright notice
#include "vehicle_msgs/msg/detail/circle__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `center`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
vehicle_msgs__msg__Circle__init(vehicle_msgs__msg__Circle * msg)
{
  if (!msg) {
    return false;
  }
  // center
  if (!geometry_msgs__msg__Point__init(&msg->center)) {
    vehicle_msgs__msg__Circle__fini(msg);
    return false;
  }
  // radius
  return true;
}

void
vehicle_msgs__msg__Circle__fini(vehicle_msgs__msg__Circle * msg)
{
  if (!msg) {
    return;
  }
  // center
  geometry_msgs__msg__Point__fini(&msg->center);
  // radius
}

bool
vehicle_msgs__msg__Circle__are_equal(const vehicle_msgs__msg__Circle * lhs, const vehicle_msgs__msg__Circle * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // center
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->center), &(rhs->center)))
  {
    return false;
  }
  // radius
  if (lhs->radius != rhs->radius) {
    return false;
  }
  return true;
}

bool
vehicle_msgs__msg__Circle__copy(
  const vehicle_msgs__msg__Circle * input,
  vehicle_msgs__msg__Circle * output)
{
  if (!input || !output) {
    return false;
  }
  // center
  if (!geometry_msgs__msg__Point__copy(
      &(input->center), &(output->center)))
  {
    return false;
  }
  // radius
  output->radius = input->radius;
  return true;
}

vehicle_msgs__msg__Circle *
vehicle_msgs__msg__Circle__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vehicle_msgs__msg__Circle * msg = (vehicle_msgs__msg__Circle *)allocator.allocate(sizeof(vehicle_msgs__msg__Circle), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vehicle_msgs__msg__Circle));
  bool success = vehicle_msgs__msg__Circle__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vehicle_msgs__msg__Circle__destroy(vehicle_msgs__msg__Circle * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vehicle_msgs__msg__Circle__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vehicle_msgs__msg__Circle__Sequence__init(vehicle_msgs__msg__Circle__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vehicle_msgs__msg__Circle * data = NULL;

  if (size) {
    data = (vehicle_msgs__msg__Circle *)allocator.zero_allocate(size, sizeof(vehicle_msgs__msg__Circle), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vehicle_msgs__msg__Circle__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vehicle_msgs__msg__Circle__fini(&data[i - 1]);
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
vehicle_msgs__msg__Circle__Sequence__fini(vehicle_msgs__msg__Circle__Sequence * array)
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
      vehicle_msgs__msg__Circle__fini(&array->data[i]);
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

vehicle_msgs__msg__Circle__Sequence *
vehicle_msgs__msg__Circle__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vehicle_msgs__msg__Circle__Sequence * array = (vehicle_msgs__msg__Circle__Sequence *)allocator.allocate(sizeof(vehicle_msgs__msg__Circle__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vehicle_msgs__msg__Circle__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vehicle_msgs__msg__Circle__Sequence__destroy(vehicle_msgs__msg__Circle__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vehicle_msgs__msg__Circle__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vehicle_msgs__msg__Circle__Sequence__are_equal(const vehicle_msgs__msg__Circle__Sequence * lhs, const vehicle_msgs__msg__Circle__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vehicle_msgs__msg__Circle__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vehicle_msgs__msg__Circle__Sequence__copy(
  const vehicle_msgs__msg__Circle__Sequence * input,
  vehicle_msgs__msg__Circle__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vehicle_msgs__msg__Circle);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vehicle_msgs__msg__Circle * data =
      (vehicle_msgs__msg__Circle *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vehicle_msgs__msg__Circle__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vehicle_msgs__msg__Circle__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vehicle_msgs__msg__Circle__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
