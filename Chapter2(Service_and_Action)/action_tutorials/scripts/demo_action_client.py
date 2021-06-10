#! /usr/bin/env python

import actionlib
import rospy

from action_tutorials.msg import demoFeedback, demoResult, demoAction, demoGoal

number = 1

def feedback_callback(feedback):
	global number 
	print '[Feedback] number %d received' %number	
	number += 1

client = actionlib.SimpleActionClient('/demo_as', demoAction)

rospy.init_node('demo_action_client')
	
client.wait_for_server()

while not rospy.is_shutdown():
	
	goal = demoGoal()
	goal.count = input('Enter a number: ')
	
	client.send_goal(goal, feedback_cb = feedback_callback)
	
	client.wait_for_result()
	print '[Result] State: %d'%(client.get_state())
	print '---'
	number = 1
