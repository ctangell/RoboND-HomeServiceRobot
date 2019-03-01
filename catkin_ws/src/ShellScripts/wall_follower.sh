#!/bin/sh
export TURTLEBOT_GAZEBO_WORLD_FILE=$(rospack find wall_follower)/../World/my_world.world
xterm  -e  " roslaunch turtlebot_gazebo turtlebot_world.launch " &
sleep 5
xterm -e " roslaunch turtlebot_gazebo gampping.launch " &
sleep 5
xterm -e " roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 5
xterm -e " rosrun wall_follower wall_follwer_node " &