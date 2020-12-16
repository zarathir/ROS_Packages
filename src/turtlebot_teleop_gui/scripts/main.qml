import QtQuick 2.15
import QtQuick.Window 2.15


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Text {
        id: text1
        x: 246
        y: 103
        width: 143
        height: 72
        text: qsTr("Hello")
        font.pixelSize: 12
    }
}
