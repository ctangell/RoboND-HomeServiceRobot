#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  // Initialize the simple_navigation_goals node
  ros::init(argc, argv, "pick_objects");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  ros::Duration(5).sleep();

  move_base_msgs::MoveBaseGoal goal;

  // First goal - pickup
  // set up the frame parameters
  goal.target_pose.header.frame_id = "map";  // base_link
  goal.target_pose.header.stamp = ros::Time::now();

  // Define a position and orientation for the robot to reach
  goal.target_pose.pose.position.x = 3.75;
  goal.target_pose.pose.position.y = 8.0;
  goal.target_pose.pose.orientation.w = 1.0;

   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending goal");
  ac.sendGoal(goal);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Hooray, the base moved to the pickup point!");
  else
    ROS_INFO("The base failed to move to goal for some reason");
  
  ROS_INFO("Waiting for 5 seconds.");
  ros::Duration(5).sleep(); 
  
  // Second goal - dropoff
  // set up the frame parameters
  goal.target_pose.header.frame_id = "map";  // base_link
  goal.target_pose.header.stamp = ros::Time::now();
  
  // Define a position and orientation for the robot to reach
  goal.target_pose.pose.position.x = -3.75;
  goal.target_pose.pose.position.y = 8.0;
  goal.target_pose.pose.orientation.w = -1.0;

   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending goal");
  ac.sendGoal(goal);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Hooray, the base moved to the dropoff point!");
  else
    ROS_INFO("The base failed to move to the gaol for some reason");

  return 0;
}
