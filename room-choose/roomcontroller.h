#ifndef ROOMCONTROLLER_H
#define ROOMCONTROLLER_H
#include "network-controller-room.h"
#include "roommodel.h"
class RoomController : public QObject
{

   Q_OBJECT

public:
    RoomController();

    Q_INVOKABLE RoomModel* getModel();
private:
    RoomModel roomModel;
    NetworkController networkController;
};

#endif // ROOMCONTROLLER_H
