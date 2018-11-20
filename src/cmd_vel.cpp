#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <sched.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <pthread.h>
#include <math.h>
#include <sys/fcntl.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <sys/stat.h>
#include <termios.h>
#include <sys/un.h>
#include <sys/ioctl.h>
#include <errno.h>

#include "ros/ros.h"
#include "sensor_msgs/Joy.h"
#include <sensor_msgs/Imu.h>
#include "sensor_msgs/MagneticField.h"
#include "std_msgs/String.h"
#include "std_msgs/UInt8.h"
#include "geometry_msgs/Twist.h"

ros::Publisher pub;

void velCallback(const geometry_msgs::Twist::ConstPtr& msg)
{
	geometry_msgs::Twist cmd;

	cmd = *msg;
	cmd.linear.x *= -1;
	pub.publish(cmd);
	// int r = RWrite_2W_Kienmatics(msg->linear.x, msg->angular.z);
	//ROS_INFO("sub cmd [%d] : %.4f, %.4f",r, msg->linear.x, msg->angular.z);
}



int main(int argc, char **argv)
{
	ros::init(argc, argv, "nrlab_node");

	ros::NodeHandle n;
	ros::Subscriber cmd_sub = n.subscribe("/cmd_vel2", 1000, velCallback);
	pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);



	ros::Rate loop_rate(100);
	


	while(ros::ok())
	{
		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}




