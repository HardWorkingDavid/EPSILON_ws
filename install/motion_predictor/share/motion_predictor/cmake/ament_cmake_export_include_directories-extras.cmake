# generated from ament_cmake_export_include_directories/cmake/ament_cmake_export_include_directories-extras.cmake.in

set(_exported_include_dirs "${motion_predictor_DIR}/../../../include;/opt/ros/humble/include/rclcpp;/opt/ros/humble/include/visualization_msgs;/opt/ros/humble/include/sensor_msgs;/opt/ros/humble/include/tf2_ros;/usr/include/opencv4;/usr/include;/opt/ros/humble/include/tf2;/opt/ros/humble/include/tf2_geometry_msgs;/home/bigdavid/EPSILON_ws/install/common/include;/home/bigdavid/EPSILON_ws/src/core/common/thirdparty;/usr/local/include/eigen3;/usr/local/include;/home/bigdavid/EPSILON_ws/src/core/common/thirdparty/OOQP/include;/opt/ros/humble/include/rcl_interfaces;/opt/ros/humble/include/rclcpp_components;/opt/ros/humble/include/builtin_interfaces;/opt/ros/humble/include/geometry_msgs;/opt/ros/humble/include/message_filters;/opt/ros/humble/include/rclcpp_action;/opt/ros/humble/include/tf2_msgs;/home/bigdavid/EPSILON_ws/install/vehicle_model/include;/home/bigdavid/EPSILON_ws/src/core/vehicle_model/thirdparty;/home/bigdavid/EPSILON_ws/install/forward_simulator/include")

# append include directories to motion_predictor_INCLUDE_DIRS
# warn about not existing paths
if(NOT _exported_include_dirs STREQUAL "")
  find_package(ament_cmake_core QUIET REQUIRED)
  foreach(_exported_include_dir ${_exported_include_dirs})
    if(NOT IS_DIRECTORY "${_exported_include_dir}")
      message(WARNING "Package 'motion_predictor' exports the include directory '${_exported_include_dir}' which doesn't exist")
    endif()
    normalize_path(_exported_include_dir "${_exported_include_dir}")
    list(APPEND motion_predictor_INCLUDE_DIRS "${_exported_include_dir}")
  endforeach()
endif()
