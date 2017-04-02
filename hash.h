#ifndef HASH_H
#define HASH_H

#include <QString>

#define HASHLEN 64

class Hash {
public:
    Hash();
    virtual ~Hash();

    bool setSalt(QString new_salt);
    bool setPass(QString new_pass);
    virtual QString hash() = 0;

protected:
    quint32 pwdlen;
    char *pwd;
    quint32 saltlen;
    char *salt;
    char *output;
};

#endif // HASH_H
