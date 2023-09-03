
#include "network-controller-room.h"

NetworkController::NetworkController(RoomModel* roomModel) : roomModel(roomModel), _socket("ws://172.26.64.1:8080/rooms", _globalPropertyHolder->token(),
                                                                                           std::bind( &NetworkController::onConnectedCallback, this), std::bind( &NetworkController::onTextMessageReceivedCallback, this, std::placeholders::_1), std::bind( &NetworkController::onClosed, this, std::placeholders::_1))
{}
void NetworkController::onConnectedCallback() {
    this->_socket.startStompConnection();
}
bool inline isValidIndex(int i, QStringList& list) {
    return i < list.size();
}
void NetworkController::onTextMessageReceivedCallback(QString message) {
    QStringList list = message.split("\n");
    qDebug() << message;
    if(!isValidIndex(0, list)) {
        return;
    }

    if(list[0] == "CONNECTED") {
        _socket.subscribe("/topic/new-rooms", _globalPropertyHolder->id());
        _socket.subscribe("/topic/all-rooms", _globalPropertyHolder->id());
        _socket.send("/app/create-room", "{\"capacity\":10,\"name\":\"zxc\"}" );

        _socket.send("/app/all-rooms", "" );

    }
    if(list[0] == "MESSAGE") {

        if(!isValidIndex(1, list)) {return;}
        int separateIndex = list[1].indexOf(QChar(':'));
        QString destination = list[1].mid(separateIndex+1, 100);
        qDebug() <<destination;

        QString body = list[list.size() - 1].remove(QChar('\u0000'));
        json data = json::parse(body.toStdString());
        if(destination == _newRoomsCommon) {
            qDebug() << "new room";


            Room room = Room::parseFromJson(data);
            roomModel->addRoomToModel(room);

        }
        if(destination == _allRoomsCommon) {
            for (auto it : data) {
                Room room = Room::parseFromJson(it);
                qDebug() << room.getId();
                roomModel->addRoomToModel(room);
            }
            _socket.unsubscribe(_allRoomsCommon, _globalPropertyHolder->id());

        }
    }
}
void NetworkController::onClosed(QString error) {
    qDebug() <<"on closed";

}
