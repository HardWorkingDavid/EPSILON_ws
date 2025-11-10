// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vehicle_msgs:msg/OccupancyGridUInt8.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vehicle_msgs/msg/detail/occupancy_grid_u_int8__rosidl_typesupport_introspection_c.h"
#include "vehicle_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vehicle_msgs/msg/detail/occupancy_grid_u_int8__functions.h"
#include "vehicle_msgs/msg/detail/occupancy_grid_u_int8__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `origin`
#include "geometry_msgs/msg/pose.h"
// Member `origin`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vehicle_msgs__msg__OccupancyGridUInt8__rosidl_typesupport_introspection_c__OccupancyGridUInt8_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vehicle_msgs__msg__OccupancyGridUInt8__init(message_memory);
}

void vehicle_msgs__msg__OccupancyGridUInt8__rosidl_typesupport_introspection_c__OccupancyGridUInt8_fini_function(void * message_memory)
{
  vehicle_msgs__msg__OccupancyGridUInt8__fini(message_memory);
}

size_t vehicle_msgs__msg__OccupancyGridUInt8__rosidl_typesupport_introspection_c__size_function__OccupancyGridUInt8__data(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return member->size;
}

const void * vehicle_msgs__msg__OccupancyGridUInt8__rosidl_typesupport_introspection_c__get_const_function__OccupancyGridUInt8__data(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vehicle_msgs__msg__OccupancyGridUInt8__rosidl_typesupport_introspection_c__get_function__OccupancyGridUInt8__data(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void vehicle_msgs__msg__OccupancyGridUInt8__rosidl_typesupport_introspection_c__fetch_function__OccupancyGridUInt8__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    vehicle_msgs__msg__OccupancyGridUInt8__rosidl_typesupport_introspection_c__get_const_function__OccupancyGridUInt8__data(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void vehicle_msgs__msg__OccupancyGridUInt8__rosidl_typesupport_introspection_c__assign_function__OccupancyGridUInt8__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    vehicle_msgs__msg__OccupancyGridUInt8__rosidl_typesupport_introspection_c__get_function__OccupancyGridUInt8__data(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

bool vehicle_msgs__msg__OccupancyGridUInt8__rosidl_typesupport_introspection_c__resize_function__OccupancyGridUInt8__data(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember vehicle_msgs__msg__OccupancyGridUInt8__rosidl_typesupport_introspection_c__OccupancyGridUInt8_message_member_array[6] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__OccupancyGridUInt8, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "width",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__OccupancyGridUInt8, width),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "height",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__OccupancyGridUInt8, height),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "resolution",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__OccupancyGridUInt8, resolution),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "origin",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__OccupancyGridUInt8, origin),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__OccupancyGridUInt8, data),  // bytes offset in struct
    NULL,  // default value
    vehicle_msgs__msg__OccupancyGridUInt8__rosidl_typesupport_introspection_c__size_function__OccupancyGridUInt8__data,  // size() function pointer
    vehicle_msgs__msg__OccupancyGridUInt8__rosidl_typesupport_introspection_c__get_const_function__OccupancyGridUInt8__data,  // get_const(index) function pointer
    vehicle_msgs__msg__OccupancyGridUInt8__rosidl_typesupport_introspection_c__get_function__OccupancyGridUInt8__data,  // get(index) function pointer
    vehicle_msgs__msg__OccupancyGridUInt8__rosidl_typesupport_introspection_c__fetch_function__OccupancyGridUInt8__data,  // fetch(index, &value) function pointer
    vehicle_msgs__msg__OccupancyGridUInt8__rosidl_typesupport_introspection_c__assign_function__OccupancyGridUInt8__data,  // assign(index, value) function pointer
    vehicle_msgs__msg__OccupancyGridUInt8__rosidl_typesupport_introspection_c__resize_function__OccupancyGridUInt8__data  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vehicle_msgs__msg__OccupancyGridUInt8__rosidl_typesupport_introspection_c__OccupancyGridUInt8_message_members = {
  "vehicle_msgs__msg",  // message namespace
  "OccupancyGridUInt8",  // message name
  6,  // number of fields
  sizeof(vehicle_msgs__msg__OccupancyGridUInt8),
  vehicle_msgs__msg__OccupancyGridUInt8__rosidl_typesupport_introspection_c__OccupancyGridUInt8_message_member_array,  // message members
  vehicle_msgs__msg__OccupancyGridUInt8__rosidl_typesupport_introspection_c__OccupancyGridUInt8_init_function,  // function to initialize message memory (memory has to be allocated)
  vehicle_msgs__msg__OccupancyGridUInt8__rosidl_typesupport_introspection_c__OccupancyGridUInt8_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vehicle_msgs__msg__OccupancyGridUInt8__rosidl_typesupport_introspection_c__OccupancyGridUInt8_message_type_support_handle = {
  0,
  &vehicle_msgs__msg__OccupancyGridUInt8__rosidl_typesupport_introspection_c__OccupancyGridUInt8_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vehicle_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vehicle_msgs, msg, OccupancyGridUInt8)() {
  vehicle_msgs__msg__OccupancyGridUInt8__rosidl_typesupport_introspection_c__OccupancyGridUInt8_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  vehicle_msgs__msg__OccupancyGridUInt8__rosidl_typesupport_introspection_c__OccupancyGridUInt8_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!vehicle_msgs__msg__OccupancyGridUInt8__rosidl_typesupport_introspection_c__OccupancyGridUInt8_message_type_support_handle.typesupport_identifier) {
    vehicle_msgs__msg__OccupancyGridUInt8__rosidl_typesupport_introspection_c__OccupancyGridUInt8_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vehicle_msgs__msg__OccupancyGridUInt8__rosidl_typesupport_introspection_c__OccupancyGridUInt8_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
