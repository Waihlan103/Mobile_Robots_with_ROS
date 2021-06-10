#include <ros/ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>
#define pi 3.147

int main(int argc,char **argv){
	ros::init(argc, argv, "forward");
	ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 10);

	geometry_msgs::Twist move;

	int rate = 10;
	float linear_velocity = 0.2;
	float linear_distance = 1;
	float angular_velocity = 0.2;
	float angular_distance = pi;
	float linear_duration, angular_duration;
	int ticks;

	linear_duration = linear_distance / linear_velocity;
	angular_duration = angular_distance / angular_velocity;

	ros::Rate r(rate);

	for(int i=0;i<2;i++){
		ticks = rate * linear_duration;
		move.linear.x = linear_velocity;
		move.angular.x = 0.0;

		for(int i=0;i<ticks;i++){
			pub.publish(move);
			r.sleep();
		}
		move.linear.x = 0.0;
		move.angular.z = 0.0;
		pub.publish(move);
		ros::Duration(1).sleep();

		ticks = rate * angular_duration;
		move.linear.x = 0.0;
		move.angular.z = angular_velocity;

		for(int i=0;i<ticks;i++){
			pub.publish(move);
			r.sleep();
		}
		move.linear.x = 0.0;
		move.angular.z = 0.0;
		pub.publish(move);
		ros::Duration(1).sleep();
	}
}