#ifndef SHA512HASH_H
#define SHA512HASH_H

#include "hash.h"

class SHA512hash : public Hash
{
public:
    SHA512hash();
    ~SHA512hash();

    QString hash();
};

#endif // SHA512HASH_H
