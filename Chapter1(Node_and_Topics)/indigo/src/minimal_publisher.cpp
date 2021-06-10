#include <ros/ros.h>
#include <std_msgs/Float64.h>

int main(int argc, char **argv)
{
	/* code */
	ros::init(argc, argv, "minimal_publisher");
	ros::NodeHandle n;
	ros::Publisher pub = n.advertise<std_msgs::Float64>("topic1", 1);

	ros::Rate r(10);

	std_msgs::Float64 float_data;
	float_data.data = 0.0;

	while (ros::ok())
	{
		float_data.data = float_data.data + 0.001;
		pub.publish(float_data);
		r.sleep();
	}
	
}