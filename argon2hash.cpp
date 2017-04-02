#include "argon2hash.h"
#include <QDebug>
#include <argon2.h>

#include <stdio.h>

Argon2Hash::Argon2Hash()
{
    t_cost = 1;                             // n-pass computation
    m_cost = 1 << 14;                       // Default: 4 mebibytes memory usage
    parallelism = 1;
}

Argon2Hash::~Argon2Hash()
{
}

QString Argon2Hash::hash()
{
    QString locHash = "";
    try {
        int encode_len = argon2_encodedlen(t_cost, m_cost, parallelism, saltlen, HASHLEN, Argon2_d) + 1;
        char encode[encode_len];
        int ret = argon2d_hash_encoded(t_cost, m_cost, parallelism, (quint8*)pwd, pwdlen, (quint8*)salt, saltlen, HASHLEN, encode, encode_len);
        printf("%s\n", encode);
        if (ret == ARGON2_OK) {
            for (uint i = 0; i < strlen(encode); i++) locHash += QString("%1").arg(encode[i]);
        } else {
            qDebug() << "Argon2 Error: " << argon2_error_message(ret);
        }
    } catch (...) {
        qDebug() << "Argon2Hash::hash(): some errors...";
    }

    return locHash;
}
