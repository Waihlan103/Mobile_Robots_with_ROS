#!/usr/bin/env python
import rospy

global_name = rospy.get_param("/global_name")
relative_name = rospy.get_param("relative_name")
private_name = rospy.get_param('~private_name')
default_name = rospy.get_param('default_param', 'default_value')

gains = rospy.get_param('gains')
p, i, d = gains['p'], gains['i'], gains['d']

rospy.set_param('a_string', 'baz')
rospy.set_param('~private_int', 2)
rospy.set_param('list_of_floats', [1., 2., 3., 4.])
rospy.set_param('bool_True', True)
rospy.set_param('gains', {'p':1, 'i':2, 'd':3})

rosparam.set_param('a_string', 'baz')
rosparam.set_param('~private_int', 2)
rosparam.set_param('list_of_floats', "[1., 2., 3., 4.]")
rosparam.set_param('bool_True', "true")
rosparam.set_param('gains', "{'p':1, 'i':2, 'd':3}")

rospy.get_param('gains/p')