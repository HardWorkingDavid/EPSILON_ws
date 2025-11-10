// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vehicle_msgs:msg/VehicleParam.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__VEHICLE_PARAM__STRUCT_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__VEHICLE_PARAM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__vehicle_msgs__msg__VehicleParam __attribute__((deprecated))
#else
# define DEPRECATED__vehicle_msgs__msg__VehicleParam __declspec(deprecated)
#endif

namespace vehicle_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VehicleParam_
{
  using Type = VehicleParam_<ContainerAllocator>;

  explicit VehicleParam_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->width = 0.0f;
      this->length = 0.0f;
      this->wheel_base = 0.0f;
      this->front_suspension = 0.0f;
      this->rear_suspension = 0.0f;
      this->max_steering_angle = 0.0f;
      this->d_cr = 0.0f;
      this->max_longitudinal_acc = 0.0f;
      this->max_lateral_acc = 0.0f;
    }
  }

  explicit VehicleParam_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->width = 0.0f;
      this->length = 0.0f;
      this->wheel_base = 0.0f;
      this->front_suspension = 0.0f;
      this->rear_suspension = 0.0f;
      this->max_steering_angle = 0.0f;
      this->d_cr = 0.0f;
      this->max_longitudinal_acc = 0.0f;
      this->max_lateral_acc = 0.0f;
    }
  }

  // field types and members
  using _width_type =
    float;
  _width_type width;
  using _length_type =
    float;
  _length_type length;
  using _wheel_base_type =
    float;
  _wheel_base_type wheel_base;
  using _front_suspension_type =
    float;
  _front_suspension_type front_suspension;
  using _rear_suspension_type =
    float;
  _rear_suspension_type rear_suspension;
  using _max_steering_angle_type =
    float;
  _max_steering_angle_type max_steering_angle;
  using _d_cr_type =
    float;
  _d_cr_type d_cr;
  using _max_longitudinal_acc_type =
    float;
  _max_longitudinal_acc_type max_longitudinal_acc;
  using _max_lateral_acc_type =
    float;
  _max_lateral_acc_type max_lateral_acc;

  // setters for named parameter idiom
  Type & set__width(
    const float & _arg)
  {
    this->width = _arg;
    return *this;
  }
  Type & set__length(
    const float & _arg)
  {
    this->length = _arg;
    return *this;
  }
  Type & set__wheel_base(
    const float & _arg)
  {
    this->wheel_base = _arg;
    return *this;
  }
  Type & set__front_suspension(
    const float & _arg)
  {
    this->front_suspension = _arg;
    return *this;
  }
  Type & set__rear_suspension(
    const float & _arg)
  {
    this->rear_suspension = _arg;
    return *this;
  }
  Type & set__max_steering_angle(
    const float & _arg)
  {
    this->max_steering_angle = _arg;
    return *this;
  }
  Type & set__d_cr(
    const float & _arg)
  {
    this->d_cr = _arg;
    return *this;
  }
  Type & set__max_longitudinal_acc(
    const float & _arg)
  {
    this->max_longitudinal_acc = _arg;
    return *this;
  }
  Type & set__max_lateral_acc(
    const float & _arg)
  {
    this->max_lateral_acc = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vehicle_msgs::msg::VehicleParam_<ContainerAllocator> *;
  using ConstRawPtr =
    const vehicle_msgs::msg::VehicleParam_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vehicle_msgs::msg::VehicleParam_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vehicle_msgs::msg::VehicleParam_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vehicle_msgs::msg::VehicleParam_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vehicle_msgs::msg::VehicleParam_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vehicle_msgs::msg::VehicleParam_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vehicle_msgs::msg::VehicleParam_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vehicle_msgs::msg::VehicleParam_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vehicle_msgs::msg::VehicleParam_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vehicle_msgs__msg__VehicleParam
    std::shared_ptr<vehicle_msgs::msg::VehicleParam_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vehicle_msgs__msg__VehicleParam
    std::shared_ptr<vehicle_msgs::msg::VehicleParam_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VehicleParam_ & other) const
  {
    if (this->width != other.width) {
      return false;
    }
    if (this->length != other.length) {
      return false;
    }
    if (this->wheel_base != other.wheel_base) {
      return false;
    }
    if (this->front_suspension != other.front_suspension) {
      return false;
    }
    if (this->rear_suspension != other.rear_suspension) {
      return false;
    }
    if (this->max_steering_angle != other.max_steering_angle) {
      return false;
    }
    if (this->d_cr != other.d_cr) {
      return false;
    }
    if (this->max_longitudinal_acc != other.max_longitudinal_acc) {
      return false;
    }
    if (this->max_lateral_acc != other.max_lateral_acc) {
      return false;
    }
    return true;
  }
  bool operator!=(const VehicleParam_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VehicleParam_

// alias to use template instance with default allocator
using VehicleParam =
  vehicle_msgs::msg::VehicleParam_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vehicle_msgs

#endif  // VEHICLE_MSGS__MSG__DETAIL__VEHICLE_PARAM__STRUCT_HPP_
