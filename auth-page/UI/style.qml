import QtQuick 2.0

QtObject {
    property bool isDarkTheme: true
    readonly property color primaryColor : isDarkTheme ? "black" :"black"
    //todo
}
