#include <QApplication>
#include <QDebug>
#include <QElapsedTimer>

#include "form.h"

#include "hash.h"
#include "argon2hash.h"
#include "scrypthash.h"
#include "bcrypthash.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Form f;
    f.show();

    return a.exec();
}
