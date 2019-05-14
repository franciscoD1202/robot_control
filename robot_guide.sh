#!/bin/bash
source /opt/ros/kinetic/setup.bash
source /home/catkin_ws/setup.bash

sudo usermod -a -G dialout $USER
sudo chmod a+rw /dev/ttyUSB0
sudo chmod a+rw /dev/ttyUSB1

 roslaunch robot_control robot_config_test.launch