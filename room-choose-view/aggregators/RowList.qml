import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import Rooms 1.0
import "../components"
import StyleSettings 1.0




ListView {
    width: parent.width
    height: parent.height

    RoomController_qml{
        id: _roomController
    }
    id: roomList
    model: _roomController.getModel()
    spacing: 5

    delegate: Item {
        width: parent.width
        height: 50

        Row {
            capacity: model.capacity
            name: model.name
            count: model.count
            roomId: model.id
            //count: model.display.count
           // name: model.display.name
        }
    }
}

