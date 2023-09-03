pragma Singleton
import QtQuick 2.13

QtObject {
    property bool isDarkTheme : true
    readonly property color primaryColor:  isDarkTheme ? "black" : "black"
    readonly property color secondaryColor:  isDarkTheme ? "white" : "white"
    readonly property color backgroundColor: Qt.rgba(0.9098, 0.9098, 0.9098, 1)

    readonly property color brownColor : "#B4654A"
    readonly property color greyColor : "#70877F"

    readonly property real opacityDisabled: 0.6
    readonly property int commonText: 25
    readonly property int headerText: 50
}
