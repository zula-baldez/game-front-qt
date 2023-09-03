#ifndef ACCOUNTACTIONSTRATEGY_H
#define ACCOUNTACTIONSTRATEGY_H

#include "strategy.h"
class AccountActionStrategy : public Strategy
{
public:
    AccountActionStrategy();
    virtual void handleMessage(const QString& message, GameBoard* model, NetworkControllerGameField* networkController) override;

};

#endif // ACCOUNTACTIONSTRATEGY_H
