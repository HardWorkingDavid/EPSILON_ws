#!/bin/bash

# 1. 新开终端启动 planner's node
# cd /home/bigdavid/EPSILON_ws
# source install/setup.bash
#ros2 launch planning_integrated test_ssc_with_eudm_ros_launch.py

gnome-terminal -- bash -c "
terminator -e 'cd /home/bigdavid/EPSILON_ws; source install/setup.bash; ros2 launch planning_integrated test_ssc_with_mpdm_ros_launch.py'
"
#gnome-terminal -- bash -c "
#terminator -e 'cd /home/bigdavid/EPSILON_ws; source install/setup.bash; ros2 launch planning_integrated test_ssc_with_eudm_ros_launch.py'
#"

sleep 1

# 2. 新开终端启动 AI agent 节点
gnome-terminal -- bash -c "
terminator -e 'cd /home/bigdavid/EPSILON_ws; source install/setup.bash; ros2 launch ai_agent_planner onlane_ai_agent_launch.py'
"

sleep 1

# 3. 新开终端启动模拟器
gnome-terminal -- bash -c "
terminator -e 'cd /home/bigdavid/EPSILON_ws; source install/setup.bash; ros2 launch phy_simulator phy_simulator_planning_launch.py'
"

sleep 1

# 4. 新开终端启动 terminal server
gnome-terminal -- bash -c "
terminator -e 'source install/setup.bash; cd /home/bigdavid/EPSILON_ws/src/EPSILON_ROS2/aux_tools/src; python3 terminal_server.py'
"

