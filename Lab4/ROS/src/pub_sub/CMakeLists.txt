cmake_minimum_required(VERSION 3.0.2)
project(pub_sub)

find_package(catkin REQUIRED COMPONENTS
    roscpp
    rospy
    std_msgs
    message_generation
)

add_message_files(
    FILES
    User.msg
)

generate_messages(
    DEPENDENCIES
    std_msgs
)

catkin_package(
    LIBRARIES pub_sub
    CATKIN_DEPENDS message_runtime roscpp rospy
)

catkin_install_python(PROGRAMS
   scripts/talker.py
   scripts/listener.py
   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

