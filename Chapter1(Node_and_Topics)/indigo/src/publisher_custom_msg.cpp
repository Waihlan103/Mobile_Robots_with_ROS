#include "ros/ros.h"
#include "indigo/flash.h"

int main(int argc, char ** argv)
{
	ros::init(argc,argv, "publisher_custom_msg_node");
	ros::NodeHandle n;
	ros::Publisher pub = n.advertise<indigo::flash>("int_message", 1000);

	ros::Rate r (10);

	while(ros::ok())
	{
		indigo::flash msg;

		msg.A = 4;
		msg.B = 7;
		msg.C = 8;

		pub.publish(msg);

		ros::spinOnce();
		r.sleep();
	}
	return 0;
}