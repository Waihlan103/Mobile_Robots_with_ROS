#include "ros/ros.h"

int main(int argc, char ** argv)
{
	/* code */
	ros::init(argc, argv, "param_test");
	ros::NodeHandle nh("~");

	std::string value;

	nh.setParam("my_param", "Hello there");
	if (nh.getParam("my_param", value))
	{
		/* code */
		ROS_INFO("param = [%s]", value.c_str());
	}

	ros::param::set("your_param", "Hello World");
	std::string value2;
	ros::param::get("your_param", value2);

	ROS_INFO("param2 = [%s]", value2.c_str());
	
	ros::waitForShutdown();
}