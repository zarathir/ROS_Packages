import sys
import os

import rospy
from std_msgs.msg import String

from PySide2.QtQml import QQmlApplicationEngine
from PySide2.QtGui import QGuiApplication

def callback(data):
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)

def listener():
    rospy.init_node('listener', anonymous=True)

    rospy.Subscriber("chatter", String, callback)

if __name__ == "__main__":
    app = QGuiApplication(sys.argv)
    engine = QQmlApplicationEngine()
    engine.load(os.path.join(os.path.dirname(__file__), "main.qml"))

    listener()

    if not engine.rootObjects():
        sys.exit(-1)

    sys.exit(app.exec_())
    