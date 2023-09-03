#include "gamefieldconnecter.h"
#include "QDebug"
void GameFieldConnecter::connectToField(long gameId) {
    _globalPropertyHolder->setGameId(gameId);
    _globalPropertyHolder->setScreenId(2);
}
GameFieldConnecter::~GameFieldConnecter() {

}
