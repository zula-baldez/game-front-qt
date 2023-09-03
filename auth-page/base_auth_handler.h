#ifndef BASEAUTHHANDLER_H
#define BASEAUTHHANDLER_H
#include "auth_handler.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;
#include "screen-manager/global.h"
class BaseAuthHandler : public AuthHandler {
    Q_OBJECT
    Q_PROPERTY(QString login READ login WRITE setLogin NOTIFY loginChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)
public:
    BaseAuthHandler();
    QString login() const {
        return _login;
    }
    QString password() const {
        return _password;
    }
    void setLogin(QString login) {
        _login = login;
    }
    void setPassword(QString password) {
        _password = password;
    }
    Q_INVOKABLE void loginRequest() override;

    ~BaseAuthHandler() override {
        delete manager;
    }
signals:
    void loginChanged();
    void passwordChanged();
public slots:
    void replyFinished(QNetworkReply* resp);
private:
    QString _login;
    QString _password;
    QNetworkAccessManager * manager = new QNetworkAccessManager();
    QNetworkRequest request;

    GlobalPropertyHolder* _globalPropertyHolder =  GlobalPropertyHolder::instance();

};

#endif // BASEAUTHHANDLER_H
