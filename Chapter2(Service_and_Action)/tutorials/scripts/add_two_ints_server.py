#! /usr/bin/env python

import rospy
from tutorials.srv import AddTwoInts, AddTwoIntsResponse

def call_back(request):
    print "Returning [%s + %s = %s]" % (request.a, request.b, (request.a + request.b))
    return AddTwoIntsResponse(request.a + request.b)

rospy.init_node('add_two_ints_server')
rospy.Service('add_two_ints', AddTwoInts, call_back)
print "Ready to add two ints."
rospy.spin()