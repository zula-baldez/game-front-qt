#include "cardmovementstrategy.h"
#include "network-controller-game-field.h"
#include "card.h"
CardMovementStrategy::CardMovementStrategy()
{

}

void CardMovementStrategy::handleMessage(const QString& message, GameBoard* model, NetworkControllerGameField* networkController) {
    qDebug() << "card give";
    json data = json::parse(message.toStdString());
    int idFrom = data["idFrom"];
    int idTo = data["idTo"];
    Card card = Card::parseFromJson(data["card"]);
    if(idTo != -1) {
      //model->removeCardFromPlayer(card, idFrom);
      model->addCardToPlayer(card, idTo);

    }



}
