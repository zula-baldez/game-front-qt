import QtQuick 2.13
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.12
import QtQuick.Window 2.12

TextField {
    property string placeholder: ""
    property string compId: ""
    property int paddings: dp(15)
    property int render: Text.QtRendering
    property int rad : dp(10)
    property int fontSize: dp(18)
    property int borderWidth: dp(1)
    property int echo : TextInput.Center

    background: Rectangle {
                  radius: rad
                  border.color: "#333"
                  border.width: borderWidth
              }

    padding: paddings
    id: compId
    font.pointSize: fontSize
    placeholderText: placeholder
    renderType: render
    echoMode: echo


    //onTextChanged: backend.text = text
}

