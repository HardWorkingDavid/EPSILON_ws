// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vehicle_msgs:msg/ArenaInfo.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vehicle_msgs/msg/detail/arena_info__rosidl_typesupport_introspection_c.h"
#include "vehicle_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vehicle_msgs/msg/detail/arena_info__functions.h"
#include "vehicle_msgs/msg/detail/arena_info__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `lane_net`
#include "vehicle_msgs/msg/lane_net.h"
// Member `lane_net`
#include "vehicle_msgs/msg/detail/lane_net__rosidl_typesupport_introspection_c.h"
// Member `obstacle_set`
#include "vehicle_msgs/msg/obstacle_set.h"
// Member `obstacle_set`
#include "vehicle_msgs/msg/detail/obstacle_set__rosidl_typesupport_introspection_c.h"
// Member `vehicle_set`
#include "vehicle_msgs/msg/vehicle_set.h"
// Member `vehicle_set`
#include "vehicle_msgs/msg/detail/vehicle_set__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vehicle_msgs__msg__ArenaInfo__rosidl_typesupport_introspection_c__ArenaInfo_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vehicle_msgs__msg__ArenaInfo__init(message_memory);
}

void vehicle_msgs__msg__ArenaInfo__rosidl_typesupport_introspection_c__ArenaInfo_fini_function(void * message_memory)
{
  vehicle_msgs__msg__ArenaInfo__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember vehicle_msgs__msg__ArenaInfo__rosidl_typesupport_introspection_c__ArenaInfo_message_member_array[4] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__ArenaInfo, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "lane_net",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__ArenaInfo, lane_net),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "obstacle_set",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__ArenaInfo, obstacle_set),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vehicle_set",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__ArenaInfo, vehicle_set),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vehicle_msgs__msg__ArenaInfo__rosidl_typesupport_introspection_c__ArenaInfo_message_members = {
  "vehicle_msgs__msg",  // message namespace
  "ArenaInfo",  // message name
  4,  // number of fields
  sizeof(vehicle_msgs__msg__ArenaInfo),
  vehicle_msgs__msg__ArenaInfo__rosidl_typesupport_introspection_c__ArenaInfo_message_member_array,  // message members
  vehicle_msgs__msg__ArenaInfo__rosidl_typesupport_introspection_c__ArenaInfo_init_function,  // function to initialize message memory (memory has to be allocated)
  vehicle_msgs__msg__ArenaInfo__rosidl_typesupport_introspection_c__ArenaInfo_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vehicle_msgs__msg__ArenaInfo__rosidl_typesupport_introspection_c__ArenaInfo_message_type_support_handle = {
  0,
  &vehicle_msgs__msg__ArenaInfo__rosidl_typesupport_introspection_c__ArenaInfo_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vehicle_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vehicle_msgs, msg, ArenaInfo)() {
  vehicle_msgs__msg__ArenaInfo__rosidl_typesupport_introspection_c__ArenaInfo_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  vehicle_msgs__msg__ArenaInfo__rosidl_typesupport_introspection_c__ArenaInfo_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vehicle_msgs, msg, LaneNet)();
  vehicle_msgs__msg__ArenaInfo__rosidl_typesupport_introspection_c__ArenaInfo_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vehicle_msgs, msg, ObstacleSet)();
  vehicle_msgs__msg__ArenaInfo__rosidl_typesupport_introspection_c__ArenaInfo_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vehicle_msgs, msg, VehicleSet)();
  if (!vehicle_msgs__msg__ArenaInfo__rosidl_typesupport_introspection_c__ArenaInfo_message_type_support_handle.typesupport_identifier) {
    vehicle_msgs__msg__ArenaInfo__rosidl_typesupport_introspection_c__ArenaInfo_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vehicle_msgs__msg__ArenaInfo__rosidl_typesupport_introspection_c__ArenaInfo_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
