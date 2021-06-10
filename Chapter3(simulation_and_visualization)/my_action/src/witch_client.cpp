#include<ros/ros.h>
#include<iostream>
#include<actionlib/client/simple_action_client.h>
#include<my_action/witchAction.h>
#include<actionlib/client/terminal_state.h>

int main(int argc, char **argv)
{
	/* code */
	ros::init(argc, argv, "witch_client");
	if (argc != 3)
	{
		/* code */
		ROS_WARN("Usage: witch_client <goal> <time_to_preempt>");
		return -1;
	}
	actionlib::SimpleActionClient<my_action::witchAction> ac("witch_action", true);

	ROS_INFO("Waiting for action server ...");

	ac.waitForServer();

	my_action::witchGoal goal;

	goal.count = atoi(argv[1]);

	ROS_INFO("Sending goal %d and preempt time of %d", goal.count, atoi(argv[2]));

	ac.sendGoal(goal);

	bool status = ac.waitForResult(ros::Duration(atoi(argv[2])));

	ac.cancelGoal();

	if (status)
	{
		/* code */
		actionlib::SimpleClientGoalState state = ac.getState();

		ROS_INFO("Action finished %s", state.toString().c_str());

		ac.cancelGoal();	

	}
	else
	{
		ROS_INFO("Action did not finish before the time out");
	}
	return 0;
}