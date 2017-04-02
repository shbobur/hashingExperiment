#include "scrypthash.h"
#include <QDebug>
#include <libscrypt.h>

SCryptHash::SCryptHash()
{
}

SCryptHash::~SCryptHash()
{

}

QString SCryptHash::hash()
{
    QString locHash = "";
    try {
        //char hash[SCRYPT_MCF_LEN];
        libscrypt_hash(output, pwd, SCRYPT_N, MY_SCRYPT_r, MY_SCRYPT_p);
        for (uint i = 0; i < strlen(output); i++) locHash += QString("%1").arg(output[i]);
    } catch (...) {
        qDebug() << "ScryptHash::hash(): some errors...";
    }

    return locHash;
}
