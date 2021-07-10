#! /usr/bin/env python

import rospy
import actionlib
from my_action.msg import witchAction, witchGoal

if __name__ == '__main__':
	rospy.init_node('witch_client')
	client = actionlib.SimpleActionClient('witch_client', witchAction)
	client.wait_for_server()

	goal = witchGoal()
	goal.count = 1000
	client.send_goal(goal)
	client.wair_for_result(rospy.Duration.from_sec(50.0))