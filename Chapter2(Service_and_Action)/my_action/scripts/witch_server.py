#! /usr/bin/env python

import rospy
import actionlib
from my_action.msg import witchAction

class witch_server():
	"""docstring for witch_server"""
	def __init__(self):
		self.server = actionlib.SimpleActionServer('witch_action', witchAction, self.execute, False)
		self.server.start()

	def execute(self, goal):
		rospy.loginfo("I got %d", goal.count)
		self.server.set_succeeded()

if __name__ == '__main__':
	rospy.init_node('witch_server')
	server = witch_server()
	rospy.spin()
		