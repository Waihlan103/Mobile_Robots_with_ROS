#! /usr/bin/env python

import rospy
from my_service.srv import *

def handle_add_three_ints(req):
	print "Returning [%s + %s + %s = %s]"%(req.A, req.B, req.C, (req.A + req.B + req.C))
	return whkResponse(req.A + req.B + req.C)

def add_three_ints_server():
	rospy.init_node('add_three_ints_server')
	s = rospy.Service('blabla', whk, handle_add_three_ints)
	print "Ready to add three ints ."
	rospy.spin()

if __name__ == '__main__':
	add_three_ints_server()