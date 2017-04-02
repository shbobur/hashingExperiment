#-------------------------------------------------
#
# Project created by QtCreator 2017-03-29T16:56:32
#
#-------------------------------------------------

QT       += core network gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ThreeHashesEvaluation
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    argon2hash.cpp \
    hash.cpp \
    scrypthash.cpp \
    bcrypthash.cpp \
    form.cpp \
    multithreadserver.cpp \
    shareddata.cpp \
    socketinrunnable.cpp

HEADERS += \
    argon2hash.h \
    hash.h \
    scrypthash.h \
    bcrypthash.h \
    form.h \
    multithreadserver.h \
    shareddata.h \
    socketinrunnable.h

LIBS += -largon2 -lscrypt


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/bcrypt/release/ -lbcrypt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/bcrypt/debug/ -lbcrypt
else:unix: LIBS += -L$$PWD/bcrypt/ -lbcrypt

INCLUDEPATH += $$PWD/bcrypt
DEPENDPATH += $$PWD/bcrypt

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/bcrypt/release/libbcrypt.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/bcrypt/debug/libbcrypt.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/bcrypt/release/bcrypt.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/bcrypt/debug/bcrypt.lib
else:unix: PRE_TARGETDEPS += $$PWD/bcrypt/libbcrypt.a

FORMS += \
    form.ui
