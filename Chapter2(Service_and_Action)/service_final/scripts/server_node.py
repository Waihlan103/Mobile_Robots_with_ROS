#! /usr/bin/env python

import rospy
from std_srvs.srv import Empty, EmptyResponse

def callback(request):
	print "Returning" 
	return EmptyResponse()

rospy.init_node('server_node')
rospy.Service('Empty', Empty, callback)
print "Waiting for the client request"
rospy.spin()