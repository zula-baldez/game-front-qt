import QtQuick 2.13
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
import StyleSettings 1.0
Rectangle {
    z: 0
    id: left
    color: Style.primaryColor
    ColumnLayout {
        anchors.centerIn : parent
        spacing: dp(60)
        Text {
            Layout.alignment: Qt.AlignCenter

            text: "Welcome back!"
            font.family: "Helvetica"
            font.pointSize: dp(60)
            font.bold: true
            color: Style.secondaryColor
        }
        Text {
            Layout.alignment: Qt.AlignCenter

            text: "To keep connected with us please\n login with your personal info"
            font.family: "Helvetica"
            font.pointSize: dp(20)
            color: Style.secondaryColor
        }
        CustomButton {
            Layout.alignment: Qt.AlignCenter
            primaryColor: "white"
            secondaryColor: "black"
            text: "Sign In!"

        }


    }


}
