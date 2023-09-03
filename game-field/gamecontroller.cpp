#include "gamecontroller.h"

GameController::GameController(QObject *parent) : QObject(parent), networkController(&gameBoard)
{
}

GameBoard* GameController::getModel()
{
    return &gameBoard;
}

void GameController::startGame() {
    networkController.send("/app/start-game", "");
}
