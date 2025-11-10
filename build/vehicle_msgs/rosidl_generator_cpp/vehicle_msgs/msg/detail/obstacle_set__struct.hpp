// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vehicle_msgs:msg/ObstacleSet.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__OBSTACLE_SET__STRUCT_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__OBSTACLE_SET__STRUCT_HPP_

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
// Member 'obs_circle'
#include "vehicle_msgs/msg/detail/circle_obstacle__struct.hpp"
// Member 'obs_polygon'
#include "vehicle_msgs/msg/detail/polygon_obstacle__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vehicle_msgs__msg__ObstacleSet __attribute__((deprecated))
#else
# define DEPRECATED__vehicle_msgs__msg__ObstacleSet __declspec(deprecated)
#endif

namespace vehicle_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ObstacleSet_
{
  using Type = ObstacleSet_<ContainerAllocator>;

  explicit ObstacleSet_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit ObstacleSet_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _obs_circle_type =
    std::vector<vehicle_msgs::msg::CircleObstacle_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vehicle_msgs::msg::CircleObstacle_<ContainerAllocator>>>;
  _obs_circle_type obs_circle;
  using _obs_polygon_type =
    std::vector<vehicle_msgs::msg::PolygonObstacle_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vehicle_msgs::msg::PolygonObstacle_<ContainerAllocator>>>;
  _obs_polygon_type obs_polygon;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__obs_circle(
    const std::vector<vehicle_msgs::msg::CircleObstacle_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vehicle_msgs::msg::CircleObstacle_<ContainerAllocator>>> & _arg)
  {
    this->obs_circle = _arg;
    return *this;
  }
  Type & set__obs_polygon(
    const std::vector<vehicle_msgs::msg::PolygonObstacle_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vehicle_msgs::msg::PolygonObstacle_<ContainerAllocator>>> & _arg)
  {
    this->obs_polygon = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vehicle_msgs::msg::ObstacleSet_<ContainerAllocator> *;
  using ConstRawPtr =
    const vehicle_msgs::msg::ObstacleSet_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vehicle_msgs::msg::ObstacleSet_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vehicle_msgs::msg::ObstacleSet_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vehicle_msgs::msg::ObstacleSet_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vehicle_msgs::msg::ObstacleSet_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vehicle_msgs::msg::ObstacleSet_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vehicle_msgs::msg::ObstacleSet_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vehicle_msgs::msg::ObstacleSet_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vehicle_msgs::msg::ObstacleSet_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vehicle_msgs__msg__ObstacleSet
    std::shared_ptr<vehicle_msgs::msg::ObstacleSet_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vehicle_msgs__msg__ObstacleSet
    std::shared_ptr<vehicle_msgs::msg::ObstacleSet_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ObstacleSet_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->obs_circle != other.obs_circle) {
      return false;
    }
    if (this->obs_polygon != other.obs_polygon) {
      return false;
    }
    return true;
  }
  bool operator!=(const ObstacleSet_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ObstacleSet_

// alias to use template instance with default allocator
using ObstacleSet =
  vehicle_msgs::msg::ObstacleSet_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vehicle_msgs

#endif  // VEHICLE_MSGS__MSG__DETAIL__OBSTACLE_SET__STRUCT_HPP_
