#include "network-controller-game-field.h"
#include "connectedstrategy.h"
#include "allplayersmessagestrategy.h"
#include <QUrlQuery>
NetworkControllerGameField::NetworkControllerGameField(GameBoard* model) :  _socket("ws://172.26.64.1:8083/game?roomId="+QString::number(_globalPropertyHolder->getGameId()), _globalPropertyHolder->token(),
                                                                                    std::bind( &NetworkControllerGameField::onConnectedCallback, this), std::bind( &NetworkControllerGameField::onTextMessageReceivedCallback, this, std::placeholders::_1), std::bind( &NetworkControllerGameField::onClosed, this, std::placeholders::_1)),
    _model(model)
{

}
void NetworkControllerGameField::subscribe(const QString& dest) {
    this->_socket.subscribe(dest, _globalPropertyHolder->id());
}

void NetworkControllerGameField::send(const QString& destination, const QString& json) {
    this->_socket.send(destination, json);

}

void NetworkControllerGameField::onConnectedCallback() {
    qDebug()<<"connected!";
    this->_socket.startStompConnection();
}
void NetworkControllerGameField::onClosed(const QString& error) {

    _globalPropertyHolder->setScreenId(1);
}


void NetworkControllerGameField::onTextMessageReceivedCallback(const QString& message) {
    qDebug() <<message;
    QStringList list = message.split("\n");
    strategyController.handleMessageWithContext(message, _model, this);

    if(list[0] == "CONNECTED") {

    }
}

void NetworkControllerGameField::addPlayer(Player player) {
    _model->addPlayer(player);
}
std::string baseUrlAllPlayers = "http://172.26.64.1:8083";




void NetworkControllerGameField::allPlayersRequest() {
    std::string url = baseUrlAllPlayers + "/all-players";

    QUrl qurl = QUrl(url.c_str());

    QUrlQuery query;

    // Add request parameters to the query
    query.addQueryItem("roomId", QString::number(_globalPropertyHolder->getGameId()));


    qurl.setQuery(query);
    request.setUrl(qurl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", _globalPropertyHolder->token().toLocal8Bit());
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)),
        this, SLOT(replyFinished(QNetworkReply*)));
    manager->get(request);
}

void NetworkControllerGameField::replyFinished(QNetworkReply* resp) {
    qDebug() << resp->errorString();

   // qDebug()<<resp->readAll();
    json data = json::parse(resp->readAll());
    for(auto i : data) {
        Player player = Player::parseFromJson(i);
        this->addPlayer(player);
    }
}
NetworkControllerGameField::~NetworkControllerGameField(){}

