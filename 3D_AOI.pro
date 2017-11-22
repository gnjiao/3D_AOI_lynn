TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    measuredobj.cpp \
    customexception.cpp \
    measuredobjlist.cpp \
    board.cpp

HEADERS += \
    rectangle.h \
    customexception.h \
    measuredobj.hpp \
    measuredobjlist.hpp \
    board.h
