#!/usr/bin/env python
import rospy
import roslib
from datetime import datetime
from pub_sub.msg import User


def callback(user):
    user_str = "{} {}.{}.".format(
        user.last_name, user.first_name[0], user.middle_name[0])
    #rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)
    print("[User]: {user} {time:%H:%M:%S}".format(
        user=user_str, time=datetime.now()))


def listener():
    rospy.init_node('user_listener', anonymous=True)
    rospy.Subscriber("current_user", User, callback)
    rospy.spin()


if __name__ == '__main__':
    listener()
