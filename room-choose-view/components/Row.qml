import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import StyleSettings 1.0
import Rooms 1.0
Rectangle  {
    GameFieldConnecter_qml {
        id: _connecter
    }

    id : row

    width: parent.width
    height: Screen.height * 0.05
    border.width: 1
    property int capacity: 0
    property int count: 0
    property string name: ""
    property int roomId: 0
    radius: 5
    Text{
        height: parent.height
        font.pixelSize: dp(Style.commonText)
        id: roomName
        width: parent.width * 0.8
        text: name
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        leftPadding: 15
    }
    Text {
        height: parent.height
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: dp(Style.commonText)
        anchors.left: roomName.right
        width: parent.width * 0.2
        text: count.toString()+"/"+capacity.toString()
        rightPadding: 15
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            _connecter.connectToField(roomId);
        }
    }








}
