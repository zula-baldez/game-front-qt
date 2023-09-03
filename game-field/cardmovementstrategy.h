#ifndef CARDMOVEMENTSTRATEGY_H
#define CARDMOVEMENTSTRATEGY_H
#include "strategy.h"

class CardMovementStrategy : public Strategy
{
public:
    CardMovementStrategy();
    void handleMessage(const QString& message, GameBoard* model, NetworkControllerGameField* networkController);

};

#endif // CARDMOVEMENTSTRATEGY_H
