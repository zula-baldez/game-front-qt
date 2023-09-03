
#ifndef STRATEGYCONTROLLER_H
#define STRATEGYCONTROLLER_H

#include <unordered_map>
#include "strategy.h"
#include "connectedstrategy.h"
#include "allplayersmessagestrategy.h"
#include "accountactionstrategy.h"
#include "cardmovementstrategy.h"
class StrategyController
{
public:
    StrategyController();
    void handleMessageWithContext(const QString& message, GameBoard* model, NetworkControllerGameField* controller);
    ~StrategyController();
private:
    std::unordered_map<QString, std::unique_ptr<Strategy>> destToStrategy;
    ConnectedStrategy connectedStrategy;
    AllPlayersMessageStrategy allPlayersStrategy;
    AccountActionStrategy accountActionStrategy;
    CardMovementStrategy cardMovementStrategy;
};

#endif // STRATEGYCONTROLLER_H
