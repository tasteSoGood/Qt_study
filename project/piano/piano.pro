#-------------------------------------------------
#
# Project created by QtCreator 2018-10-20T17:40:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = piano
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    notes.qrc

QT += multimedia

CONFIG += C++11
