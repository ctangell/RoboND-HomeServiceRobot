#!/bin/sh
export TURTLEBOT_GAZEBO_WORLD_FILE=$(rospack find wall_follower)/../World/my_world.world
xterm  -e  "roslaunch turtlebot_gazebo turtlebot_world.launch " &
sleep 5
export TURTLEBOT_GAZEBO_MAP_FILE=$(rospack find wall_follower)/../World/my_world.yaml
xterm -e " roslaunch turtlebot_gazebo amcl_demo.launch" &
sleep 5
xterm -e " roslaunch turtlebot_rviz_launchers view_navigation.launch " &
