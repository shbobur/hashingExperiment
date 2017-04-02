#include "bcrypthash.h"
#include <QDebug>
#include <stdio.h>
#include <bcrypt.h>

BCryptHash::BCryptHash()
{
}

BCryptHash::~BCryptHash()
{
    
}

QString BCryptHash::hash()
{
    QString locHash = "";
    try {
        char salt[HASHLEN];
        Q_ASSERT(bcrypt_gensalt(WORK_FACTOR, salt) == 0);
        Q_ASSERT(bcrypt_hashpw(pwd, salt, output) == 0);

        for (uint i = 0; i < strlen(output); i++) locHash += QString("%1").arg(output[i]);
    } catch (...) {
        qDebug() << "BCryptHash::hash(): Some erros...";
    }

    return locHash;
}
