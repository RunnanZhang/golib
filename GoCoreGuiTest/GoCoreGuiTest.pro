#-------------------------------------------------
#
# Project created by QtCreator 2014-03-03T20:09:14
#
#-------------------------------------------------

QT      += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET   = GoCoreGuiTest
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h \
    mainwindow_p.h

FORMS   += mainwindow.ui

include(../imports.pri)

LIBS    += -lGoCore
