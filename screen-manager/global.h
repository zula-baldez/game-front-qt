#pragma once

#include <QObject>
#include <QDebug>
class GlobalPropertyHolder : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int screenId READ getScreenId WRITE setScreenId NOTIFY screenIdChanged)

public:
    static GlobalPropertyHolder* instance()
    {
        static GlobalPropertyHolder* instance = new GlobalPropertyHolder;
        return instance;
    }

    int getScreenId() {
        return _screenId;
    }
    void setScreenId(int screenId) {
        if(screenId != _screenId) {
            qDebug() << _screenId;
            this->_screenId = screenId;
            emit screenIdChanged();

        }
    }

    int getGameId() {
        qDebug()<<123;

        qDebug()<<_gameId;

        return _gameId;
    }
    void setGameId(long gameId) {
        qDebug()<<gameId;

        _gameId = gameId;
    }

    void setToken(QString token) {
        this->_token = token;
    }
    QString token() {
        return _token;
    }

    void setId(int id) {
        this->_id = id;
    }
    int id() {
        return _id;
    }
signals:
    void screenIdChanged();


private:
    GlobalPropertyHolder(QObject* parent = nullptr)
        : QObject(parent)
    {
    }
    int _screenId = 0;
    QString _token = "";
    int _gameId = 0;
    int _id = 0;


};
