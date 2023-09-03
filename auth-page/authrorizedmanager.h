#ifndef AUTHRORIZEDMANAGER_H
#define AUTHRORIZEDMANAGER_H
#include <QObject>
#include <qhttprequest.h>
#include <qhttpserver.h>
#include "screen-manager/global.h"
class AuthrorizedManager : public QObject
{
    Q_OBJECT
public:
    AuthrorizedManager();


public slots:
    void handle(QHttpRequest *req, QHttpResponse *resp);
private:
    QHttpServer *server = new QHttpServer;


};

#endif // AUTHRORIZEDMANAGER_H
