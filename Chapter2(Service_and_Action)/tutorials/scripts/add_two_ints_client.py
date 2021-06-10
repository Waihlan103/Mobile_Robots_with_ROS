#! /usr/bin/env python

import rospy
from tutorials.srv import AddTwoInts, AddTwoIntsRequest

rospy.init_node('add_two_ints_client')
rospy.wait_for_service('/add_two_ints')

var = rospy.ServiceProxy('/add_two_ints', AddTwoInts)

number = AddTwoIntsRequest()

while not rospy.is_shutdown():

	print 'Please enter two integers: '
	number.a = input()
	number.b = input()

	print (var(number))
	print '---'


