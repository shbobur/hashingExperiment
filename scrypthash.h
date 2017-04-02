#ifndef SCRYPTHASH_H
#define SCRYPTHASH_H

#include "hash.h"

#define MY_SCRYPT_r 16
#define MY_SCRYPT_p 1

class SCryptHash : public Hash
{
public:
    SCryptHash();
    ~SCryptHash();

    QString hash();
};

#endif // SCRYPTHASH_H
