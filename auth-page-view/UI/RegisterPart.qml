import QtQuick 2.13
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
import StyleSettings 1.0
import ResourceProvider 1.0
Rectangle {
    z: 0
    id: right
    color: "white"


    ColumnLayout {
        function verifyPasswordEquality() {
            if(password.text === passwordRepeat.text) {
                return true
            }
            return false
        }
        anchors.centerIn : parent
        spacing: dp(40)
        Text {
            Layout.alignment: Qt.AlignCenter

            text: "Create account"
            font.family: "Helvetica"
            font.pointSize: dp(40)
            font.bold: true
            color: "black"
        }

        RowLayout {
            spacing: 50
            Layout.alignment: Qt.AlignCenter

            Image {
                source: Resources.defaultGoogleIcon
                Layout.alignment: Qt.AlignCenter

                Layout.preferredWidth: dp(85)
                Layout.preferredHeight: dp(85)
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                       console.info("image clicked!")
                    }
                }
            }
            Image {
                source: Resources.defaultVkIcon
                Layout.alignment: Qt.AlignCenter

                Layout.preferredWidth: dp(85)
                Layout.preferredHeight: dp(85)
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                       vkAuth.loginRequest();
                    }
                }
            }
        }
        Text {
            Layout.alignment: Qt.AlignCenter

            text: "Or use login for registration"
            font.family: "Helvetica"
            font.pointSize: dp(20)
            font.bold: true
            color: "black"
        }
        CustomTextField {
            Layout.alignment: Qt.AlignCenter
            Layout.preferredWidth: right.width * 0.8
            placeholderText: "Enter name..."
            id: login
            echoMode: TextInput.Center
            onTextChanged:  baseAuth.login = text

        }
        CustomTextField {
            Layout.alignment: Qt.AlignCenter
            Layout.preferredWidth: right.width * 0.8
            placeholderText: "Enter password..."
            id: password
            echoMode: TextInput.Password
            onTextChanged:  baseAuth.password = text
        }
        CustomTextField {
            Layout.alignment: Qt.AlignCenter
            Layout.preferredWidth: right.width * 0.8
            placeholderText: "Repeat password..."
            id: passwordRepeat
            echoMode: TextInput.Password

        }


        Text {

            Layout.alignment: Qt.AlignCenter

            text: parent.verifyPasswordEquality() ? "" : "Passwords are not equals!"
            font.family: "Helvetica"
            font.pointSize: dp(25)
            font.bold: true
            color: "red"
        }
        CustomButton {
            onClicked: baseAuth.loginRequest()
            enabled: parent.verifyPasswordEquality()
            Layout.alignment: Qt.AlignCenter
            id: singup
            text : "Sign up!"

        }



    }
}
