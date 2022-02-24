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

#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>

#include "board.h"

typedef enum {
    BOARD_WIDGET_LOCAL,
    BOARD_WIDGET_AI,
    BOARD_WIDGET_NETWORK,
} boardwidget_t;

class BoardWidget : public QWidget {
    Q_OBJECT

public:
    BoardWidget(boardwidget_t);
    ~BoardWidget();

    virtual QSize sizeHint();
    virtual QSize minimumSizeHint();

protected:
    virtual void mousePressEvent(QMouseEvent *);
    virtual void paintEvent(QPaintEvent *);

public slots:
    void newgame();

private slots:
    void changed(int row, int col);
    void winner(player_t winner,int row, int col);


private:
    Board * board = NULL;
    int diameter;
    int winner_row = -1;
    int winner_col = -1;
    boardwidget_t board_type;

    void init();
};

#endif // BOARDWIDGET_H
