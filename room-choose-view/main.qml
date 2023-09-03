import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import "aggregators"
import StyleSettings 1.0
import QtQuick.Layouts 1.3
import ResourceProvider 1.0

Rectangle  {

    id : row
    anchors.fill: parent
    visible: true
    Rectangle {
        anchors.fill: parent
        color: Style.backgroundColor

        Rectangle {
            id: logoRect
            height: parent.height * 0.2
            width: parent.width
            color: Style.backgroundColor
            Image {
                transformOrigin: Item.TopLeft
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.leftMargin: parent.width * 0.025
                source: Resources.icon
                property real aspectRatio: sourceSize.width / sourceSize.height
                height: parent.height
                width: height * aspectRatio

            }

            Text {
                anchors.fill: parent
                text: "AVAILABLE ROOMS"
                color: Style.primaryColor
                font.pointSize: dp(Style.headerText)
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter

            }
            CustomButton {
                //anchors.fill: parent

                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: parent.width * 0.025
                rad: 5
                fontSize: Style.commonText
                primaryColor: Style.secondaryColor
                secondaryColor: Style.brownColor
                text: "Create room"
                onClicked: {
                    console.log("aboab")
                }
            }

        }
        RowLayout {
            anchors.top: logoRect.bottom
            width: parent.width
            height: parent.height * 0.7


            Rectangle {

                border.width: 4
                radius: 10
                border.color: Style.brownColor

                Layout.preferredWidth: parent.width * 0.6
                Layout.preferredHeight: parent.height
                Layout.leftMargin: parent.width * 0.025
                RowList {
                    clip: true
                    anchors.margins : 10
                    anchors.fill: parent
                }
            }

            Rectangle {

                border.width: 4
                radius: 10
                border.color: Style.brownColor

                Layout.preferredWidth: parent.width * 0.325
                Layout.preferredHeight: parent.height
                Layout.leftMargin: parent.width * 0.025

                Layout.rightMargin: parent.width * 0.025
                Text {
                    id: text
                    text: qsTr("Chat is not supported yet")
                }
            }
        }


    }




}
