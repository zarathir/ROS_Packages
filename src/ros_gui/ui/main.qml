import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls.Universal 2.12
import QtQml 2.12

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("QML Signals and Slots")

    Connections {
        target: robotThread
        }
    }

    Button {
        id: buttonLoop
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenterOffset: -100

        text: "Start ROS Node"

        onClicked: robotThread.init()
    }


}
