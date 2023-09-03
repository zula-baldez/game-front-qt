#ifndef ALLPLAYERSMESSAGESTRATEGY_H
#define ALLPLAYERSMESSAGESTRATEGY_H

#include "strategy.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;
class AllPlayersMessageStrategy : public Strategy
{
public:
    AllPlayersMessageStrategy();
    virtual void handleMessage(const QString& message, GameBoard* model, NetworkControllerGameField* networkController) override;

};

#endif // ALLPLAYERSMESSAGESTRATEGY_H
