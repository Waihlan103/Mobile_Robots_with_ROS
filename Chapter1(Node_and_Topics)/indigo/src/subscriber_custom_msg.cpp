#include "ros/ros.h"
#include "indigo/flash.h"

void callback(const indigo::flash::ConstPtr &msg)
{
	ROS_INFO("I Heard [%d], [%d], [%d]", msg->A, msg->B, msg->C);
}

int main(int argc, char ** argv)
{
	ros::init(argc, argv, "subscriber_node");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("int_message", 1000, callback);

	ros::spin();

}