#include "stompsocket.h"
#include <chrono>
#include <thread>
#include <QtCore/QCoreApplication>


static std::string url = "ws://172.26.64.1:8080/game";
using namespace STOMP;
int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    qDebug() << "prikol(";

    StompSocket stompSocket(url);
    return a.exec();


}
