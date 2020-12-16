"""
This package is a GUI for the turtlebot_teleop package.
"""

import sys
import os

import rospy
from std_msgs.msg import String

from PySide2.QtQml import QQmlApplicationEngine
from PySide2.QtGui import QGuiApplication

class RosNode():
    """
    ROS Node Class
    """
    def callback(self, data):
        """
        Callback function for the subscriber.
        """
        rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)

    def run(self):
        """
        Listener function for the ROS-Node
        """
        rospy.init_node('listener', anonymous=True)

        rospy.Subscriber("chatter", String, self.callback)

        #rospy.spin()

if __name__ == "__main__":
    app = QGuiApplication(sys.argv)
    engine = QQmlApplicationEngine()
    engine.load(os.path.join(os.path.dirname(__file__), "ui/main.qml"))

    n = RosNode()
    n.run()

    if not engine.rootObjects():
        sys.exit(-1)

    sys.exit(app.exec_())
    