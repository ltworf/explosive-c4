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

QT       += core widgets

TARGET = explosive-c4
TEMPLATE = app

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11


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

TRANSLATIONS += \
    explosive-c4_it_IT.ts
CONFIG += lrelease
CONFIG += embed_translations

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

OTHER_FILES += \
    android/AndroidManifest.xml

isEmpty(target.path) {
    target.path = $${DESTDIR}/usr/games
    export(target.path)
}
INSTALLS += target

launcher.files = extras/explosive-c4.desktop
launcher.path = $${DESTDIR}/usr/share/applications/
INSTALLS += launcher

icon.files = extras/high/explosive-c4.svg
icon.path = $${DESTDIR}/usr/share/icons/hicolor/128x128/apps/
INSTALLS += icon

icon_low.files = extras/low/explosive-c4.svg
icon_low.path = $${DESTDIR}/usr/share/icons/hicolor/48x48/apps/
INSTALLS += icon_low

manpage.files = extras/explosive-c4.6
manpage.path = $${DESTDIR}/usr/share/man/man6/
INSTALLS += manpage

export(INSTALLS)
