#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "game-field/gameboard-model.h"
#include "game-field/gamecontroller.h"
#include "auth-page/authrorizedmanager.h"
#include "auth-page/base_auth_handler.h"
#include "auth-page/vk_oauth_handler.h"
#include "room-choose/roomcontroller.h"
#include "room-choose/roommodel.h"
#include <QQmlContext>
#include "room-choose/gamefieldconnecter.h"
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.addImportPath(":/auth-page-view/qml");

    qmlRegisterType<GameBoard>     ("Game", 1, 0, "GameBoard_qml");
    qmlRegisterType<GameController>("Game", 1, 0, "GameController_qml");
    qmlRegisterType<RoomController>     ("Rooms", 1, 0, "RoomController_qml");
    qmlRegisterType<RoomModel>     ("Rooms", 1, 0, "RoomModel_qml");
    qmlRegisterType<GameFieldConnecter>     ("Rooms", 1, 0, "GameFieldConnecter_qml");


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    BaseAuthHandler bAuthHandler;
    VkOauthHandler vkAuth;
    AuthrorizedManager authorizedManager;
    GlobalPropertyHolder* globalProperties = GlobalPropertyHolder::instance();
    engine.rootContext()->setContextProperty("baseAuth", &bAuthHandler);
    engine.rootContext()->setContextProperty("vkAuth", &vkAuth);
    engine.rootContext()->setContextProperty("authorizedManager", &authorizedManager);
    engine.rootContext()->setContextProperty("globalProperties", globalProperties);

    engine.load(url);
    return app.exec();
}
