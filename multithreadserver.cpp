#include "multithreadserver.h"

#include "socketinrunnable.h"

MultiThreadServer::MultiThreadServer(QObject *parent) :
    QTcpServer(parent)
{
}

void MultiThreadServer::incomingConnection(qintptr handle)
{
    SocketInRunnable* runnable = new SocketInRunnable(handle);
    QThreadPool::globalInstance()->start(runnable);
}

void MultiThreadServer::startListening()
{
    if (listen(QHostAddress::Any, 12345)) {
        qDebug() << "Listening to port 12345...";
    }
    else {
        qDebug() << "Error while starting: ";
    }

}
