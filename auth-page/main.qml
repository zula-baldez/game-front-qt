import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtWebEngine 1.10
import StyleSettings 1.0

ApplicationWindow  {

    id : mainWindow
    minimumWidth: 500
    minimumHeight: 500 //todo
    property int dpi: Screen.pixelDensity * 25.4
    property int screenWidth: Screen.width*2/3
    property int screenHeight: Screen.height*2/3
//    WebEngineView {
//        id: webView
//        anchors.fill: parent

//        onUrlChanged: {
//            console.log("URL changed to:", url);
//        }
//    }



//    Component.onCompleted: {
//        // Function to open the URL in the web browser
//        function openUrl(url) {
//            webView.url = url;
//        }
//        // Example usage:
//        openUrl("http://172.26.64.1:8080/oauth2/authorization/vk");
//    }

    function dp(x) {
           if (dpi < 120) {
               return Math.max(x * 1.0 / 1080 * mainWindow.height,1)
           } else {
               return x * (dpi / 160)
           }
       }

    width: screenWidth
    height: screenHeight
    visible: true
    color : Style.backgroundColor

    title: qsTr("auth-form")

    Loader {
        id : mainForm
        anchors.fill: parent
        source:"./UI/AuthAll.qml"
    }




}
