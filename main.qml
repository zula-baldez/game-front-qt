import QtQuick 2.15
import QtQuick.Window 2.15

import QtQuick.Controls 2.15

ApplicationWindow  {

    property int currentComponentIndex: globalProperties.screenId
    visible: true
    minimumHeight: 1000
    minimumWidth: 1000
    property int dpi: Screen.pixelDensity * 25.4
    id: mainWindow
    function dp(x) {
           if (dpi < 120) {
               return Math.max(x * 1.0 / 1080 * mainWindow.height,1)
           } else {
               return x * (dpi / 160)
           }
    }


    Loader {
        id: componentLoader
        anchors.fill: parent

        source: componentSource
    }
    //auth-page-view/main.qml
    property string componentSource: ["auth-page-view/main.qml", "room-choose-view/main.qml", "game-field-view/main.qml"][currentComponentIndex]


}
