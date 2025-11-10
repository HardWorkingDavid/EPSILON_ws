// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vehicle_msgs:msg/Lane.idl
// generated code does not contain a copyright notice
#include "vehicle_msgs/msg/detail/lane__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `child_id`
// Member `father_id`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `behavior`
#include "rosidl_runtime_c/string_functions.h"
// Member `start_point`
// Member `final_point`
// Member `points`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
vehicle_msgs__msg__Lane__init(vehicle_msgs__msg__Lane * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    vehicle_msgs__msg__Lane__fini(msg);
    return false;
  }
  // id
  // dir
  // child_id
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->child_id, 0)) {
    vehicle_msgs__msg__Lane__fini(msg);
    return false;
  }
  // father_id
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->father_id, 0)) {
    vehicle_msgs__msg__Lane__fini(msg);
    return false;
  }
  // l_lane_id
  // l_change_avbl
  // r_lane_id
  // r_change_avbl
  // behavior
  if (!rosidl_runtime_c__String__init(&msg->behavior)) {
    vehicle_msgs__msg__Lane__fini(msg);
    return false;
  }
  // length
  // start_point
  if (!geometry_msgs__msg__Point__init(&msg->start_point)) {
    vehicle_msgs__msg__Lane__fini(msg);
    return false;
  }
  // final_point
  if (!geometry_msgs__msg__Point__init(&msg->final_point)) {
    vehicle_msgs__msg__Lane__fini(msg);
    return false;
  }
  // points
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->points, 0)) {
    vehicle_msgs__msg__Lane__fini(msg);
    return false;
  }
  return true;
}

void
vehicle_msgs__msg__Lane__fini(vehicle_msgs__msg__Lane * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // id
  // dir
  // child_id
  rosidl_runtime_c__int32__Sequence__fini(&msg->child_id);
  // father_id
  rosidl_runtime_c__int32__Sequence__fini(&msg->father_id);
  // l_lane_id
  // l_change_avbl
  // r_lane_id
  // r_change_avbl
  // behavior
  rosidl_runtime_c__String__fini(&msg->behavior);
  // length
  // start_point
  geometry_msgs__msg__Point__fini(&msg->start_point);
  // final_point
  geometry_msgs__msg__Point__fini(&msg->final_point);
  // points
  geometry_msgs__msg__Point__Sequence__fini(&msg->points);
}

bool
vehicle_msgs__msg__Lane__are_equal(const vehicle_msgs__msg__Lane * lhs, const vehicle_msgs__msg__Lane * rhs)
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
  // dir
  if (lhs->dir != rhs->dir) {
    return false;
  }
  // child_id
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->child_id), &(rhs->child_id)))
  {
    return false;
  }
  // father_id
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->father_id), &(rhs->father_id)))
  {
    return false;
  }
  // l_lane_id
  if (lhs->l_lane_id != rhs->l_lane_id) {
    return false;
  }
  // l_change_avbl
  if (lhs->l_change_avbl != rhs->l_change_avbl) {
    return false;
  }
  // r_lane_id
  if (lhs->r_lane_id != rhs->r_lane_id) {
    return false;
  }
  // r_change_avbl
  if (lhs->r_change_avbl != rhs->r_change_avbl) {
    return false;
  }
  // behavior
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->behavior), &(rhs->behavior)))
  {
    return false;
  }
  // length
  if (lhs->length != rhs->length) {
    return false;
  }
  // start_point
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->start_point), &(rhs->start_point)))
  {
    return false;
  }
  // final_point
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->final_point), &(rhs->final_point)))
  {
    return false;
  }
  // points
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->points), &(rhs->points)))
  {
    return false;
  }
  return true;
}

bool
vehicle_msgs__msg__Lane__copy(
  const vehicle_msgs__msg__Lane * input,
  vehicle_msgs__msg__Lane * output)
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
  // dir
  output->dir = input->dir;
  // child_id
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->child_id), &(output->child_id)))
  {
    return false;
  }
  // father_id
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->father_id), &(output->father_id)))
  {
    return false;
  }
  // l_lane_id
  output->l_lane_id = input->l_lane_id;
  // l_change_avbl
  output->l_change_avbl = input->l_change_avbl;
  // r_lane_id
  output->r_lane_id = input->r_lane_id;
  // r_change_avbl
  output->r_change_avbl = input->r_change_avbl;
  // behavior
  if (!rosidl_runtime_c__String__copy(
      &(input->behavior), &(output->behavior)))
  {
    return false;
  }
  // length
  output->length = input->length;
  // start_point
  if (!geometry_msgs__msg__Point__copy(
      &(input->start_point), &(output->start_point)))
  {
    return false;
  }
  // final_point
  if (!geometry_msgs__msg__Point__copy(
      &(input->final_point), &(output->final_point)))
  {
    return false;
  }
  // points
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->points), &(output->points)))
  {
    return false;
  }
  return true;
}

vehicle_msgs__msg__Lane *
vehicle_msgs__msg__Lane__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vehicle_msgs__msg__Lane * msg = (vehicle_msgs__msg__Lane *)allocator.allocate(sizeof(vehicle_msgs__msg__Lane), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vehicle_msgs__msg__Lane));
  bool success = vehicle_msgs__msg__Lane__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vehicle_msgs__msg__Lane__destroy(vehicle_msgs__msg__Lane * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vehicle_msgs__msg__Lane__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vehicle_msgs__msg__Lane__Sequence__init(vehicle_msgs__msg__Lane__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vehicle_msgs__msg__Lane * data = NULL;

  if (size) {
    data = (vehicle_msgs__msg__Lane *)allocator.zero_allocate(size, sizeof(vehicle_msgs__msg__Lane), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vehicle_msgs__msg__Lane__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vehicle_msgs__msg__Lane__fini(&data[i - 1]);
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
vehicle_msgs__msg__Lane__Sequence__fini(vehicle_msgs__msg__Lane__Sequence * array)
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
      vehicle_msgs__msg__Lane__fini(&array->data[i]);
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

vehicle_msgs__msg__Lane__Sequence *
vehicle_msgs__msg__Lane__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vehicle_msgs__msg__Lane__Sequence * array = (vehicle_msgs__msg__Lane__Sequence *)allocator.allocate(sizeof(vehicle_msgs__msg__Lane__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vehicle_msgs__msg__Lane__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vehicle_msgs__msg__Lane__Sequence__destroy(vehicle_msgs__msg__Lane__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vehicle_msgs__msg__Lane__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vehicle_msgs__msg__Lane__Sequence__are_equal(const vehicle_msgs__msg__Lane__Sequence * lhs, const vehicle_msgs__msg__Lane__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vehicle_msgs__msg__Lane__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vehicle_msgs__msg__Lane__Sequence__copy(
  const vehicle_msgs__msg__Lane__Sequence * input,
  vehicle_msgs__msg__Lane__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vehicle_msgs__msg__Lane);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vehicle_msgs__msg__Lane * data =
      (vehicle_msgs__msg__Lane *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vehicle_msgs__msg__Lane__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vehicle_msgs__msg__Lane__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vehicle_msgs__msg__Lane__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
