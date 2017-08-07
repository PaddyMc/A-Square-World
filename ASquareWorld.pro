#-------------------------------------------------
#
# Project created by QtCreator 2014-11-01T19:40:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ASquareWorld
TEMPLATE = app


SOURCES += main.cpp\
        startwindow.cpp \
    introwindow.cpp \
    gamewindow.cpp \
    item.cpp \
    player.cpp \
    enemy.cpp \
    winner.cpp \
    loser.cpp

HEADERS  += startwindow.h \
    introwindow.h \
    gamewindow.h \
    item.h \
    player.h \
    enemy.h \
    winner.h \
    loser.h

FORMS    += startwindow.ui \
    introwindow.ui \
    gamewindow.ui \
    winner.ui \
    loser.ui

RESOURCES += \
    images.qrc
