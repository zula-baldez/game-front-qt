
import QtQuick 2.13
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
import StyleSettings 1.0

Button {
    property color primaryColor : Style.primaryColor
    property color secondaryColor : Style.secondaryColor
    //property string text
    property int leftPad: 50
    property int rightPad: 50
    property int topPad: 10
    property int botPad: 10
    property int fontSize: 15
    property int rad: 25

    contentItem: Text {
        leftPadding: dp(leftPad)
        rightPadding: dp(rightPad)
        topPadding: dp(topPad)
        bottomPadding: dp(botPad)
        text: parent.text
        color: parent.pressed ? primaryColor : secondaryColor
        opacity: enabled ? 1 : Style.opacityDisabled
        font.pointSize: dp(fontSize)

    }

    background: Rectangle {
        color: parent.pressed ? secondaryColor : primaryColor
        border.color: parent.pressed ? secondaryColor : secondaryColor
        border.width: dp(2)
        radius: dp(rad)
    }
}
