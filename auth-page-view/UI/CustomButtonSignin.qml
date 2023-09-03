
import QtQuick 2.13
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
import StyleSettings 1.0

Button {
    id: button_2
    text: qsTr("SIGN IN")
    contentItem: Text {
        leftPadding: dp(50)
        rightPadding: dp(50)
        topPadding: dp(10)
        bottomPadding: dp(10)
        text: button_2.text
        color: button_2.pressed ? Style.primaryColor : Style.secondaryColor
        font.pointSize: dp(15)

    }

    background: Rectangle {
        color: button_2.pressed ? Style.secondaryColor : Style.primaryColor
        border.color: button_2.pressed ? Style.secondaryColor : Style.secondaryColor
        border.width: dp(2)
        radius: dp(25)
    }
}
