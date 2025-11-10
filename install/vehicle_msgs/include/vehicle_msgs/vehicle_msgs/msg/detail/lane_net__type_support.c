// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vehicle_msgs:msg/LaneNet.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vehicle_msgs/msg/detail/lane_net__rosidl_typesupport_introspection_c.h"
#include "vehicle_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vehicle_msgs/msg/detail/lane_net__functions.h"
#include "vehicle_msgs/msg/detail/lane_net__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `lanes`
#include "vehicle_msgs/msg/lane.h"
// Member `lanes`
#include "vehicle_msgs/msg/detail/lane__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vehicle_msgs__msg__LaneNet__rosidl_typesupport_introspection_c__LaneNet_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vehicle_msgs__msg__LaneNet__init(message_memory);
}

void vehicle_msgs__msg__LaneNet__rosidl_typesupport_introspection_c__LaneNet_fini_function(void * message_memory)
{
  vehicle_msgs__msg__LaneNet__fini(message_memory);
}

size_t vehicle_msgs__msg__LaneNet__rosidl_typesupport_introspection_c__size_function__LaneNet__lanes(
  const void * untyped_member)
{
  const vehicle_msgs__msg__Lane__Sequence * member =
    (const vehicle_msgs__msg__Lane__Sequence *)(untyped_member);
  return member->size;
}

const void * vehicle_msgs__msg__LaneNet__rosidl_typesupport_introspection_c__get_const_function__LaneNet__lanes(
  const void * untyped_member, size_t index)
{
  const vehicle_msgs__msg__Lane__Sequence * member =
    (const vehicle_msgs__msg__Lane__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vehicle_msgs__msg__LaneNet__rosidl_typesupport_introspection_c__get_function__LaneNet__lanes(
  void * untyped_member, size_t index)
{
  vehicle_msgs__msg__Lane__Sequence * member =
    (vehicle_msgs__msg__Lane__Sequence *)(untyped_member);
  return &member->data[index];
}

void vehicle_msgs__msg__LaneNet__rosidl_typesupport_introspection_c__fetch_function__LaneNet__lanes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const vehicle_msgs__msg__Lane * item =
    ((const vehicle_msgs__msg__Lane *)
    vehicle_msgs__msg__LaneNet__rosidl_typesupport_introspection_c__get_const_function__LaneNet__lanes(untyped_member, index));
  vehicle_msgs__msg__Lane * value =
    (vehicle_msgs__msg__Lane *)(untyped_value);
  *value = *item;
}

void vehicle_msgs__msg__LaneNet__rosidl_typesupport_introspection_c__assign_function__LaneNet__lanes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  vehicle_msgs__msg__Lane * item =
    ((vehicle_msgs__msg__Lane *)
    vehicle_msgs__msg__LaneNet__rosidl_typesupport_introspection_c__get_function__LaneNet__lanes(untyped_member, index));
  const vehicle_msgs__msg__Lane * value =
    (const vehicle_msgs__msg__Lane *)(untyped_value);
  *item = *value;
}

bool vehicle_msgs__msg__LaneNet__rosidl_typesupport_introspection_c__resize_function__LaneNet__lanes(
  void * untyped_member, size_t size)
{
  vehicle_msgs__msg__Lane__Sequence * member =
    (vehicle_msgs__msg__Lane__Sequence *)(untyped_member);
  vehicle_msgs__msg__Lane__Sequence__fini(member);
  return vehicle_msgs__msg__Lane__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember vehicle_msgs__msg__LaneNet__rosidl_typesupport_introspection_c__LaneNet_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__LaneNet, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "lanes",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__LaneNet, lanes),  // bytes offset in struct
    NULL,  // default value
    vehicle_msgs__msg__LaneNet__rosidl_typesupport_introspection_c__size_function__LaneNet__lanes,  // size() function pointer
    vehicle_msgs__msg__LaneNet__rosidl_typesupport_introspection_c__get_const_function__LaneNet__lanes,  // get_const(index) function pointer
    vehicle_msgs__msg__LaneNet__rosidl_typesupport_introspection_c__get_function__LaneNet__lanes,  // get(index) function pointer
    vehicle_msgs__msg__LaneNet__rosidl_typesupport_introspection_c__fetch_function__LaneNet__lanes,  // fetch(index, &value) function pointer
    vehicle_msgs__msg__LaneNet__rosidl_typesupport_introspection_c__assign_function__LaneNet__lanes,  // assign(index, value) function pointer
    vehicle_msgs__msg__LaneNet__rosidl_typesupport_introspection_c__resize_function__LaneNet__lanes  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vehicle_msgs__msg__LaneNet__rosidl_typesupport_introspection_c__LaneNet_message_members = {
  "vehicle_msgs__msg",  // message namespace
  "LaneNet",  // message name
  2,  // number of fields
  sizeof(vehicle_msgs__msg__LaneNet),
  vehicle_msgs__msg__LaneNet__rosidl_typesupport_introspection_c__LaneNet_message_member_array,  // message members
  vehicle_msgs__msg__LaneNet__rosidl_typesupport_introspection_c__LaneNet_init_function,  // function to initialize message memory (memory has to be allocated)
  vehicle_msgs__msg__LaneNet__rosidl_typesupport_introspection_c__LaneNet_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vehicle_msgs__msg__LaneNet__rosidl_typesupport_introspection_c__LaneNet_message_type_support_handle = {
  0,
  &vehicle_msgs__msg__LaneNet__rosidl_typesupport_introspection_c__LaneNet_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vehicle_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vehicle_msgs, msg, LaneNet)() {
  vehicle_msgs__msg__LaneNet__rosidl_typesupport_introspection_c__LaneNet_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  vehicle_msgs__msg__LaneNet__rosidl_typesupport_introspection_c__LaneNet_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vehicle_msgs, msg, Lane)();
  if (!vehicle_msgs__msg__LaneNet__rosidl_typesupport_introspection_c__LaneNet_message_type_support_handle.typesupport_identifier) {
    vehicle_msgs__msg__LaneNet__rosidl_typesupport_introspection_c__LaneNet_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vehicle_msgs__msg__LaneNet__rosidl_typesupport_introspection_c__LaneNet_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
