#include <ros/ros.h>
#include <std_msgs/String.h>

void callback(const std_msgs::String::ConstPtr &msg)
{
	ROS_INFO("i HEARD [%s] ", msg->data.c_str());
}

int main(int argc, char **argv)
{
	/* code */
	ros::init(argc, argv, "subscriber_node");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("message", 1000, callback);

	ros::spin();
}