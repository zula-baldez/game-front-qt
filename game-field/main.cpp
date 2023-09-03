#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "gameboard-model.h"
#include "gamecontroller.h"





int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    qmlRegisterType<GameBoard>     ("Game", 1, 0, "GameBoard_qml"     );
    qmlRegisterType<GameController>("Game", 1, 0, "GameController_qml");
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    std::string url1 = "123";

    return app.exec();
}
