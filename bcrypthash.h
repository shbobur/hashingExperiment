#ifndef BCRYPTHASH_H
#define BCRYPTHASH_H

#include "hash.h"

#define WORK_FACTOR 12

class BCryptHash : public Hash
{
public:
    BCryptHash();
    ~BCryptHash();

    QString hash();
};

#endif // BCRYPTHASH_H
