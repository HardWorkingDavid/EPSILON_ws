// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vehicle_msgs:msg/VehicleParam.idl
// generated code does not contain a copyright notice
#include "vehicle_msgs/msg/detail/vehicle_param__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
vehicle_msgs__msg__VehicleParam__init(vehicle_msgs__msg__VehicleParam * msg)
{
  if (!msg) {
    return false;
  }
  // width
  // length
  // wheel_base
  // front_suspension
  // rear_suspension
  // max_steering_angle
  // d_cr
  // max_longitudinal_acc
  // max_lateral_acc
  return true;
}

void
vehicle_msgs__msg__VehicleParam__fini(vehicle_msgs__msg__VehicleParam * msg)
{
  if (!msg) {
    return;
  }
  // width
  // length
  // wheel_base
  // front_suspension
  // rear_suspension
  // max_steering_angle
  // d_cr
  // max_longitudinal_acc
  // max_lateral_acc
}

bool
vehicle_msgs__msg__VehicleParam__are_equal(const vehicle_msgs__msg__VehicleParam * lhs, const vehicle_msgs__msg__VehicleParam * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // width
  if (lhs->width != rhs->width) {
    return false;
  }
  // length
  if (lhs->length != rhs->length) {
    return false;
  }
  // wheel_base
  if (lhs->wheel_base != rhs->wheel_base) {
    return false;
  }
  // front_suspension
  if (lhs->front_suspension != rhs->front_suspension) {
    return false;
  }
  // rear_suspension
  if (lhs->rear_suspension != rhs->rear_suspension) {
    return false;
  }
  // max_steering_angle
  if (lhs->max_steering_angle != rhs->max_steering_angle) {
    return false;
  }
  // d_cr
  if (lhs->d_cr != rhs->d_cr) {
    return false;
  }
  // max_longitudinal_acc
  if (lhs->max_longitudinal_acc != rhs->max_longitudinal_acc) {
    return false;
  }
  // max_lateral_acc
  if (lhs->max_lateral_acc != rhs->max_lateral_acc) {
    return false;
  }
  return true;
}

bool
vehicle_msgs__msg__VehicleParam__copy(
  const vehicle_msgs__msg__VehicleParam * input,
  vehicle_msgs__msg__VehicleParam * output)
{
  if (!input || !output) {
    return false;
  }
  // width
  output->width = input->width;
  // length
  output->length = input->length;
  // wheel_base
  output->wheel_base = input->wheel_base;
  // front_suspension
  output->front_suspension = input->front_suspension;
  // rear_suspension
  output->rear_suspension = input->rear_suspension;
  // max_steering_angle
  output->max_steering_angle = input->max_steering_angle;
  // d_cr
  output->d_cr = input->d_cr;
  // max_longitudinal_acc
  output->max_longitudinal_acc = input->max_longitudinal_acc;
  // max_lateral_acc
  output->max_lateral_acc = input->max_lateral_acc;
  return true;
}

vehicle_msgs__msg__VehicleParam *
vehicle_msgs__msg__VehicleParam__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vehicle_msgs__msg__VehicleParam * msg = (vehicle_msgs__msg__VehicleParam *)allocator.allocate(sizeof(vehicle_msgs__msg__VehicleParam), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vehicle_msgs__msg__VehicleParam));
  bool success = vehicle_msgs__msg__VehicleParam__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vehicle_msgs__msg__VehicleParam__destroy(vehicle_msgs__msg__VehicleParam * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vehicle_msgs__msg__VehicleParam__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vehicle_msgs__msg__VehicleParam__Sequence__init(vehicle_msgs__msg__VehicleParam__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vehicle_msgs__msg__VehicleParam * data = NULL;

  if (size) {
    data = (vehicle_msgs__msg__VehicleParam *)allocator.zero_allocate(size, sizeof(vehicle_msgs__msg__VehicleParam), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vehicle_msgs__msg__VehicleParam__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vehicle_msgs__msg__VehicleParam__fini(&data[i - 1]);
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
vehicle_msgs__msg__VehicleParam__Sequence__fini(vehicle_msgs__msg__VehicleParam__Sequence * array)
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
      vehicle_msgs__msg__VehicleParam__fini(&array->data[i]);
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

vehicle_msgs__msg__VehicleParam__Sequence *
vehicle_msgs__msg__VehicleParam__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vehicle_msgs__msg__VehicleParam__Sequence * array = (vehicle_msgs__msg__VehicleParam__Sequence *)allocator.allocate(sizeof(vehicle_msgs__msg__VehicleParam__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vehicle_msgs__msg__VehicleParam__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vehicle_msgs__msg__VehicleParam__Sequence__destroy(vehicle_msgs__msg__VehicleParam__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vehicle_msgs__msg__VehicleParam__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vehicle_msgs__msg__VehicleParam__Sequence__are_equal(const vehicle_msgs__msg__VehicleParam__Sequence * lhs, const vehicle_msgs__msg__VehicleParam__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vehicle_msgs__msg__VehicleParam__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vehicle_msgs__msg__VehicleParam__Sequence__copy(
  const vehicle_msgs__msg__VehicleParam__Sequence * input,
  vehicle_msgs__msg__VehicleParam__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vehicle_msgs__msg__VehicleParam);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vehicle_msgs__msg__VehicleParam * data =
      (vehicle_msgs__msg__VehicleParam *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vehicle_msgs__msg__VehicleParam__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vehicle_msgs__msg__VehicleParam__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vehicle_msgs__msg__VehicleParam__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
