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
    DB/blob.cpp \
    DB/sqlitedb.cpp \
    DB/sqlitedbtest.cpp \
    App/mainwindow.cpp \
    Job/measuredobj.cpp \
    SDK/rectangle.cpp


HEADERS += \
    App/appsetting.hpp \
    App/capturesetting.hpp \
    Job/board.hpp \
    Job/inspectiondata.hpp \
    Job/measuredobj.hpp \
    Job/measuredobjlist.hpp \
    SDK/customexception.hpp \
    SDK/rectangle.hpp \
    SDK/datahelper.hpp \
    DB/blob.hpp \
    DB/sqlitedb.hpp \
    DB/sqlitedbtest.hpp \
    App/mainwindow.hpp \
    Job/measuredobj.hpp


DISTFILES +=

INCLUDEPATH += $$PWD/include/sqlite
INCLUDEPATH += $$PWD/include

unix: : LIBS += -L$$PWD/../../../lib/ -lsqlite3

unix:LIBS +=  -L/usr/lib/x86_64-linux-gnu\
-ldl
