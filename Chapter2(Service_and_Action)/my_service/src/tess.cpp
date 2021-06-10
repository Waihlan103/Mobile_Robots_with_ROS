#include "ros/ros.h"
#include "my_service/whk.h"
#include <cstdlib>

int main(int argc, char **argv)
{
	/* code */
	ros::init(argc, argv, "Tess_node");
	if(argc != 4)
	{
		ROS_INFO("Usage:Tess_node <int32> <int32> <int32>");

		return 1;
	}
	ros::NodeHandle nh;
	ros::ServiceClient client = nh.serviceClient<my_service::whk>("add_3_ints");

	my_service::whk srv;
	srv.request.A = atoll(argv[1]);
	srv.request.B = atoll(argv[2]);
	srv.request.C = atoll(argv[3]);

	if(client.call(srv)){
		ROS_INFO("Sum [%d] ", (int)srv.response.sum);
	}
	else
	{
		ROS_INFO("Failed to call service add_three_integer");
		return 1;
	}
	return 0;
}
