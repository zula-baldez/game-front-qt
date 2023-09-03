#include "auth_handler.h"
#include <QHttpMultiPart>
#include <QUrlQuery>
#include <iostream>
#include <QDebug>
#include <QJsonObject>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QObject>

#include <unistd.h>
#include <QDesktopServices>
AuthHandler::AuthHandler(QObject *parent)
    : QObject{parent}
{

}
struct data {
    QString login;
    QString password;
};
std::string baseUrl = "http://172.26.64.1:8080";


void AuthHandler::sendLoginRequest() {
    qDebug() << _login;
    qDebug() << _login;
    std::string url = baseUrl + "/auth/register";
    request.setUrl(QUrl(url.c_str()));
    QJsonDocument jsonDoc;
    QJsonObject jsonObj;
    jsonObj["login"] = _login;
    jsonObj["password"] = _password;
    jsonDoc.setObject(jsonObj);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    qDebug() <<  jsonDoc.toJson();
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)),
        this, SLOT(replyFinished(QNetworkReply*)));
    manager->post(request, jsonDoc.toJson());
}

void AuthHandler::sendLoginRequestVk() {
    std::string url = baseUrl + "/oauth/VK/authenticate";
    request.setUrl(QUrl(url.c_str()));
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)),
        this, SLOT(replyFinishedVk(QNetworkReply*)));
    manager->get(request);

}
void AuthHandler::replyFinishedVk(QNetworkReply* resp) {
    QVariant status_code = resp->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    QVariant location = resp->header(QNetworkRequest::LocationHeader);
    QString url = location.toString();
    //todo ERRO HANDLING
    QDesktopServices::openUrl(QUrl(url));
    qDebug() << location;

}
void AuthHandler::replyFinished(QNetworkReply* resp) {
    resp->header(QNetworkRequest::LocationHeader);
    QVariant status_code = resp->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    qDebug() << status_code;


}



void loginChanged();
void passwordChanged();
void buttonClicked();
