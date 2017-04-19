#ifndef SOCKETINRUNNABLE_H
#define SOCKETINRUNNABLE_H

#include <QRunnable>
#include <QTcpSocket>
#include <QDebug>
#include <QTime>

#include "hash.h"
#include "argon2hash.h"
#include "bcrypthash.h"
#include "scrypthash.h"
#include "sha512hash.h"

#include "shareddata.h"

//#define HASH_FUNCS 3
//#define MAX_NUM_OF_FUNCS 32

class SocketInRunnable : public QRunnable
{
public:
    SocketInRunnable(int handle);
    ~SocketInRunnable();
    void run();

private:
    int descriptor;
    SharedData sharedData;
    QString thisHash;

    Hash* hashingFunctions[4];

    void hash();

};

#endif // SOCKETINRUNNABLE_H
