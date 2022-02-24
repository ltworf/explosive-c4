/*
explosive-c4
Copyright (C) 2014-2022 Salvo "LtWorf" Tomaselli

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


#include "mainui.h"
#include "ui_mainui.h"

MainUI::MainUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainUI)
{
    ui->setupUi(this);

    resize(457, 640);

    setWindowTitle("explosive-c4");

    board_local = new BoardWidget(BOARD_WIDGET_LOCAL);
    board_AI = new BoardWidget(BOARD_WIDGET_AI);

    ui->frmLocalGame->setVisible(false);
    ui->frmAIGame->setVisible(false);
    ui->frmAbout->setVisible(false);

    ui->frmLocalGame->layout()->addWidget(board_local);
    ui->frmAIGame->layout()->addWidget(board_AI);

    connect(ui->cmdNewLocalGame,SIGNAL(clicked()),board_local,SLOT(newgame()));
    connect(ui->cmdNewAIGame,SIGNAL(clicked()),board_AI,SLOT(newgame()));
}

MainUI::~MainUI() {
    delete ui;
    delete board_AI;
    delete board_local;
}
