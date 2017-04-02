#ifndef ARGON2HASH_H
#define ARGON2HASH_H

#include "hash.h"

#define ENCODED_LEN 128

class Argon2Hash : public Hash
{
public:
    Argon2Hash();
    ~Argon2Hash();

    QString hash();
    bool verify(QString pass, QString encodedHash);

private:
    quint32 t_cost;            // n-pass computation
    quint32 m_cost;                       // 4 mebibytes memory usage
    quint32 parallelism;                // number of threads and lanes

};

#endif // ARGON2HASH_H
