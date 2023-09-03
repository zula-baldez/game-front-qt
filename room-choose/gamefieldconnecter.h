#ifndef GAMEFIELDCONNECTER_H
#define GAMEFIELDCONNECTER_H
#include "screen-manager/global.h"
#include <QObject>



class GameFieldConnecter: public QObject
{
    Q_OBJECT
public:
    GameFieldConnecter() {};
    Q_INVOKABLE void connectToField(long roomId);
    virtual ~GameFieldConnecter();
private:
    GlobalPropertyHolder* _globalPropertyHolder =  GlobalPropertyHolder::instance();

};

#endif // GAMEFIELDCONNECTER_H
