#ifndef NETWORK-CONTROLLER-ROOM_H
#define NETWORK-CONTROLLER-ROOM_H

#include "roommodel.h"
#include "screen-manager/global.h"

class NetworkController
{
public:
    NetworkController(RoomModel* roomModel);
    NetworkController() = delete;
private:
    void onConnectedCallback();
    void onTextMessageReceivedCallback(QString message);
    void onClosed(QString error);
    GlobalPropertyHolder* _globalPropertyHolder =  GlobalPropertyHolder::instance();
    STOMP::StompSocket _socket;
    QString _newRoomsCommon = "/topic/new-rooms";
    QString _allRoomsCommon = "/topic/all-rooms";
    RoomModel* roomModel;

};

#endif // NETWORK-CONTROLLER-ROOM_H
