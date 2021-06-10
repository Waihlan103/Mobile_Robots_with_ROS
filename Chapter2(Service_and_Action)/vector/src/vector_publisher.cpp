#include <ros/ros.h>
#include <whk/vec.h>

int main(int argc, char ** argv){
	ros::init(argc, argv, "vector_publisher");
	ros::NodeHandle n;
	ros::Publisher pub = n.advertise<whk::vec>("vec_topic", 1000);

	ros::Rate naptime(1.0);

	double counter = 0;

	whk::vec vec_msg;
	vec_msg.x.resize(3);

	vec_msg.x[0] = 1.414;
	vec_msg.x[1] = 2.71828;
	vec_msg.x[2] = 3.1416;

	vec_msg.x.push_back(counter);
	while(ros::ok())
	{
		counter += 1.0;
		pub.publish(vec_msg);
		naptime.sleep();
	}
}