# RoboND-HomeServiceRobot

This project demonstrates a simulation of a home service robot. The project has an indoor environment, then maps it with Gmapping, a SLAM package, producing a map. It then uses AMCL to locate the robot in the map, and navigates between two points. Markers are then shown on the map, first at the pickup point, and then when the robot reaches the drop off point.

The major contributions to the project are
* pick_objects node
* add_markers node
* shell scripts for starting execution
