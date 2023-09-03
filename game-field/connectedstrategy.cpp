#include "connectedstrategy.h"
#include "network-controller-game-field.h"
ConnectedStrategy::ConnectedStrategy()
{

}

inline void ConnectedStrategy::handleMessage(const QString& message, GameBoard* model, NetworkControllerGameField* networkController) {
    qDebug() << message;
    networkController->subscribe("/topic/accounts");
    networkController->subscribe("/topic/fines");
    networkController->subscribe("/topic/card-changes");

    networkController->allPlayersRequest();
}
