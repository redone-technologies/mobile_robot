# mobile_robot

sudo apt install ros-kinetic-turtlebot-teleop ros-kinetic-turtlebot-gazebo ros-kinetic-turtlebot-simulator -y

sudo apt-get install flex ros-kinetic-move-base-msgs ros-kinetic-mongodb-store ros-kinetic-tf2-bullet freeglut3-dev python-catkin-tools -y

sudo apt install ros-kinetic-ackermann-* ros-kinetic-controller-* ros-kinetic-control-* ros-kinetic-controller-*  ros-kinetic-gazebo-ros-control ros-kinetic-gazebo-ros-pkgs  ros-kinetic-effort-controllers  ros-kinetic-joint-state* -y




# SLAM
roslaunch mobile_robot slam.launch

rosrun gmapping slam_gmapping scan:=scan _odom_frame:=odom _base_frame:=base_footprint

rosrun map_server map_saver -f testmap


