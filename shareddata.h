#ifndef SHAREDDATA_H
#define SHAREDDATA_H

#include <QObject>
#include "argon2.h"

/*
 * enum HashType { argon2 = 0,
 *                 bcrypt = 1,
 *                 scrypt = 2
 *               }
 */

class SharedData : public QObject
{
    Q_OBJECT
public:
    explicit SharedData(QObject *parent = 0);

    static int getHashType();
    static void setHashType(const int &value);

    static quint8 getNumOfHashingOps();
    static void setNumOfHashingOps(const quint8 &value);

private:
    static int hashType;       // 0-argon2, 1-bcrypt, 2-scrypt
    static quint8 numOfHashingOps;

};

#endif // SHAREDDATA_H
