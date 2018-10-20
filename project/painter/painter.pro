#-------------------------------------------------
#
# Project created by QtCreator 2018-10-19T15:35:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = painter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    paintarea.cpp

HEADERS  += mainwindow.h \
    paintarea.h

FORMS    += mainwindow.ui
