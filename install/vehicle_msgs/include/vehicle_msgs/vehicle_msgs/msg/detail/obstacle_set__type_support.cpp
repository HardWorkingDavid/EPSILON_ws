// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from vehicle_msgs:msg/ObstacleSet.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "vehicle_msgs/msg/detail/obstacle_set__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace vehicle_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ObstacleSet_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) vehicle_msgs::msg::ObstacleSet(_init);
}

void ObstacleSet_fini_function(void * message_memory)
{
  auto typed_message = static_cast<vehicle_msgs::msg::ObstacleSet *>(message_memory);
  typed_message->~ObstacleSet();
}

size_t size_function__ObstacleSet__obs_circle(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<vehicle_msgs::msg::CircleObstacle> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ObstacleSet__obs_circle(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<vehicle_msgs::msg::CircleObstacle> *>(untyped_member);
  return &member[index];
}

void * get_function__ObstacleSet__obs_circle(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<vehicle_msgs::msg::CircleObstacle> *>(untyped_member);
  return &member[index];
}

void fetch_function__ObstacleSet__obs_circle(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const vehicle_msgs::msg::CircleObstacle *>(
    get_const_function__ObstacleSet__obs_circle(untyped_member, index));
  auto & value = *reinterpret_cast<vehicle_msgs::msg::CircleObstacle *>(untyped_value);
  value = item;
}

void assign_function__ObstacleSet__obs_circle(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<vehicle_msgs::msg::CircleObstacle *>(
    get_function__ObstacleSet__obs_circle(untyped_member, index));
  const auto & value = *reinterpret_cast<const vehicle_msgs::msg::CircleObstacle *>(untyped_value);
  item = value;
}

void resize_function__ObstacleSet__obs_circle(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<vehicle_msgs::msg::CircleObstacle> *>(untyped_member);
  member->resize(size);
}

size_t size_function__ObstacleSet__obs_polygon(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<vehicle_msgs::msg::PolygonObstacle> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ObstacleSet__obs_polygon(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<vehicle_msgs::msg::PolygonObstacle> *>(untyped_member);
  return &member[index];
}

void * get_function__ObstacleSet__obs_polygon(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<vehicle_msgs::msg::PolygonObstacle> *>(untyped_member);
  return &member[index];
}

void fetch_function__ObstacleSet__obs_polygon(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const vehicle_msgs::msg::PolygonObstacle *>(
    get_const_function__ObstacleSet__obs_polygon(untyped_member, index));
  auto & value = *reinterpret_cast<vehicle_msgs::msg::PolygonObstacle *>(untyped_value);
  value = item;
}

void assign_function__ObstacleSet__obs_polygon(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<vehicle_msgs::msg::PolygonObstacle *>(
    get_function__ObstacleSet__obs_polygon(untyped_member, index));
  const auto & value = *reinterpret_cast<const vehicle_msgs::msg::PolygonObstacle *>(untyped_value);
  item = value;
}

void resize_function__ObstacleSet__obs_polygon(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<vehicle_msgs::msg::PolygonObstacle> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ObstacleSet_message_member_array[3] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs::msg::ObstacleSet, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "obs_circle",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vehicle_msgs::msg::CircleObstacle>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs::msg::ObstacleSet, obs_circle),  // bytes offset in struct
    nullptr,  // default value
    size_function__ObstacleSet__obs_circle,  // size() function pointer
    get_const_function__ObstacleSet__obs_circle,  // get_const(index) function pointer
    get_function__ObstacleSet__obs_circle,  // get(index) function pointer
    fetch_function__ObstacleSet__obs_circle,  // fetch(index, &value) function pointer
    assign_function__ObstacleSet__obs_circle,  // assign(index, value) function pointer
    resize_function__ObstacleSet__obs_circle  // resize(index) function pointer
  },
  {
    "obs_polygon",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vehicle_msgs::msg::PolygonObstacle>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vehicle_msgs::msg::ObstacleSet, obs_polygon),  // bytes offset in struct
    nullptr,  // default value
    size_function__ObstacleSet__obs_polygon,  // size() function pointer
    get_const_function__ObstacleSet__obs_polygon,  // get_const(index) function pointer
    get_function__ObstacleSet__obs_polygon,  // get(index) function pointer
    fetch_function__ObstacleSet__obs_polygon,  // fetch(index, &value) function pointer
    assign_function__ObstacleSet__obs_polygon,  // assign(index, value) function pointer
    resize_function__ObstacleSet__obs_polygon  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ObstacleSet_message_members = {
  "vehicle_msgs::msg",  // message namespace
  "ObstacleSet",  // message name
  3,  // number of fields
  sizeof(vehicle_msgs::msg::ObstacleSet),
  ObstacleSet_message_member_array,  // message members
  ObstacleSet_init_function,  // function to initialize message memory (memory has to be allocated)
  ObstacleSet_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ObstacleSet_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ObstacleSet_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace vehicle_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<vehicle_msgs::msg::ObstacleSet>()
{
  return &::vehicle_msgs::msg::rosidl_typesupport_introspection_cpp::ObstacleSet_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vehicle_msgs, msg, ObstacleSet)() {
  return &::vehicle_msgs::msg::rosidl_typesupport_introspection_cpp::ObstacleSet_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
