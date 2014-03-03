#-------------------------------------------------
#
# Project created by QtCreator 2014-03-03T20:08:33
#
#-------------------------------------------------

QT       -= gui

TARGET = GoCore
TEMPLATE = lib

DEFINES += GOCORE_LIBRARY

SOURCES += gocore.cpp

HEADERS += gocore.h \
    gocoreglobal.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

include(../imports.pri)

include(datahiding/godatahiding.pri)
include(observer/goobserver.pri)
