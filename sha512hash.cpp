#include "sha512hash.h"
#include <openssl/sha.h>
#include <string.h>
#include <QDebug>

SHA512hash::SHA512hash()
{
}

SHA512hash::~SHA512hash()
{
}

QString SHA512hash::hash()
{
    QString locHash = "";

    try {
        unsigned char digest[SHA512_DIGEST_LENGTH];
        int len = pwdlen + saltlen;
        char str[len];
        strcat(str, pwd);
        strcat(str, salt);

        SHA512((unsigned char*)str, strlen(str), (unsigned  char*)digest);

        char mdString[SHA512_DIGEST_LENGTH*2+1 + saltlen];
        for(int i = 0; i < SHA512_DIGEST_LENGTH; i++)
            sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);

        for (uint i = 0; i < strlen(mdString); i++) locHash += QString("%1").arg(mdString[i]);

    } catch (...) {
        qDebug() << "SHA512hash: some errors ...";
    }

    return locHash;
}
