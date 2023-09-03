#include "roomcontroller.h"


Q_INVOKABLE RoomModel* RoomController::getModel() {
    return &roomModel;
}


RoomController::RoomController() : networkController(&roomModel) {}
