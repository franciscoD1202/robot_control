#!/bin/bash
clear
echo "Start..." 
source /opt/ros/kinetic/setup.bash
xterm -hold -e "source /home/francisco/catkin_ws/devel/setup.bash"

sudo usermod -a -G dialout $USER
sudo chmod a+rw /dev/ttyUSB0
sudo chmod a+rw /dev/ttyUSB1

ROS_MASTER_URI=http://157.253.202.241:11311

echo "Completed..."