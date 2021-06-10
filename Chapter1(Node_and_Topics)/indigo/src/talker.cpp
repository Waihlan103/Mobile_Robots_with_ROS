#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char ** argv)
{
	ros::init(argc, argv, "talker");
	ros::NodeHandle n;
	ros::NodeHandle nh("~");
	ros::Publisher pub = n.advertise<std_msgs::String>("message", 1000);

	ros::Publisher pub1 = nh.advertise<std_msgs::String>("degree", 1000);

	ros::Rate r (10);

	while(ros::ok())
	{
		std_msgs::String msg;
		std::stringstream ss;
		ss<<"I am publisher node!";
		msg.data = ss.str();

		ROS_INFO("I sent %s", msg.data.c_str());
		pub.publish(msg);

		pub1.publish(msg);

		ros::spinOnce();
		r.sleep();
	}
	return 0;
}