# generated from ament_cmake_export_include_directories/cmake/ament_cmake_export_include_directories-extras.cmake.in

set(_exported_include_dirs "${route_planner_DIR}/../../../include;/opt/ros/humble/include/rclcpp;/opt/ros/humble/include/visualization_msgs;/opt/ros/humble/include/sensor_msgs;/opt/ros/humble/include/tf2_ros;/usr/include/opencv4;/usr/include;/opt/ros/humble/include/tf2;/opt/ros/humble/include/tf2_geometry_msgs;/home/bigdavid/EPSILON_ws/install/common/include;/home/bigdavid/EPSILON_ws/src/EPSILON_ROS2/core/common/thirdparty;/usr/local/include/eigen3;/usr/local/include;/home/bigdavid/EPSILON_ws/src/EPSILON_ROS2/core/common/thirdparty/OOQP/include;/opt/ros/humble/include/rcl_interfaces;/opt/ros/humble/include/rclcpp_components;/opt/ros/humble/include/builtin_interfaces;/opt/ros/humble/include/geometry_msgs;/opt/ros/humble/include/message_filters;/opt/ros/humble/include/rclcpp_action;/opt/ros/humble/include/tf2_msgs;/home/bigdavid/EPSILON_ws/install/vehicle_model/include;/home/bigdavid/EPSILON_ws/src/EPSILON_ROS2/core/vehicle_model/thirdparty;/home/bigdavid/EPSILON_ws/install/forward_simulator/include;/home/bigdavid/EPSILON_ws/install/motion_predictor/include;/home/bigdavid/EPSILON_ws/install/vehicle_msgs/include/vehicle_msgs;/home/bigdavid/.local/lib/python3.10/site-packages/numpy/core/include;/home/bigdavid/EPSILON_ws/install/semantic_map_manager/include;/home/bigdavid/EPSILON_ws/src/EPSILON_ROS2/core/semantic_map_manager/thirdparty;/opt/ros/humble/include/std_msgs;/opt/ros/humble/include/nav_msgs;/opt/ros/humble/include/rosidl_runtime_c;/opt/ros/humble/include/rosidl_typesupport_interface;/opt/ros/humble/include/rcutils;/opt/ros/humble/include/rosidl_runtime_cpp;/opt/ros/humble/include/rosidl_typesupport_fastrtps_c;/opt/ros/humble/include/rosidl_typesupport_fastrtps_cpp;/opt/ros/humble/include/rmw;/opt/ros/humble/include/rosidl_typesupport_c;/opt/ros/humble/include/rosidl_typesupport_cpp;/opt/ros/humble/include/rcpputils;/opt/ros/humble/include/rosidl_typesupport_introspection_c;/opt/ros/humble/include/rosidl_typesupport_introspection_cpp;/home/bigdavid/EPSILON_ws/install/vehicle_msgs/include")

# append include directories to route_planner_INCLUDE_DIRS
# warn about not existing paths
if(NOT _exported_include_dirs STREQUAL "")
  find_package(ament_cmake_core QUIET REQUIRED)
  foreach(_exported_include_dir ${_exported_include_dirs})
    if(NOT IS_DIRECTORY "${_exported_include_dir}")
      message(WARNING "Package 'route_planner' exports the include directory '${_exported_include_dir}' which doesn't exist")
    endif()
    normalize_path(_exported_include_dir "${_exported_include_dir}")
    list(APPEND route_planner_INCLUDE_DIRS "${_exported_include_dir}")
  endforeach()
endif()
