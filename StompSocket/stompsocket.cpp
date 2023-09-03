#include "stompsocket.h"

#include <chrono>
#include <thread>

#include <QNetworkRequest>
QT_USE_NAMESPACE

namespace STOMP {
    using namespace std::string_literals;
    //using
    //todo callback in send, in client
    StompSocket::StompSocket(const QString& url, const QString& token, callback_connected connected, callback_sent sent, callback_closed closed) :
        sent(sent), connected(connected), closed(closed)
    {
        qDebug()<<url;
        m_url = url;
        connect(&m_webSocket, &QWebSocket::connected, this, &StompSocket::onConnected);
        connect(&m_webSocket, &QWebSocket::disconnected, this, &StompSocket::onClosed);
        connect(&m_webSocket, &QWebSocket::textMessageReceived, this, &StompSocket::onTextMessageReceived);
        QNetworkRequest request(url);
        QByteArray header =  (token).toUtf8();
        request.setRawHeader("Authorization", header);
        qDebug() << request.url();
        m_webSocket.open(request);
    }
    void StompSocket::startStompConnection() {
        QString request = "CONNECT\naccept-version:1.2,1.1,1.0\nheart-beat:10000,10000\n\n";
        request.append('\0');
        qDebug() << request;
        m_webSocket.sendTextMessage(request);
    }


    void StompSocket::subscribe(const QString& destination, int id) {
        QString request = "SUBSCRIBE\nid:sub-"+destination+std::to_string(id).c_str()+"\ndestination:"+destination+"\n\n";
        request.append('\0');
        qDebug() << request;
        m_webSocket.sendTextMessage(request);
    }    

    void StompSocket::unsubscribe(const QString& destination, int id) {
        QString request = "UNSUBSCRIBE\nid:sub-"+destination+std::to_string(id).c_str()+"\ndestination:"+destination+"\n\n";
        request.append('\0');
        qDebug() << request;
        m_webSocket.sendTextMessage(request);

    }

    void StompSocket::send(const QString& destination, const QString& json) {
        int contentLenght = json.length();
        QString request = "SEND\ndestination:"+destination+"\ncontent-length:"+contentLenght+"\n\n"+json;
        request.append('\0');
        qDebug() << request;
        m_webSocket.sendTextMessage(request);
    }    
    void StompSocket::onClosed() {
                qDebug() << m_webSocket.errorString();
                qDebug() << m_url;
                closed("Asd");
    }    
    void StompSocket::onConnected() {
        connected();
    }
    void StompSocket::onTextMessageReceived(QString message) {
        sent(message);
    }
    StompSocket::~StompSocket() {
        disconnect(&m_webSocket, &QWebSocket::disconnected, this, &StompSocket::onClosed);
    }


}
