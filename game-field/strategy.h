
#ifndef STRATEGY_H
#define STRATEGY_H

#include "gameboard-model.h"
class NetworkControllerGameField;
class Strategy
{
public:
    Strategy() {}

    virtual void handleMessage(const QString& message, GameBoard* model, NetworkControllerGameField* networkController) = 0;
    virtual ~Strategy() {};
};

#endif // STRATEGY_H
