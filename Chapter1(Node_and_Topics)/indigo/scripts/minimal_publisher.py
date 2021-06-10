#! /usr/bin/env python

import rospy
from std_msgs.msg import Float64

rospy.init_node("minimal_publisher", anonymous = True)
pub = rospy.Publisher("topic1", Float64, queue_size = 10)

rate = rospy.Rate(10)

msg = Float64()
msg.data = 0.0
while not rospy.is_shutdown():
	pub.publish(msg)
	msg.data = msg.data + 0.01
	rate.sleep()
