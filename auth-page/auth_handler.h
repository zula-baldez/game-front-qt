#ifndef AUTH_HANDLER_H
#define AUTH_HANDLER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
class AuthHandler : public QObject
{
    Q_OBJECT
public:
    explicit AuthHandler() {};
    Q_INVOKABLE virtual void loginRequest() = 0;
    virtual ~AuthHandler() {};

};

#endif // AUTH_HANDLER_H
