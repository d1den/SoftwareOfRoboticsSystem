#!/usr/bin/env python
import rospy
import roslib
from pub_sub.msg import User


def talker():
    pub = rospy.Publisher('current_user', User, queue_size=10)
    rospy.init_node('user_publisher', anonymous=True)
    rate = rospy.Rate(1)
    while not rospy.is_shutdown():
        user = User()
        user.first_name = "Pavel"
        user.middle_name = "Andreevich"
        user.last_name = "Seleznev"
        pub.publish(user)
        rate.sleep()


if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
