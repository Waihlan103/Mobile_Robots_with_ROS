#! /usr/bin/env python

import rospy
from exercise4.msg import Int2
from std_msgs.msg import Int32

def callback(msg):
    total_sum = msg.a + msg.b
    pub.publish(total_sum)

rospy.init_node("two_ints_subscriber")
pub = rospy.Publisher('/sum', Int32, queue_size = 1)
rospy.Subscriber('/two_ints', Int2, callback)
rospy.spin()