#include "authrorizedmanager.h"
#include "qhttpresponse.h"
#include <QDebug>
AuthrorizedManager::AuthrorizedManager()
{

    connect(server, SIGNAL(newRequest(QHttpRequest*, QHttpResponse*)),
            this, SLOT(handle(QHttpRequest*, QHttpResponse*)));

    server->listen(9999);

}
void AuthrorizedManager::handle(QHttpRequest *req, QHttpResponse *resp)
{

    QString token = req->url().toString();
    token = token.right(token.size() - 1);
    resp->setHeader("Content-Length", QString("13"));
    resp->writeHead(200);
    resp->write("Close browser");
    resp->end();

    GlobalPropertyHolder::instance()->setScreenId(1);
    GlobalPropertyHolder::instance()->setToken("Bearer "+token);

}


