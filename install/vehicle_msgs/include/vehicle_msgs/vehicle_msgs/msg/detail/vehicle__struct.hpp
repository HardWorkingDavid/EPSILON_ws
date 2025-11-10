// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vehicle_msgs:msg/Vehicle.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__VEHICLE__STRUCT_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__VEHICLE__STRUCT_HPP_

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
// Member 'id'
#include "std_msgs/msg/detail/int32__struct.hpp"
// Member 'subclass'
// Member 'type'
#include "std_msgs/msg/detail/string__struct.hpp"
// Member 'param'
#include "vehicle_msgs/msg/detail/vehicle_param__struct.hpp"
// Member 'state'
#include "vehicle_msgs/msg/detail/state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vehicle_msgs__msg__Vehicle __attribute__((deprecated))
#else
# define DEPRECATED__vehicle_msgs__msg__Vehicle __declspec(deprecated)
#endif

namespace vehicle_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Vehicle_
{
  using Type = Vehicle_<ContainerAllocator>;

  explicit Vehicle_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    id(_init),
    subclass(_init),
    type(_init),
    param(_init),
    state(_init)
  {
    (void)_init;
  }

  explicit Vehicle_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    id(_alloc, _init),
    subclass(_alloc, _init),
    type(_alloc, _init),
    param(_alloc, _init),
    state(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _id_type =
    std_msgs::msg::Int32_<ContainerAllocator>;
  _id_type id;
  using _subclass_type =
    std_msgs::msg::String_<ContainerAllocator>;
  _subclass_type subclass;
  using _type_type =
    std_msgs::msg::String_<ContainerAllocator>;
  _type_type type;
  using _param_type =
    vehicle_msgs::msg::VehicleParam_<ContainerAllocator>;
  _param_type param;
  using _state_type =
    vehicle_msgs::msg::State_<ContainerAllocator>;
  _state_type state;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__id(
    const std_msgs::msg::Int32_<ContainerAllocator> & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__subclass(
    const std_msgs::msg::String_<ContainerAllocator> & _arg)
  {
    this->subclass = _arg;
    return *this;
  }
  Type & set__type(
    const std_msgs::msg::String_<ContainerAllocator> & _arg)
  {
    this->type = _arg;
    return *this;
  }
  Type & set__param(
    const vehicle_msgs::msg::VehicleParam_<ContainerAllocator> & _arg)
  {
    this->param = _arg;
    return *this;
  }
  Type & set__state(
    const vehicle_msgs::msg::State_<ContainerAllocator> & _arg)
  {
    this->state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vehicle_msgs::msg::Vehicle_<ContainerAllocator> *;
  using ConstRawPtr =
    const vehicle_msgs::msg::Vehicle_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vehicle_msgs::msg::Vehicle_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vehicle_msgs::msg::Vehicle_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vehicle_msgs::msg::Vehicle_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vehicle_msgs::msg::Vehicle_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vehicle_msgs::msg::Vehicle_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vehicle_msgs::msg::Vehicle_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vehicle_msgs::msg::Vehicle_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vehicle_msgs::msg::Vehicle_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vehicle_msgs__msg__Vehicle
    std::shared_ptr<vehicle_msgs::msg::Vehicle_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vehicle_msgs__msg__Vehicle
    std::shared_ptr<vehicle_msgs::msg::Vehicle_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Vehicle_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->id != other.id) {
      return false;
    }
    if (this->subclass != other.subclass) {
      return false;
    }
    if (this->type != other.type) {
      return false;
    }
    if (this->param != other.param) {
      return false;
    }
    if (this->state != other.state) {
      return false;
    }
    return true;
  }
  bool operator!=(const Vehicle_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Vehicle_

// alias to use template instance with default allocator
using Vehicle =
  vehicle_msgs::msg::Vehicle_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vehicle_msgs

#endif  // VEHICLE_MSGS__MSG__DETAIL__VEHICLE__STRUCT_HPP_
