#!/usr/bin/env python

import rospy

rospy.init_node("hello")
rate = rospy.Rate(10) # 10hz
while not rospy.is_shutdown(): #loop until closing the terminal or press Crtl+Z
	print ("Hello World")
	rate.sleep()