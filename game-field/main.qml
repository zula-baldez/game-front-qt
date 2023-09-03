import QtQuick 2.15
import QtQuick.Window 2.15
import "agregators"

//todo модули
Window {
    width: 1920
    height: 1080
    visible: true
    title: qsTr("Hello World")
    GameBoard {
            id: _gameBoard
            anchors.fill: parent
            anchors.margins: 5
    }
}
