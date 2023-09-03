import QtQuick 2.0


Image {
    property string imgPath: "../UI/Assets/2_bybi.png"
    property int cardWidth: 300/3
    property int cardHeight: 400/4
    property int rotate: 0
    property int xCoord: 500
    property int yCoord: 500
    id: _img
    cache: false
    source: imgPath
    width: cardWidth
    height: cardHeight
    Component.onCompleted: rotation = rotate
    property int zRotation: 0
    property int xScale : 1
    property int yScale : 1

    y: yCoord
    x: xCoord
    z: 2
    property point beginDrag
    property bool caught: false
    property bool dragDisabled: false
    Drag.active: mouseArea.drag.active
    Drag.keys: "player-hand"
    Drag.hotSpot.x: width / 2
    Drag.hotSpot.y: height / 2
    transform: [
        Rotation {id: _zRotation; origin.x: _img.width/2; origin.y: _img.height; axis { x: 0; y: 1; z: 0 } angle: _img.zRotation },
        Scale { origin.x: _img.width/2; origin.y: _img.height/2; xScale: _img.xScale; yScale: _img.yScale}
    ]

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        drag.target: parent
        drag.smoothed: false
        drag.threshold: 0
        enabled: dragDisabled ? false : true
        onPressed: {
            _img.beginDrag = Qt.point(_img.x, _img.y)
            scaleAnimX.to = 2
            scaleAnimY.to = 2
            scaleAnim.start()

        }

        onReleased: {
            scaleAnimX.to = 1
            scaleAnimY.to = 1
            scaleAnim.start()
            if(!_img.caught) {
                backAnimX.from = _img.x
                backAnimX.to = _img.beginDrag.x
                backAnimY.from = _img.y
                backAnimY.to = _img.beginDrag.y
                backAnim.start()
            } else {
                parent.Drag.drop()
                dropAnim.start()
            }
        }
    }
    ParallelAnimation {
        id: scaleAnim
        NumberAnimation { target: _img; id: scaleAnimX; properties: "xScale"; duration: 100 }
        NumberAnimation { target: _img; id: scaleAnimY; properties: "yScale"; duration: 100 }
    }


    SequentialAnimation {
        id: dropAnim
        PropertyAction { target: _img; properties: "dragDisabled"; value: true}
        ParallelAnimation {
            NumberAnimation { target: _img; id: rotateAnim; properties: "rotation"; to: _img.rotate; duration: 400 }
            SequentialAnimation {
                NumberAnimation { target: _img; properties: "zRotation"; from: 0; to: 90; duration: 100 }
                PropertyAction { target: _img; property: "source"; value: "/UI/Assets/rubashka.jpg" }
                NumberAnimation { target: _img; properties: "zRotation"; from: 90; to: 270; duration: 200 }
                PropertyAction { target: _img; properties: "source"; value: _img.imgPath}
                NumberAnimation { target: _img; properties: "zRotation"; from: 270; to: 360; duration: 100 }


            }
        }
        PropertyAction { target: _img; properties: "dragDisabled"; value: false}

    }
    SequentialAnimation {
        id: backAnim
        PropertyAction { target: _img; properties: "dragDisabled"; value: true}

        ParallelAnimation {

            PropertyAction { target: _img; properties: "dragDisabled"; value: true}

            SpringAnimation { id: backAnimX; target: _img; property: "x"; duration: 0; spring: 5; damping: 0.5 }
            SpringAnimation { id: backAnimY; target: _img; property: "y"; duration: 0; spring: 5; damping: 0.5 }

        }
        PropertyAction { target: _img; properties: "dragDisabled"; value: false}


    }



}

