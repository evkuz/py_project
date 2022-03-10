#!/usr/bin/env python

import sys
import rospy
import actionlib
from move_base_msgs.msg import MoveBaseAction, MoveBaseGoal
from geometry_msgs.msg import Twist

# Presentation version 1 according to A.G
x1 = 0.750
y1 = 0.90
z1 = 0.0
w1 = 1.0

x2 = 0.00
y2 = 0.10
z2 = 0.0
w2 = 1.0

# Presentation version 2 according to A.R
x1 = 0.750
y1 = 0.90
z1 = 0.0
w1 = 1.0

x2 = 0.10
y2 = 0.10
z2 = -0.7
w2 = 0.7

# Presentation version 3 according to A.R + turn on 10,5 o'clock
x1 = 0.750
y1 = 0.90
z1 = 0.20
w1 = 0.90

x2 = 0.10
y2 = 0.10
z2 = -0.7
w2 = 0.7

'''
a = 1.0
b = 0.0
c = 0.0
d = 0.0
'''


def movebase_client(x, y, z, w):
    client = actionlib.SimpleActionClient('move_base',MoveBaseAction)
    print('w8ing server')
    client.wait_for_server()
    print('ok')
    goal = MoveBaseGoal()
    goal.target_pose.header.frame_id = "map"
    goal.target_pose.header.stamp = rospy.Time.now()
    goal.target_pose.pose.position.x = x
    goal.target_pose.pose.position.y = y
    goal.target_pose.pose.position.z = 0.0
    goal.target_pose.pose.orientation.x = 0.0
    goal.target_pose.pose.orientation.y = 0.0
    goal.target_pose.pose.orientation.z = z
    goal.target_pose.pose.orientation.w = w

    client.send_goal(goal)
    wait = client.wait_for_result()
    if not wait:
        rospy.logerr("Action server not available!")
        rospy.signal_shutdown("Action server not available!")
    else:
        return client.get_result()

if __name__ == '__main__':
    result = 0
    print sys.argv
    try:
        rospy.init_node('movebase_client_py')
        if len(sys.argv) < 2:
            result = -2
        elif sys.argv[1] == 'a':
            result = movebase_client(x1, y1, z1, w1)
        elif sys.argv[1] == 'b':
            result = movebase_client(x2, y2, z2, w2)
        else:
            print("Unknown point name!")
            result = -1

        if result == 1:
            rospy.loginfo("Goal execution done!")
            result = 0
    except rospy.ROSInterruptException:
        rospy.loginfo("Navigation test finished.")

    exit(result)