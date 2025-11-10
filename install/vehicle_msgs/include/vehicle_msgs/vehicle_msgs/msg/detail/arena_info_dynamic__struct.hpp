// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vehicle_msgs:msg/ArenaInfoDynamic.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__ARENA_INFO_DYNAMIC__STRUCT_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__ARENA_INFO_DYNAMIC__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'vehicle_set'
#include "vehicle_msgs/msg/detail/vehicle_set__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vehicle_msgs__msg__ArenaInfoDynamic __attribute__((deprecated))
#else
# define DEPRECATED__vehicle_msgs__msg__ArenaInfoDynamic __declspec(deprecated)
#endif

namespace vehicle_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ArenaInfoDynamic_
{
  using Type = ArenaInfoDynamic_<ContainerAllocator>;

  explicit ArenaInfoDynamic_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    vehicle_set(_init)
  {
    (void)_init;
  }

  explicit ArenaInfoDynamic_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    vehicle_set(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _vehicle_set_type =
    vehicle_msgs::msg::VehicleSet_<ContainerAllocator>;
  _vehicle_set_type vehicle_set;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__vehicle_set(
    const vehicle_msgs::msg::VehicleSet_<ContainerAllocator> & _arg)
  {
    this->vehicle_set = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vehicle_msgs::msg::ArenaInfoDynamic_<ContainerAllocator> *;
  using ConstRawPtr =
    const vehicle_msgs::msg::ArenaInfoDynamic_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vehicle_msgs::msg::ArenaInfoDynamic_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vehicle_msgs::msg::ArenaInfoDynamic_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vehicle_msgs::msg::ArenaInfoDynamic_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vehicle_msgs::msg::ArenaInfoDynamic_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vehicle_msgs::msg::ArenaInfoDynamic_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vehicle_msgs::msg::ArenaInfoDynamic_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vehicle_msgs::msg::ArenaInfoDynamic_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vehicle_msgs::msg::ArenaInfoDynamic_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vehicle_msgs__msg__ArenaInfoDynamic
    std::shared_ptr<vehicle_msgs::msg::ArenaInfoDynamic_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vehicle_msgs__msg__ArenaInfoDynamic
    std::shared_ptr<vehicle_msgs::msg::ArenaInfoDynamic_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ArenaInfoDynamic_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->vehicle_set != other.vehicle_set) {
      return false;
    }
    return true;
  }
  bool operator!=(const ArenaInfoDynamic_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ArenaInfoDynamic_

// alias to use template instance with default allocator
using ArenaInfoDynamic =
  vehicle_msgs::msg::ArenaInfoDynamic_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vehicle_msgs

#endif  // VEHICLE_MSGS__MSG__DETAIL__ARENA_INFO_DYNAMIC__STRUCT_HPP_
