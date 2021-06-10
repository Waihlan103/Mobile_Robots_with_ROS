#! /usr/bin/env python

import rospy
from geometry_msgs.msg import Twist

rospy.init_node("topic_publisher")
pub = rospy.Publisher('/turtle1/cmd_vel', Twist, queue_size = 1)
rate = rospy.Rate(2)
count = Twist()
count.linear.x = 2.0
count.angular.z = 1.0 

while not rospy.is_shutdown():
    pub.publish(count)
    
    rate.sleep()