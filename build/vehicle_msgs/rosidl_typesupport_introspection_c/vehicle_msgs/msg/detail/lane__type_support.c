// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vehicle_msgs:msg/Lane.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vehicle_msgs/msg/detail/lane__rosidl_typesupport_introspection_c.h"
#include "vehicle_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vehicle_msgs/msg/detail/lane__functions.h"
#include "vehicle_msgs/msg/detail/lane__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `child_id`
// Member `father_id`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `behavior`
#include "rosidl_runtime_c/string_functions.h"
// Member `start_point`
// Member `final_point`
// Member `points`
#include "geometry_msgs/msg/point.h"
// Member `start_point`
// Member `final_point`
// Member `points`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__Lane_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vehicle_msgs__msg__Lane__init(message_memory);
}

void vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__Lane_fini_function(void * message_memory)
{
  vehicle_msgs__msg__Lane__fini(message_memory);
}

size_t vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__size_function__Lane__child_id(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__get_const_function__Lane__child_id(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__get_function__Lane__child_id(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__fetch_function__Lane__child_id(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__get_const_function__Lane__child_id(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__assign_function__Lane__child_id(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__get_function__Lane__child_id(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__resize_function__Lane__child_id(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

size_t vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__size_function__Lane__father_id(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__get_const_function__Lane__father_id(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__get_function__Lane__father_id(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__fetch_function__Lane__father_id(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__get_const_function__Lane__father_id(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__assign_function__Lane__father_id(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__get_function__Lane__father_id(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__resize_function__Lane__father_id(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

size_t vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__size_function__Lane__points(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__get_const_function__Lane__points(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__get_function__Lane__points(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__fetch_function__Lane__points(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__get_const_function__Lane__points(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__assign_function__Lane__points(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__get_function__Lane__points(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__resize_function__Lane__points(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__Lane_message_member_array[14] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__Lane, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__Lane, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "dir",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__Lane, dir),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "child_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__Lane, child_id),  // bytes offset in struct
    NULL,  // default value
    vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__size_function__Lane__child_id,  // size() function pointer
    vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__get_const_function__Lane__child_id,  // get_const(index) function pointer
    vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__get_function__Lane__child_id,  // get(index) function pointer
    vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__fetch_function__Lane__child_id,  // fetch(index, &value) function pointer
    vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__assign_function__Lane__child_id,  // assign(index, value) function pointer
    vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__resize_function__Lane__child_id  // resize(index) function pointer
  },
  {
    "father_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__Lane, father_id),  // bytes offset in struct
    NULL,  // default value
    vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__size_function__Lane__father_id,  // size() function pointer
    vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__get_const_function__Lane__father_id,  // get_const(index) function pointer
    vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__get_function__Lane__father_id,  // get(index) function pointer
    vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__fetch_function__Lane__father_id,  // fetch(index, &value) function pointer
    vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__assign_function__Lane__father_id,  // assign(index, value) function pointer
    vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__resize_function__Lane__father_id  // resize(index) function pointer
  },
  {
    "l_lane_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__Lane, l_lane_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "l_change_avbl",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__Lane, l_change_avbl),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "r_lane_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__Lane, r_lane_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "r_change_avbl",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__Lane, r_change_avbl),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "behavior",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__Lane, behavior),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "length",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__Lane, length),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "start_point",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__Lane, start_point),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "final_point",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__Lane, final_point),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "points",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__Lane, points),  // bytes offset in struct
    NULL,  // default value
    vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__size_function__Lane__points,  // size() function pointer
    vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__get_const_function__Lane__points,  // get_const(index) function pointer
    vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__get_function__Lane__points,  // get(index) function pointer
    vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__fetch_function__Lane__points,  // fetch(index, &value) function pointer
    vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__assign_function__Lane__points,  // assign(index, value) function pointer
    vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__resize_function__Lane__points  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__Lane_message_members = {
  "vehicle_msgs__msg",  // message namespace
  "Lane",  // message name
  14,  // number of fields
  sizeof(vehicle_msgs__msg__Lane),
  vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__Lane_message_member_array,  // message members
  vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__Lane_init_function,  // function to initialize message memory (memory has to be allocated)
  vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__Lane_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__Lane_message_type_support_handle = {
  0,
  &vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__Lane_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vehicle_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vehicle_msgs, msg, Lane)() {
  vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__Lane_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__Lane_message_member_array[11].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__Lane_message_member_array[12].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__Lane_message_member_array[13].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__Lane_message_type_support_handle.typesupport_identifier) {
    vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__Lane_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vehicle_msgs__msg__Lane__rosidl_typesupport_introspection_c__Lane_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
