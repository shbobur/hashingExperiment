#ifndef MULTITHREADSERVER_H
#define MULTITHREADSERVER_H

#include <QTcpServer>
#include <QThreadPool>

#include "shareddata.h"

class MultiThreadServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MultiThreadServer(QObject *parent = 0);

    void incomingConnection(qintptr handle);

    void startListening();

public slots:

private:
    QThreadPool* threadPool;
    SharedData *data;

};

#endif // MULTITHREADSERVER_H
