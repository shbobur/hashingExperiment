#include "shareddata.h"

int SharedData::hashType;
quint8 SharedData::numOfHashingOps;

SharedData::SharedData(QObject *parent) :
    QObject(parent)
{
}

int SharedData::getHashType()
{
    return hashType;
}

void SharedData::setHashType(const int &value)
{
    hashType = value;
}
quint8 SharedData::getNumOfHashingOps()
{
    return numOfHashingOps;
}

void SharedData::setNumOfHashingOps(const quint8 &value)
{
    numOfHashingOps = value;
}

