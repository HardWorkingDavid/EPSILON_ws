// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vehicle_msgs:msg/Lane.idl
// generated code does not contain a copyright notice

#ifndef VEHICLE_MSGS__MSG__DETAIL__LANE__STRUCT_HPP_
#define VEHICLE_MSGS__MSG__DETAIL__LANE__STRUCT_HPP_

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
// Member 'start_point'
// Member 'final_point'
// Member 'points'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vehicle_msgs__msg__Lane __attribute__((deprecated))
#else
# define DEPRECATED__vehicle_msgs__msg__Lane __declspec(deprecated)
#endif

namespace vehicle_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Lane_
{
  using Type = Lane_<ContainerAllocator>;

  explicit Lane_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    start_point(_init),
    final_point(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->dir = 0l;
      this->l_lane_id = 0l;
      this->l_change_avbl = false;
      this->r_lane_id = 0l;
      this->r_change_avbl = false;
      this->behavior = "";
      this->length = 0.0f;
    }
  }

  explicit Lane_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    behavior(_alloc),
    start_point(_alloc, _init),
    final_point(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->dir = 0l;
      this->l_lane_id = 0l;
      this->l_change_avbl = false;
      this->r_lane_id = 0l;
      this->r_change_avbl = false;
      this->behavior = "";
      this->length = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _id_type =
    int32_t;
  _id_type id;
  using _dir_type =
    int32_t;
  _dir_type dir;
  using _child_id_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _child_id_type child_id;
  using _father_id_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _father_id_type father_id;
  using _l_lane_id_type =
    int32_t;
  _l_lane_id_type l_lane_id;
  using _l_change_avbl_type =
    bool;
  _l_change_avbl_type l_change_avbl;
  using _r_lane_id_type =
    int32_t;
  _r_lane_id_type r_lane_id;
  using _r_change_avbl_type =
    bool;
  _r_change_avbl_type r_change_avbl;
  using _behavior_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _behavior_type behavior;
  using _length_type =
    float;
  _length_type length;
  using _start_point_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _start_point_type start_point;
  using _final_point_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _final_point_type final_point;
  using _points_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _points_type points;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__dir(
    const int32_t & _arg)
  {
    this->dir = _arg;
    return *this;
  }
  Type & set__child_id(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->child_id = _arg;
    return *this;
  }
  Type & set__father_id(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->father_id = _arg;
    return *this;
  }
  Type & set__l_lane_id(
    const int32_t & _arg)
  {
    this->l_lane_id = _arg;
    return *this;
  }
  Type & set__l_change_avbl(
    const bool & _arg)
  {
    this->l_change_avbl = _arg;
    return *this;
  }
  Type & set__r_lane_id(
    const int32_t & _arg)
  {
    this->r_lane_id = _arg;
    return *this;
  }
  Type & set__r_change_avbl(
    const bool & _arg)
  {
    this->r_change_avbl = _arg;
    return *this;
  }
  Type & set__behavior(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->behavior = _arg;
    return *this;
  }
  Type & set__length(
    const float & _arg)
  {
    this->length = _arg;
    return *this;
  }
  Type & set__start_point(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->start_point = _arg;
    return *this;
  }
  Type & set__final_point(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->final_point = _arg;
    return *this;
  }
  Type & set__points(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->points = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vehicle_msgs::msg::Lane_<ContainerAllocator> *;
  using ConstRawPtr =
    const vehicle_msgs::msg::Lane_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vehicle_msgs::msg::Lane_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vehicle_msgs::msg::Lane_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vehicle_msgs::msg::Lane_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vehicle_msgs::msg::Lane_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vehicle_msgs::msg::Lane_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vehicle_msgs::msg::Lane_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vehicle_msgs::msg::Lane_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vehicle_msgs::msg::Lane_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vehicle_msgs__msg__Lane
    std::shared_ptr<vehicle_msgs::msg::Lane_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vehicle_msgs__msg__Lane
    std::shared_ptr<vehicle_msgs::msg::Lane_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Lane_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->id != other.id) {
      return false;
    }
    if (this->dir != other.dir) {
      return false;
    }
    if (this->child_id != other.child_id) {
      return false;
    }
    if (this->father_id != other.father_id) {
      return false;
    }
    if (this->l_lane_id != other.l_lane_id) {
      return false;
    }
    if (this->l_change_avbl != other.l_change_avbl) {
      return false;
    }
    if (this->r_lane_id != other.r_lane_id) {
      return false;
    }
    if (this->r_change_avbl != other.r_change_avbl) {
      return false;
    }
    if (this->behavior != other.behavior) {
      return false;
    }
    if (this->length != other.length) {
      return false;
    }
    if (this->start_point != other.start_point) {
      return false;
    }
    if (this->final_point != other.final_point) {
      return false;
    }
    if (this->points != other.points) {
      return false;
    }
    return true;
  }
  bool operator!=(const Lane_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Lane_

// alias to use template instance with default allocator
using Lane =
  vehicle_msgs::msg::Lane_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vehicle_msgs

#endif  // VEHICLE_MSGS__MSG__DETAIL__LANE__STRUCT_HPP_
