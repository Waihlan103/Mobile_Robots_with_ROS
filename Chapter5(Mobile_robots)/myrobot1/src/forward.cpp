#include <ros/ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char** argv)
{
	ros::init(argc, argv, "forward");
	ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 10);

	geometry_msgs::Twist move;
	int rate = 10;
	float linear_velocity = 0.2;
	float goal_distance = 1;
	int ticks;

	move.linear.x = linear_velocity;

	ros::Rate r(rate);
	//v = s/t --> t = s/v
	float duration = goal_distance/linear_velocity;
	ticks = rate * duration;
	for (int i=0;i<ticks;i++)
	{
		pub.publish(move);
		r.sleep();
	}

	move.linear.x = 0.0;
	pub.publish(move);
	ros::Duration(1).sleep();
}