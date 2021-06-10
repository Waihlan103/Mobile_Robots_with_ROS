#! /usr/bin/env python

import rospy
import random
from exercise4.msg import Int2

rospy.init_node("two_ints_publisher")
pub = rospy.Publisher('/two_ints', Int2, queue_size = 1)
rate = rospy.Rate(2)
count = Int2()

while not rospy.is_shutdown():
    count.a = random.randint(0,10)
    count.b = random.randint(0,10)
    pub.publish(count)
    rate.sleep()