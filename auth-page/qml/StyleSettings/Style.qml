pragma Singleton
import QtQuick 2.13

QtObject {
    property bool isDarkTheme : true
    readonly property color primaryColor:  isDarkTheme ? "black" : "black"
    readonly property color secondaryColor:  isDarkTheme ? "white" : "white"
    readonly property color backgroundColor: Qt.rgba(0.9098, 0.9098, 0.9098, 1)
    readonly property real opacityDisabled: 0.6
}
