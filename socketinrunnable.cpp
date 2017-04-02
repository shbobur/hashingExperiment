#include "socketinrunnable.h"
#include "argon2.h"

#include <QTime>
#include <QElapsedTimer>
#include "shareddata.h"

SocketInRunnable::SocketInRunnable(int handle) : descriptor(handle)
{
    thisHash = "";

    hashingFunctions[0] = new Argon2Hash();
    hashingFunctions[1] = new BCryptHash();
    hashingFunctions[2] = new SCryptHash();
}

SocketInRunnable::~SocketInRunnable()
{
}

void SocketInRunnable::run()
{
    QTcpSocket *socket = new QTcpSocket();
    socket->setSocketDescriptor(descriptor);

    socket->waitForReadyRead();
    QString requestID = QString(socket->readAll());

    QString currentTime = QTime::currentTime().toString();

    QElapsedTimer timer;
    timer.start();                          // start timer
    hash();
    qint64 hashingTime = timer.elapsed();      // get time
    timer.invalidate();

    socket->write(QString("(" + requestID + "): " + thisHash + "|" + QString::number(hashingTime / 1000.0)).toLatin1());
    socket->waitForBytesWritten();

    qDebug() << "OK: " << currentTime << " " << thisHash << " " << QString::number(hashingTime / 1000.0);

    socket->disconnectFromHost();
    socket->close();
    socket->deleteLater();
}

void SocketInRunnable::hash()
{
    qsrand(QTime::currentTime().msec());

    int hashType = sharedData.getHashType();

    thisHash = "";
    for (int i = 0; i < sharedData.getNumOfHashingOps(); i++) {
        hashingFunctions[hashType]->setPass("password.");
        hashingFunctions[hashType]->setSalt("saltsaltsalt");
        thisHash += hashingFunctions[hashType]->hash();
    }
}
