#-------------------------------------------------
#
# Project created by QtCreator 2016-06-24T12:27:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Paint
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    canvas.cpp

HEADERS  += mainwindow.h \
    canvas.h

FORMS    += \
    mainwindow.ui

RESOURCES += \
    resource.qrc
