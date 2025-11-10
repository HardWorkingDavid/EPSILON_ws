// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vehicle_msgs:msg/Vehicle.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vehicle_msgs/msg/detail/vehicle__rosidl_typesupport_introspection_c.h"
#include "vehicle_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vehicle_msgs/msg/detail/vehicle__functions.h"
#include "vehicle_msgs/msg/detail/vehicle__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `id`
#include "std_msgs/msg/int32.h"
// Member `id`
#include "std_msgs/msg/detail/int32__rosidl_typesupport_introspection_c.h"
// Member `subclass`
// Member `type`
#include "std_msgs/msg/string.h"
// Member `subclass`
// Member `type`
#include "std_msgs/msg/detail/string__rosidl_typesupport_introspection_c.h"
// Member `param`
#include "vehicle_msgs/msg/vehicle_param.h"
// Member `param`
#include "vehicle_msgs/msg/detail/vehicle_param__rosidl_typesupport_introspection_c.h"
// Member `state`
#include "vehicle_msgs/msg/state.h"
// Member `state`
#include "vehicle_msgs/msg/detail/state__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vehicle_msgs__msg__Vehicle__rosidl_typesupport_introspection_c__Vehicle_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vehicle_msgs__msg__Vehicle__init(message_memory);
}

void vehicle_msgs__msg__Vehicle__rosidl_typesupport_introspection_c__Vehicle_fini_function(void * message_memory)
{
  vehicle_msgs__msg__Vehicle__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember vehicle_msgs__msg__Vehicle__rosidl_typesupport_introspection_c__Vehicle_message_member_array[6] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__Vehicle, header),  // bytes offset in struct
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
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__Vehicle, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "subclass",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__Vehicle, subclass),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__Vehicle, type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "param",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__Vehicle, param),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs__msg__Vehicle, state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vehicle_msgs__msg__Vehicle__rosidl_typesupport_introspection_c__Vehicle_message_members = {
  "vehicle_msgs__msg",  // message namespace
  "Vehicle",  // message name
  6,  // number of fields
  sizeof(vehicle_msgs__msg__Vehicle),
  vehicle_msgs__msg__Vehicle__rosidl_typesupport_introspection_c__Vehicle_message_member_array,  // message members
  vehicle_msgs__msg__Vehicle__rosidl_typesupport_introspection_c__Vehicle_init_function,  // function to initialize message memory (memory has to be allocated)
  vehicle_msgs__msg__Vehicle__rosidl_typesupport_introspection_c__Vehicle_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vehicle_msgs__msg__Vehicle__rosidl_typesupport_introspection_c__Vehicle_message_type_support_handle = {
  0,
  &vehicle_msgs__msg__Vehicle__rosidl_typesupport_introspection_c__Vehicle_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vehicle_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vehicle_msgs, msg, Vehicle)() {
  vehicle_msgs__msg__Vehicle__rosidl_typesupport_introspection_c__Vehicle_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  vehicle_msgs__msg__Vehicle__rosidl_typesupport_introspection_c__Vehicle_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Int32)();
  vehicle_msgs__msg__Vehicle__rosidl_typesupport_introspection_c__Vehicle_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, String)();
  vehicle_msgs__msg__Vehicle__rosidl_typesupport_introspection_c__Vehicle_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, String)();
  vehicle_msgs__msg__Vehicle__rosidl_typesupport_introspection_c__Vehicle_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vehicle_msgs, msg, VehicleParam)();
  vehicle_msgs__msg__Vehicle__rosidl_typesupport_introspection_c__Vehicle_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vehicle_msgs, msg, State)();
  if (!vehicle_msgs__msg__Vehicle__rosidl_typesupport_introspection_c__Vehicle_message_type_support_handle.typesupport_identifier) {
    vehicle_msgs__msg__Vehicle__rosidl_typesupport_introspection_c__Vehicle_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vehicle_msgs__msg__Vehicle__rosidl_typesupport_introspection_c__Vehicle_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
