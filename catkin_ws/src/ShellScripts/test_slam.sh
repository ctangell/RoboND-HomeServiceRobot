#!/bin/sh
xterm  -e  " roslaunch turtlebot_gazebo turtlebot_world.launch " &
sleep 5
xterm -e " roslaunch turtlebot_gazebo gampping_demo.launch " &
#xterm  -e  " source /opt/ros/kinetic/setup.bash; roscore" & 
sleep 5
xterm -e " roslaunch turtlebot_rviz_launchers view_navigation.launch " &
#xterm  -e  " rosrun rviz rviz" 
sleep 5
xterm -e " roslaunch turtlebot_teleop keyboard_teleop.launch " &