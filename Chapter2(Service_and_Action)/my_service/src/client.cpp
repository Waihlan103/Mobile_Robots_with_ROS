#include "ros/ros.h"
#include "my_service/whk.h"

int main(int argc, char **argv)
{
	ros::init(argc, argv, "add_three_integer");
	ros::NodeHandle nh;
	ros::ServiceClient client = nh.serviceClient<my_service::whk>("add_3_ints");

	my_service::whk whk_srv;
	whk_srv.request.A = 1;
	whk_srv.request.B = 2;
	whk_srv.request.C = 3;

	if(client.call(whk_srv))
	{
		ROS_INFO("Sum : %d ", (int)whk_srv.response.sum);
	}
	else
	{
		ROS_ERROR("Failed to call add three integer");
		return 1;
	}
	return 0;
}