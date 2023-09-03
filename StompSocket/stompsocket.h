#ifndef STOMPSOCKET_H
#define STOMPSOCKET_H
#include <iostream>
#include <unordered_map>
#include <QtCore/QObject>
#include <QtWebSockets/QWebSocket>

namespace STOMP {
    using callback_connected = std::function<void(void)>;
    using callback_sent = std::function<void(QString message)>;
    using callback_closed = std::function<void(QString message)>;



    class StompSocket : public QObject {
        Q_OBJECT
        public:
            StompSocket(const QString& url, const QString& token, callback_connected connected, callback_sent sent, callback_closed closed);
            void subscribe(const QString& destination, int id);
            void send(const QString& destination, const QString& json);
            void startStompConnection();
            void unsubscribe(const QString& destination, int id);
            ~StompSocket();
    private:
            QString m_url;
            int m_port;
            std::unordered_map<std::string, std::string> m_headers;
            QWebSocket m_webSocket;
            callback_sent sent;
            callback_connected connected;
            callback_closed closed;


    private Q_SLOTS:
            void onConnected();
            void onTextMessageReceived(QString message);
            void onClosed();
    };


}
#endif // STOMPSOCKET_H
