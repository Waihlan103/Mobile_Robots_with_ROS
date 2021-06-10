#include <ros/ros.h>

int main(int argc, char** argv)
{
	ros::init(argc, argv, "param_test");
	ros::NodeHandle nh;

	std::string value;

	nh.setParam("my_param", "Hello_World");
	if(nh.getParam("my_param", value))
	{
		ROS_INFO("param = %s", value.c_str());
	}

	ros::param::set("yout_param", "hello world");
	std::string value2;
	ros::param::get("yout_param", value2);

	ROS_INFO("param2 = %s", value2.c_str());

	ros::waitForShutdown();
}