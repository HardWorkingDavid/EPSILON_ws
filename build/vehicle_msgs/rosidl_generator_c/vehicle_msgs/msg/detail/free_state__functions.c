// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vehicle_msgs:msg/FreeState.idl
// generated code does not contain a copyright notice
#include "vehicle_msgs/msg/detail/free_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `pos`
// Member `vel`
// Member `acc`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
vehicle_msgs__msg__FreeState__init(vehicle_msgs__msg__FreeState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    vehicle_msgs__msg__FreeState__fini(msg);
    return false;
  }
  // pos
  if (!geometry_msgs__msg__Point__init(&msg->pos)) {
    vehicle_msgs__msg__FreeState__fini(msg);
    return false;
  }
  // vel
  if (!geometry_msgs__msg__Point__init(&msg->vel)) {
    vehicle_msgs__msg__FreeState__fini(msg);
    return false;
  }
  // acc
  if (!geometry_msgs__msg__Point__init(&msg->acc)) {
    vehicle_msgs__msg__FreeState__fini(msg);
    return false;
  }
  // angle
  return true;
}

void
vehicle_msgs__msg__FreeState__fini(vehicle_msgs__msg__FreeState * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // pos
  geometry_msgs__msg__Point__fini(&msg->pos);
  // vel
  geometry_msgs__msg__Point__fini(&msg->vel);
  // acc
  geometry_msgs__msg__Point__fini(&msg->acc);
  // angle
}

bool
vehicle_msgs__msg__FreeState__are_equal(const vehicle_msgs__msg__FreeState * lhs, const vehicle_msgs__msg__FreeState * rhs)
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
  // pos
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->pos), &(rhs->pos)))
  {
    return false;
  }
  // vel
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->vel), &(rhs->vel)))
  {
    return false;
  }
  // acc
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->acc), &(rhs->acc)))
  {
    return false;
  }
  // angle
  if (lhs->angle != rhs->angle) {
    return false;
  }
  return true;
}

bool
vehicle_msgs__msg__FreeState__copy(
  const vehicle_msgs__msg__FreeState * input,
  vehicle_msgs__msg__FreeState * output)
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
  // pos
  if (!geometry_msgs__msg__Point__copy(
      &(input->pos), &(output->pos)))
  {
    return false;
  }
  // vel
  if (!geometry_msgs__msg__Point__copy(
      &(input->vel), &(output->vel)))
  {
    return false;
  }
  // acc
  if (!geometry_msgs__msg__Point__copy(
      &(input->acc), &(output->acc)))
  {
    return false;
  }
  // angle
  output->angle = input->angle;
  return true;
}

vehicle_msgs__msg__FreeState *
vehicle_msgs__msg__FreeState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vehicle_msgs__msg__FreeState * msg = (vehicle_msgs__msg__FreeState *)allocator.allocate(sizeof(vehicle_msgs__msg__FreeState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vehicle_msgs__msg__FreeState));
  bool success = vehicle_msgs__msg__FreeState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vehicle_msgs__msg__FreeState__destroy(vehicle_msgs__msg__FreeState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vehicle_msgs__msg__FreeState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vehicle_msgs__msg__FreeState__Sequence__init(vehicle_msgs__msg__FreeState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vehicle_msgs__msg__FreeState * data = NULL;

  if (size) {
    data = (vehicle_msgs__msg__FreeState *)allocator.zero_allocate(size, sizeof(vehicle_msgs__msg__FreeState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vehicle_msgs__msg__FreeState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vehicle_msgs__msg__FreeState__fini(&data[i - 1]);
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
vehicle_msgs__msg__FreeState__Sequence__fini(vehicle_msgs__msg__FreeState__Sequence * array)
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
      vehicle_msgs__msg__FreeState__fini(&array->data[i]);
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

vehicle_msgs__msg__FreeState__Sequence *
vehicle_msgs__msg__FreeState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vehicle_msgs__msg__FreeState__Sequence * array = (vehicle_msgs__msg__FreeState__Sequence *)allocator.allocate(sizeof(vehicle_msgs__msg__FreeState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vehicle_msgs__msg__FreeState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vehicle_msgs__msg__FreeState__Sequence__destroy(vehicle_msgs__msg__FreeState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vehicle_msgs__msg__FreeState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vehicle_msgs__msg__FreeState__Sequence__are_equal(const vehicle_msgs__msg__FreeState__Sequence * lhs, const vehicle_msgs__msg__FreeState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vehicle_msgs__msg__FreeState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vehicle_msgs__msg__FreeState__Sequence__copy(
  const vehicle_msgs__msg__FreeState__Sequence * input,
  vehicle_msgs__msg__FreeState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vehicle_msgs__msg__FreeState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vehicle_msgs__msg__FreeState * data =
      (vehicle_msgs__msg__FreeState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vehicle_msgs__msg__FreeState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vehicle_msgs__msg__FreeState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vehicle_msgs__msg__FreeState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
