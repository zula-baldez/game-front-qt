#include "accountactionstrategy.h"
#include "network-controller-game-field.h"

AccountActionStrategy::AccountActionStrategy()
{

}
void AccountActionStrategy::handleMessage(const QString& message, GameBoard* model, NetworkControllerGameField* networkController) {
    json data = json::parse(message.toStdString());
    std::string action = data["accountAction"];
    if(action == "ADD") {
        int id = data["id"];
        std::string name = data["name"];
        Player player = Player(id, QString::fromStdString(name));
        networkController->addPlayer(player);

    }


}
