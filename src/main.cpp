/*
explosive-c4
Copyright (C) 2014-2021 Salvo "LtWorf" Tomaselli

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

author Salvo "LtWorf" Tomaselli <tiposchi@tiscali.it>
*/


#include <QApplication>
#include <QTranslator>
#include <QLocale>


#include "mainui.h"

#include "board.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    app.setApplicationName("explosive-c4");
    app.setOrganizationDomain("explosive-c4");
    app.setOrganizationName("explosive-c4");

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "explosive-c4_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

    MainUI* foo = new MainUI();
    foo->show();
    return app.exec();

}
