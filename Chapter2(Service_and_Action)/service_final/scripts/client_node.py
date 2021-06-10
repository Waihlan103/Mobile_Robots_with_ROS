#! /usr/bin/env python

import rospy
from std_srvs.srv import Empty, EmptyRequest

rospy.init_node('client_node')
rospy.wait_for_service('/Empty')

var = rospy.ServiceProxy('/Empty', Empty)

number = EmptyRequest()

print(var(number))