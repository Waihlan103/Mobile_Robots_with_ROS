#include "ros/ros.h"
#include "my_service/whk.h"

bool add(my_service::whk::Request &req,
		 my_service::whk::Response &res)
{
	res.sum = req.A + req.B + req.C;
	ROS_INFO("Sent!");
	ROS_INFO("Sum is [%d] ", (int)res.sum);

	return true;
}

int main(int argc, char **argv){
	ros::init(argc, argv, "add_three_integer_server");
	ros::NodeHandle nh;
	ros::ServiceServer server = nh.advertiseService("add_3_ints", add);
	ROS_INFO("Ready to add!");
	ros::spin();

	return 0;
}