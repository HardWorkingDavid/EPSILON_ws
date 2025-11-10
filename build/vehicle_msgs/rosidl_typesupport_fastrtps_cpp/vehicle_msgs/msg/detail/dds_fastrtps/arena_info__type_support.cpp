// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from vehicle_msgs:msg/ArenaInfo.idl
// generated code does not contain a copyright notice
#include "vehicle_msgs/msg/detail/arena_info__rosidl_typesupport_fastrtps_cpp.hpp"
#include "vehicle_msgs/msg/detail/arena_info__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs

namespace vehicle_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const vehicle_msgs::msg::LaneNet &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  vehicle_msgs::msg::LaneNet &);
size_t get_serialized_size(
  const vehicle_msgs::msg::LaneNet &,
  size_t current_alignment);
size_t
max_serialized_size_LaneNet(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace vehicle_msgs

namespace vehicle_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const vehicle_msgs::msg::ObstacleSet &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  vehicle_msgs::msg::ObstacleSet &);
size_t get_serialized_size(
  const vehicle_msgs::msg::ObstacleSet &,
  size_t current_alignment);
size_t
max_serialized_size_ObstacleSet(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace vehicle_msgs

namespace vehicle_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const vehicle_msgs::msg::VehicleSet &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  vehicle_msgs::msg::VehicleSet &);
size_t get_serialized_size(
  const vehicle_msgs::msg::VehicleSet &,
  size_t current_alignment);
size_t
max_serialized_size_VehicleSet(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace vehicle_msgs


namespace vehicle_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vehicle_msgs
cdr_serialize(
  const vehicle_msgs::msg::ArenaInfo & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: lane_net
  vehicle_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.lane_net,
    cdr);
  // Member: obstacle_set
  vehicle_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.obstacle_set,
    cdr);
  // Member: vehicle_set
  vehicle_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.vehicle_set,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vehicle_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  vehicle_msgs::msg::ArenaInfo & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: lane_net
  vehicle_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.lane_net);

  // Member: obstacle_set
  vehicle_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.obstacle_set);

  // Member: vehicle_set
  vehicle_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.vehicle_set);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vehicle_msgs
get_serialized_size(
  const vehicle_msgs::msg::ArenaInfo & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: lane_net

  current_alignment +=
    vehicle_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.lane_net, current_alignment);
  // Member: obstacle_set

  current_alignment +=
    vehicle_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.obstacle_set, current_alignment);
  // Member: vehicle_set

  current_alignment +=
    vehicle_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.vehicle_set, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vehicle_msgs
max_serialized_size_ArenaInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: lane_net
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        vehicle_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_LaneNet(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: obstacle_set
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        vehicle_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_ObstacleSet(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: vehicle_set
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        vehicle_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_VehicleSet(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = vehicle_msgs::msg::ArenaInfo;
    is_plain =
      (
      offsetof(DataType, vehicle_set) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _ArenaInfo__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const vehicle_msgs::msg::ArenaInfo *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ArenaInfo__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<vehicle_msgs::msg::ArenaInfo *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ArenaInfo__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const vehicle_msgs::msg::ArenaInfo *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ArenaInfo__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ArenaInfo(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ArenaInfo__callbacks = {
  "vehicle_msgs::msg",
  "ArenaInfo",
  _ArenaInfo__cdr_serialize,
  _ArenaInfo__cdr_deserialize,
  _ArenaInfo__get_serialized_size,
  _ArenaInfo__max_serialized_size
};

static rosidl_message_type_support_t _ArenaInfo__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ArenaInfo__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace vehicle_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_vehicle_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<vehicle_msgs::msg::ArenaInfo>()
{
  return &vehicle_msgs::msg::typesupport_fastrtps_cpp::_ArenaInfo__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vehicle_msgs, msg, ArenaInfo)() {
  return &vehicle_msgs::msg::typesupport_fastrtps_cpp::_ArenaInfo__handle;
}

#ifdef __cplusplus
}
#endif
