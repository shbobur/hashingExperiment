#include "hash.h"

Hash::Hash()
{
    output = new char[HASHLEN * 2];
    Q_CHECK_PTR(output);
}

Hash::~Hash()
{
    delete output;
    delete pwd;
    delete salt;
}

bool Hash::setSalt(QString new_salt)
{
    try {
        saltlen = (quint32)new_salt.length();
        salt = new char[saltlen];
        Q_CHECK_PTR(salt);
        memcpy( salt, new_salt.toLatin1().data(), saltlen);
    } catch (...) {
        return false;
    }

    return true;
}

bool Hash::setPass(QString new_pass)
{
    try {
        pwdlen = new_pass.length();
        pwd = new char[pwdlen];
        Q_CHECK_PTR(pwd);
        memcpy( pwd, new_pass.toLatin1().data(), pwdlen);
    } catch(...) {
        return false;
    }

    return true;
}
