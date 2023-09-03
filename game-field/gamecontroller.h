#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include "gameboard-model.h"
#include "network-controller-game-field.h"
class GameController : public QObject
{
    Q_OBJECT

public:
    explicit GameController(QObject *parent = nullptr);

    Q_INVOKABLE GameBoard* getModel();
    Q_INVOKABLE void startGame();


private:
    NetworkControllerGameField networkController;
    GameBoard gameBoard;
};

#endif
