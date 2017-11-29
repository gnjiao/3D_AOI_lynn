TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt
QT += xml
QT += core
QT += sql

SOURCES += main.cpp \
    App/appsetting.cpp \
    App/capturesetting.cpp \
    Job/board.cpp \
    Job/inspectiondata.cpp \
    Job/measuredobjlist.cpp \
    SDK/customexception.cpp \
    App/app.cpp \
    DB/blob.cpp \
    DB/sqlitedb.cpp \
    DB/sqlitedbtest.cpp


HEADERS += \
    App/appsetting.hpp \
    App/capturesetting.hpp \
    Job/board.hpp \
    Job/inspectiondata.hpp \
    Job/measuredobj.hpp \
    Job/measuredobjlist.hpp \
    SDK/customexception.hpp \
    SDK/rectangle.hpp \
    App/app.h \
    SDK/datahelper.hpp \
    DB/blob.hpp \
    DB/sqlitedb.hpp \
    DB/sqlitedbtest.hpp


DISTFILES +=

INCLUDEPATH += $$PWD/include/sqlite
INCLUDEPATH += $$PWD/include

unix: : LIBS += -L$$PWD/../../../lib/ -lsqlite3

unix:LIBS +=  -L/usr/lib/x86_64-linux-gnu\
-ldl
