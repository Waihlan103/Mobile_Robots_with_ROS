#! /usr/bin/env python

import rospy
from std_msgs.msg import String

rospy.init_node("test_publisher")
pub = rospy.Publisher('/hi', String, queue_size = 1)
rate = rospy.Rate(2)
name = 'Hello'

while not rospy.is_shutdown():
	pub.publish(name)
	rate.sleep()	