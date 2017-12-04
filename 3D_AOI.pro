TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt
QT += xml
QT += core
QT += sql

SOURCES += \ 
    DB/blob.cpp \
    DB/sqlitedb.cpp \
    DB/sqlitedbtest.cpp \
    src/App/appsetting.cpp \
    src/App/capturesetting.cpp \
    src/App/mainwindow.cpp \
    src/Job/board.cpp \
    src/Job/inspectiondata.cpp \
    src/Job/measuredobj.cpp \
    src/Job/measuredobjlist.cpp \
    src/SDK/customexception.cpp \
    src/SDK/rectangle.cpp \
    src/main.cpp


HEADERS += \ 
    DB/blob.hpp \
    DB/sqlitedb.hpp \
    DB/sqlitedbtest.hpp \
    src/App/appsetting.hpp \
    src/App/capturesetting.hpp \
    src/App/mainwindow.hpp \
    src/Job/board.hpp \
    src/Job/inspectiondata.hpp \
    src/Job/measuredobj.hpp \
    src/Job/measuredobjlist.hpp \
    src/SDK/customexception.hpp \
    src/SDK/datahelper.hpp \
    src/SDK/rectangle.hpp


DISTFILES +=

INCLUDEPATH += $$PWD/include/sqlite
INCLUDEPATH += $$PWD/include

unix: : LIBS += -L$$PWD/../../../lib/ -lsqlite3

unix:LIBS +=  -L/usr/lib/x86_64-linux-gnu\
-ldl
