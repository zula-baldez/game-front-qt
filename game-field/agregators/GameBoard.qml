
import QtQuick 2.15
import QtQuick.Controls 2.15

import Game 1.0
import StyleSettings 1.0
import "../basic-components"
Page {
    id: root
    property int cellHeight: 200
    property int cellWidth: 150
    property int baseX : 960
    property int baseY: 276
    property int radiusX: 800
    property int radiusY: 700
    property int tableWidht: (2 * radiusX - 2 * 100)
    property int tableHeight: radiusY + 75
    GameController_qml{
        id: _gameController
    }
    Image {
        z: -1
        source: "../UI/Assets/table.jpg"
        width: tableWidht
        height: tableHeight
        x: baseX - tableWidht/2
        y : 1080 - baseY + cellWidth  - tableHeight
        rotation: 180
    }
    CustomButton {
        text: "aboba"
        x: 100
        y: 500
        onClicked: _gameController.startGame();

    }

    Repeater {
        id: _repeater

        model:  _gameController.getModel();
        z: 1
        delegate: Item {

                id: _delegate
                DropArea {
                    id: _drop_area
                    x: root.baseX - root.cellWidth/2 + root.radiusX / 1.7 * Math.cos(Math.PI * 1.0 * index / (_repeater.count-1))
                    y: 1080 - root.cellHeight/2 - (root.baseY + root.radiusY / 1.7 * Math.sin(Math.PI * 1.0 * index / (_repeater.count-1)))
                    z: 1
                    rotation: 90 - 180 / (_repeater.count-1) * index
                    width: root.cellWidth
                    height: root.cellHeight
                    property string txt : model.display.toString()
                    keys: "player-hand"
                    onEntered: drag.source.caught = true;
                    onExited: drag.source.caught = false;
                    onDropped: {
                        drag.source.rotate = _drop_area.rotation


                    }

                    Rectangle {
                        anchors.fill: parent
                        border.color: "black"
                        color: "transparent"
                        border.width: 1
                        radius: 5

                    }
              }
            Player {
                width: cellWidth * 1.1
                height: cellHeight * 1.1
                x: root.baseX - width/2 + root.radiusX  * Math.cos(Math.PI * 1.0 * index / (_repeater.count-1))
                y: 1080 - height/2 - (root.baseY + root.radiusY * 0.97 * Math.sin(Math.PI * 1.0 * index / (_repeater.count-1)))
                internalText.text: "aboba"
            }
        }
    }
}
