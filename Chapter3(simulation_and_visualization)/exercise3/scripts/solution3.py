#! /usr/bin/env python

import rospy
from turtlesim.msg import Pose

def callback(msg):
    print "x: ", msg.x
    print "y: ", msg.y
    print "theta: ", msg.theta
    print "linear_velocity: ", msg.linear_velocity
    print "angular_velocity: ", msg.angular_velocity
    print "---"
    
rospy.init_node("turtle")
rospy.Subscriber("/turtle1/pose", Pose, callback)
rospy.spin()