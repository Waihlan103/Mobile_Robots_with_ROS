#include <ros/ros.h>
#include <std_msgs/Float64.h>

void callback(const std_msgs::Float64& msg)
{
	ROS_INFO("Received = [%f]", msg.data);
}

int main(int argc, char **argv){
	ros::init(argc, argv, "minimal_subscriber");
	ros::NodeHandle h;
	ros::Subscriber sub = h.subscribe("topic1", 1, callback);

	ros::spin();
	return 0;
}