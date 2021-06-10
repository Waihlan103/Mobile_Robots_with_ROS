#! /usr/bin/env python

import rospy
from turtlesim.srv import *

rospy.init_node('service_client')
rospy.wait_for_service('/spawn')

spawner = rospy.ServiceProxy('/spawn', Spawn)

turtle = SpawnRequest()
turtle.x = 10.0
turtle.y = 10.0
turtle.theta = 90.0
turtle.name = "turtle_new"


result = spawner(turtle)
print result