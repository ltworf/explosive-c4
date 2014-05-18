#-------------------------------------------------
#
# Project created by QtCreator 2014-05-12T20:46:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = explosive-c4
TEMPLATE = app


SOURCES += \
    main.cpp \
    mainui.cpp \
    boardwidget.cpp \
    boardai.cpp \
    board.cpp

HEADERS  += \
    mainui.h \
    boardwidget.h \
    board.h \
    boardai.h

FORMS    += \
    mainui.ui

CONFIG += mobility
MOBILITY = 
CONFIG += c++11

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

OTHER_FILES += \
    android/AndroidManifest.xml

