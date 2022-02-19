# explosive-c4
# Copyright (C) 2014-2022 Salvo "LtWorf" Tomaselli
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as
# published by the Free Software Foundation, either version 3 of the
# License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Affero General Public License for more details.
#
# You should have received a copy of the GNU Affero General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.
#
# author Salvo "LtWorf" Tomaselli <tiposchi@tiscali.it>


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

