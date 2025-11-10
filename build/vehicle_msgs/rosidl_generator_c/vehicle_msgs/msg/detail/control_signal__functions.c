// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vehicle_msgs:msg/ControlSignal.idl
// generated code does not contain a copyright notice
#include "vehicle_msgs/msg/detail/control_signal__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `is_openloop`
#include "std_msgs/msg/detail/bool__functions.h"
// Member `state`
#include "vehicle_msgs/msg/detail/state__functions.h"

bool
vehicle_msgs__msg__ControlSignal__init(vehicle_msgs__msg__ControlSignal * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    vehicle_msgs__msg__ControlSignal__fini(msg);
    return false;
  }
  // acc
  // steer_rate
  // is_openloop
  if (!std_msgs__msg__Bool__init(&msg->is_openloop)) {
    vehicle_msgs__msg__ControlSignal__fini(msg);
    return false;
  }
  // state
  if (!vehicle_msgs__msg__State__init(&msg->state)) {
    vehicle_msgs__msg__ControlSignal__fini(msg);
    return false;
  }
  return true;
}

void
vehicle_msgs__msg__ControlSignal__fini(vehicle_msgs__msg__ControlSignal * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // acc
  // steer_rate
  // is_openloop
  std_msgs__msg__Bool__fini(&msg->is_openloop);
  // state
  vehicle_msgs__msg__State__fini(&msg->state);
}

bool
vehicle_msgs__msg__ControlSignal__are_equal(const vehicle_msgs__msg__ControlSignal * lhs, const vehicle_msgs__msg__ControlSignal * rhs)
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
  // acc
  if (lhs->acc != rhs->acc) {
    return false;
  }
  // steer_rate
  if (lhs->steer_rate != rhs->steer_rate) {
    return false;
  }
  // is_openloop
  if (!std_msgs__msg__Bool__are_equal(
      &(lhs->is_openloop), &(rhs->is_openloop)))
  {
    return false;
  }
  // state
  if (!vehicle_msgs__msg__State__are_equal(
      &(lhs->state), &(rhs->state)))
  {
    return false;
  }
  return true;
}

bool
vehicle_msgs__msg__ControlSignal__copy(
  const vehicle_msgs__msg__ControlSignal * input,
  vehicle_msgs__msg__ControlSignal * output)
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
  // acc
  output->acc = input->acc;
  // steer_rate
  output->steer_rate = input->steer_rate;
  // is_openloop
  if (!std_msgs__msg__Bool__copy(
      &(input->is_openloop), &(output->is_openloop)))
  {
    return false;
  }
  // state
  if (!vehicle_msgs__msg__State__copy(
      &(input->state), &(output->state)))
  {
    return false;
  }
  return true;
}

vehicle_msgs__msg__ControlSignal *
vehicle_msgs__msg__ControlSignal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vehicle_msgs__msg__ControlSignal * msg = (vehicle_msgs__msg__ControlSignal *)allocator.allocate(sizeof(vehicle_msgs__msg__ControlSignal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vehicle_msgs__msg__ControlSignal));
  bool success = vehicle_msgs__msg__ControlSignal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vehicle_msgs__msg__ControlSignal__destroy(vehicle_msgs__msg__ControlSignal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vehicle_msgs__msg__ControlSignal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vehicle_msgs__msg__ControlSignal__Sequence__init(vehicle_msgs__msg__ControlSignal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vehicle_msgs__msg__ControlSignal * data = NULL;

  if (size) {
    data = (vehicle_msgs__msg__ControlSignal *)allocator.zero_allocate(size, sizeof(vehicle_msgs__msg__ControlSignal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vehicle_msgs__msg__ControlSignal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vehicle_msgs__msg__ControlSignal__fini(&data[i - 1]);
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
vehicle_msgs__msg__ControlSignal__Sequence__fini(vehicle_msgs__msg__ControlSignal__Sequence * array)
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
      vehicle_msgs__msg__ControlSignal__fini(&array->data[i]);
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

vehicle_msgs__msg__ControlSignal__Sequence *
vehicle_msgs__msg__ControlSignal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vehicle_msgs__msg__ControlSignal__Sequence * array = (vehicle_msgs__msg__ControlSignal__Sequence *)allocator.allocate(sizeof(vehicle_msgs__msg__ControlSignal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vehicle_msgs__msg__ControlSignal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vehicle_msgs__msg__ControlSignal__Sequence__destroy(vehicle_msgs__msg__ControlSignal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vehicle_msgs__msg__ControlSignal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vehicle_msgs__msg__ControlSignal__Sequence__are_equal(const vehicle_msgs__msg__ControlSignal__Sequence * lhs, const vehicle_msgs__msg__ControlSignal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vehicle_msgs__msg__ControlSignal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vehicle_msgs__msg__ControlSignal__Sequence__copy(
  const vehicle_msgs__msg__ControlSignal__Sequence * input,
  vehicle_msgs__msg__ControlSignal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vehicle_msgs__msg__ControlSignal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vehicle_msgs__msg__ControlSignal * data =
      (vehicle_msgs__msg__ControlSignal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vehicle_msgs__msg__ControlSignal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vehicle_msgs__msg__ControlSignal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vehicle_msgs__msg__ControlSignal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
