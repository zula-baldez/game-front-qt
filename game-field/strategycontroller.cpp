#include "strategycontroller.h"
#include "network-controller-game-field.h"
StrategyController::StrategyController()
{

    //destToStrategy["connected"]=   connectedStrategy;
}


void StrategyController::handleMessageWithContext(const QString& message, GameBoard* model, NetworkControllerGameField* controller) {
    QStringList list = message.split("\n");

    qDebug()<<(message);
    if(list[0] == "CONNECTED") {
        connectedStrategy.handleMessage(message, model, controller);
    } else {
        int separateIndex = list[1].indexOf(QChar(':'));
        QString dest = list[1].mid(separateIndex+1, 100);
        QString body = list[list.size() - 1].remove(QChar('\u0000'));
        if(dest == "/topic/common/players") {

            allPlayersStrategy.handleMessage(body, model, controller);
        }
        if(dest == "/topic/accounts") {

            accountActionStrategy.handleMessage(body, model, controller);
        }
        if(dest == "/topic/card-changes") {
            cardMovementStrategy.handleMessage(body, model, controller);
        }

    }

}
StrategyController::~StrategyController() {
    for(auto& i : destToStrategy) {
        i.second.release();
    }
}
