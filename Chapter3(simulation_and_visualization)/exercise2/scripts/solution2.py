#! /usr/bin/env python

import rospy
from std_msgs.msg import String

rospy.init_node("topic_publisher")
pub = rospy.Publisher('/hello', String, queue_size = 1)
rate = rospy.Rate(2)
name = 'Hello World'

while not rospy.is_shutdown():
    pub.publish(name)
    rate.sleep()