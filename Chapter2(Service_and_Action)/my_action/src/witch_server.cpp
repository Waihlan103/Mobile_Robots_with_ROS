#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <actionlib/server/simple_action_server.h>
#include <iostream>
#include <sstream>
#include "my_action/witchAction.h"

class DemoAction
{
protected:
	ros::NodeHandle nh;
	actionlib::SimpleActionServer<my_action::witchAction>as;

	my_action::witchFeedback feedback;
	my_action::witchResult result;

	std::string action_name;
	int goal;
	int progress;
public:
	DemoAction(std::string name) : as(
		nh,
		name,
		boost::bind(&DemoAction::executeCB, this,_1),
		false),
		action_name(name)
	{
		as.registerPreemptCallback(boost::bind(&DemoAction::preemptCB, this));
		as.start();
	}
	
	void preemptCB(){
		ROS_WARN("%s got preempted!", action_name.c_str());
		result.final_count = progress;
		as.setPreempted(result, "I got Preempted");
	}

	void executeCB(const my_action::witchGoalConstPtr &goal)
	{
		if(!as.isActive() || as.isPreemptRequested()) return;
		ros::Rate rate(5);
		ROS_INFO("%s is processing the goal %d", action_name.c_str(), goal->count);
		for(progress = 1; progress <= goal->count; progress++)
		{
			if(!ros::ok()) {
				result.final_count = progress;
				as.setAborted(result, "I failed");
				ROS_INFO("%s shutting down",action_name.c_str());
				break;
			}
			if(!as.isActive() || as.isPreemptRequested()) return;
			if(goal->count<=progress)
			{
				result.final_count = progress;
				as.setSucceeded(result);
			}
			else{
				feedback.current_count = progress;
				as.publishFeedback(feedback);
			}
			rate.sleep();
		}
	}
};

int main(int argc, char** argv)
{
	ros::init(argc, argv, "witch_server");
	ROS_INFO("starting witch action server");
	DemoAction da(ros::this_node::getName());
	ros::spin();
	return 0;
}