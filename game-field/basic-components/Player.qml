import QtQuick 2.15

Rectangle {
    id: root
    property alias internalText: valueText

    color: "lightgreen"
    border.color: "black"
    border.width: 1
    radius: 5
    z: 0
    width: 0
    height: 0
    Text {
        id: valueText
        text: "1"

        font.bold: true
        font.pointSize: root.height / 10

        anchors.centerIn: root
    }
}
