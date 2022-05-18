#!/usr/bin/env python

# import rospy
# from sensor_msgs.msg import JointState
# from std_msgs.msg import Header    

# if __name__ == '__main__':
#     rospy.init_node('state_pub')
#     pub = rospy.Publisher('joint_states', JointState, queue_size=10)
#     msg = JointState()
#     msg.header = Header()
#     msg.header.stamp = rospy.Time.now()
#     msg.name = ['xlider_joint', 'yslider_joint']
#     msg.position = [0, -0.015, 0.2549, 0,0,0]
#     msg.velocity = [0.02]
#     msg.effort = [10]
#     rate = rospy.Rate(10) # 10hz

#     while not rospy.is_shutdown():
#         pub.publish(msg)
#         rate.sleep()

import rospy
from std_msgs.msg import Float64    

if __name__ == '__main__':
    rospy.init_node('state_pub')
    pub1 = rospy.Publisher('INSECT_WATCHER/xslider_position_controller/command', Float64, queue_size=100)
    pub2 = rospy.Publisher('INSECT_WATCHER/yslider_position_controller/command', Float64, queue_size=100)
    msg1 = Float64()
    msg2 = Float64()
    v=Float64()
    v.data=0.05

    rate = rospy.Rate(0.5) # 10hz
    init_rate = rospy.Rate(0.2)

    #初始化
    msg1.data=0.0515
    msg2.data=0.057
    pub1.publish(msg1)
    pub2.publish(msg2)
    init_rate.sleep()

    while not rospy.is_shutdown():
        msg1.data=0.0515
        msg2.data=0.057
        pub1.publish(msg1)
        pub2.publish(msg2)
        rate.sleep()
        msg2.data=0.107
        pub2.publish(msg2)
        rate.sleep()
        msg2.data=0.157
        pub2.publish(msg2)
        rate.sleep()
        msg1.data=0.1015
        pub1.publish(msg1)
        rate.sleep()
        msg2.data=0.107
        pub2.publish(msg2)
        rate.sleep()
        msg2.data=0.057
        pub2.publish(msg2)
        rate.sleep()
        msg1.data=0.1515
        pub1.publish(msg1)
        rate.sleep()
        msg2.data=0.107
        pub2.publish(msg2)
        rate.sleep()
        msg2.data=0.157
        pub2.publish(msg2)
        rate.sleep()
