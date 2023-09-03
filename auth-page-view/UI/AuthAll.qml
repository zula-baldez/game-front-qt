import QtQuick 2.0
import QtQuick.Layouts 1.3
import StyleSettings 1.0


Item {
    property int rad : dp(20)
    anchors.centerIn: parent
    width : parent.width * 0.85
    height : parent.height * 0.85
    Rectangle {
        anchors.fill: parent
        radius : rad
        border.width: rad / 2
        color: Qt.rgba(0, 0, 0, 0)
        border.color: Style.backgroundColor
        z: 1
    }

    Rectangle {
        z: 0
        anchors.centerIn: parent
        width : parent.width - rad / 2
        height: parent.height - rad
        GridLayout {
            z: 0
            columns: 2

            anchors.fill: parent
            columnSpacing: 0
            SignInPart {
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
            RegisterPart {
                Layout.fillWidth: true
                Layout.fillHeight: true
            }


        }
    }


}

