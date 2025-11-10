// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vehicle_msgs:msg/ControlSignal.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__CONTROL_SIGNAL__STRUCT_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__CONTROL_SIGNAL__STRUCT_HPP_

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
// Member 'is_openloop'
#include "std_msgs/msg/detail/bool__struct.hpp"
// Member 'state'
#include "vehicle_msgs/msg/detail/state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vehicle_msgs__msg__ControlSignal __attribute__((deprecated))
#else
# define DEPRECATED__vehicle_msgs__msg__ControlSignal __declspec(deprecated)
#endif

namespace vehicle_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ControlSignal_
{
  using Type = ControlSignal_<ContainerAllocator>;

  explicit ControlSignal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    is_openloop(_init),
    state(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->acc = 0.0;
      this->steer_rate = 0.0;
    }
  }

  explicit ControlSignal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    is_openloop(_alloc, _init),
    state(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->acc = 0.0;
      this->steer_rate = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _acc_type =
    double;
  _acc_type acc;
  using _steer_rate_type =
    double;
  _steer_rate_type steer_rate;
  using _is_openloop_type =
    std_msgs::msg::Bool_<ContainerAllocator>;
  _is_openloop_type is_openloop;
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
  Type & set__acc(
    const double & _arg)
  {
    this->acc = _arg;
    return *this;
  }
  Type & set__steer_rate(
    const double & _arg)
  {
    this->steer_rate = _arg;
    return *this;
  }
  Type & set__is_openloop(
    const std_msgs::msg::Bool_<ContainerAllocator> & _arg)
  {
    this->is_openloop = _arg;
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
    vehicle_msgs::msg::ControlSignal_<ContainerAllocator> *;
  using ConstRawPtr =
    const vehicle_msgs::msg::ControlSignal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vehicle_msgs::msg::ControlSignal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vehicle_msgs::msg::ControlSignal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vehicle_msgs::msg::ControlSignal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vehicle_msgs::msg::ControlSignal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vehicle_msgs::msg::ControlSignal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vehicle_msgs::msg::ControlSignal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vehicle_msgs::msg::ControlSignal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vehicle_msgs::msg::ControlSignal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vehicle_msgs__msg__ControlSignal
    std::shared_ptr<vehicle_msgs::msg::ControlSignal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vehicle_msgs__msg__ControlSignal
    std::shared_ptr<vehicle_msgs::msg::ControlSignal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ControlSignal_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->acc != other.acc) {
      return false;
    }
    if (this->steer_rate != other.steer_rate) {
      return false;
    }
    if (this->is_openloop != other.is_openloop) {
      return false;
    }
    if (this->state != other.state) {
      return false;
    }
    return true;
  }
  bool operator!=(const ControlSignal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ControlSignal_

// alias to use template instance with default allocator
using ControlSignal =
  vehicle_msgs::msg::ControlSignal_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vehicle_msgs

#endif  // VEHICLE_MSGS__MSG__DETAIL__CONTROL_SIGNAL__STRUCT_HPP_
