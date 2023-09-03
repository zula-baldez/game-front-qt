
#ifndef NETWORKCONTROLLER_H
#define NETWORKCONTROLLER_H
class Strategy;
#include "gameboard-model.h"
#include "strategycontroller.h"
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
class NetworkControllerGameField : public QObject
{
    Q_OBJECT
public:
    NetworkControllerGameField(GameBoard* gameBoard);
    void onConnectedCallback();
    void onTextMessageReceivedCallback(const QString& message);
    void onClosed(const QString& error);
    void subscribe(const QString& dest);
    void send(const QString& destination, const QString& json);
    void addPlayer(Player player);
    void allPlayersRequest();
    virtual ~NetworkControllerGameField();
public slots:
    void replyFinished(QNetworkReply* resp);

private:
    GlobalPropertyHolder* _globalPropertyHolder =  GlobalPropertyHolder::instance();
    STOMP::StompSocket _socket;
    GameBoard* _model;
    StrategyController strategyController = StrategyController();
    QNetworkAccessManager * manager = new QNetworkAccessManager();
    QNetworkRequest request;
};

#endif // NETWORKCONTROLLER_H
