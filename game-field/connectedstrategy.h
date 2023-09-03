
#ifndef CONNECTEDSTRATEGY_H
#define CONNECTEDSTRATEGY_H

#include "strategy.h"
class ConnectedStrategy : public Strategy
{
public:
    ConnectedStrategy();
    virtual void handleMessage(const QString& message, GameBoard* model, NetworkControllerGameField* networkController) override;

};

#endif // CONNECTEDSTRATEGY_H
