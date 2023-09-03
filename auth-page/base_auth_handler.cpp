#include "base_auth_handler.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonObject>

BaseAuthHandler::BaseAuthHandler()
{

}
std::string baseUrl = "http://172.26.64.1:8082";

void BaseAuthHandler::loginRequest()  {
    qDebug() << _login;
    std::string url = baseUrl + "/auth/register";
    request.setUrl(QUrl(url.c_str()));
    QJsonDocument jsonDoc;
    QJsonObject jsonObj;
    jsonObj["username"] = _login;
    jsonObj["password"] = _password;
    jsonDoc.setObject(jsonObj);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    qDebug() <<  jsonDoc.toJson();
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)),
        this, SLOT(replyFinished(QNetworkReply*)));
    manager->post(request, jsonDoc.toJson());
}
void BaseAuthHandler::replyFinished(QNetworkReply* resp) {

    auto t = resp->readAll();
    qDebug()<<t;
    json data = json::parse(t.toStdString());
    std::string token = data["token"];
    _globalPropertyHolder->setToken("Bearer " + QString::fromStdString(token));

    _globalPropertyHolder->setId(data["id"]);
    _globalPropertyHolder->setScreenId(1);

}
