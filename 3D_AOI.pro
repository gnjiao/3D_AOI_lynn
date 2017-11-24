TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt
QT += xml
QT += core

SOURCES += main.cpp \
    App/appsetting.cpp \
    App/capturesetting.cpp \
    Job/board.cpp \
    Job/inspectiondata.cpp \
    Job/measuredobj.cpp \
    Job/measuredobjlist.cpp \
    SDK/customexception.cpp

HEADERS += \
    App/appsetting.hpp \
    App/capturesetting.hpp \
    Job/board.hpp \
    Job/inspectiondata.hpp \
    Job/measuredobj.hpp \
    Job/measuredobjlist.hpp \
    SDK/customexception.hpp \
    SDK/rectangle.hpp
