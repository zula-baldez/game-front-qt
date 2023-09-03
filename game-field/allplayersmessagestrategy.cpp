#include "allplayersmessagestrategy.h"
#include "network-controller-game-field.h"

AllPlayersMessageStrategy::AllPlayersMessageStrategy() {

}
void AllPlayersMessageStrategy::handleMessage(const QString& message, GameBoard* model, NetworkControllerGameField* networkController) {
    json data = json::parse(message.toStdString());
    for(auto i : data) {
        Player player = Player::parseFromJson(i);
        networkController->addPlayer(player);
    }


}
