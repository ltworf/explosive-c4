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

#include <QMap>
#include <QPair>
#include <QPainter>
#include <QMouseEvent>
#include <QColor>
#include <QBrush>

#include "boardwidget.h"
#include "boardai.h"

// map cell type to pen and brush color
static QMap<cell_t, QPair<QColor, QColor> > cell_color;


BoardWidget::BoardWidget(boardwidget_t board_type) {
    QWidget();
    this->board_type = board_type;

    // initialize color table
    if (cell_color.empty()) {
        cell_color[CELL_RED]    = qMakePair(QColor("#ff4500"), Qt::red);
        cell_color[CELL_YELLOW] = qMakePair(Qt::yellow, QColor("#ffd700"));
        cell_color[CELL_EMPTY]  = qMakePair(Qt::white, Qt::white);
    }

    init();
}

void BoardWidget::init() {
    if (board!=NULL) {
        delete board;
    }
    switch (board_type) {
        case BOARD_WIDGET_LOCAL:
            board = new Board();
            break;
        case BOARD_WIDGET_AI:
            board = new BoardAI();
            break;
        case BOARD_WIDGET_NETWORK:
            //TODO something about this
            break;
    }
    connect(board,
            SIGNAL(changed(int,int)),
            this,
            SLOT(changed(int,int))
           );
    connect(board,
            SIGNAL(winner(player_t,int, int)),
            this,
            SLOT(winner(player_t, int, int))
           );
    QSize size = this->size();
    update(0,0,size.width(),size.height());
}

BoardWidget::~BoardWidget() {
    delete board;
}

void BoardWidget::winner(player_t winner, int row, int col) {
    winner_row = row;
    winner_col = col;
}

void BoardWidget::newgame() {
    winner_col = winner_row = -1;
    init();
}


void BoardWidget::paintEvent(QPaintEvent * p) {
    QWidget::paintEvent(p);
    QPainter painter(this);

    QSize size = this->size();

    painter.fillRect(0,0,size.width(),size.height(),QColor(0,0,0));

    int rows;
    int cols;
    board->get_size(&rows,&cols);

    int w_max = size.width() / cols;
    int h_max = size.height() / rows;
    diameter = w_max < h_max ? w_max : h_max;

    int hole_diam = diameter - 2;
    if (diameter > 8) {
        hole_diam = diameter*7/8;
    }
    int hole_offset = (diameter - hole_diam)/2;

    painter.setRenderHint(QPainter::Antialiasing, true);

    for (int r=0; r<rows;r++){
        for (int c=0; c<cols;c++) {
            cell_t cell = board->get_content(r,c);
            painter.setPen(QPen(cell_color[cell].first, hole_offset));
            painter.setBrush(QBrush(cell_color[cell].second, Qt::SolidPattern));

            if (c==winner_col and r==winner_row)
                painter.fillRect(diameter*c,diameter*r,diameter,diameter,QColor(255,255,255));


            painter.drawEllipse(diameter*c+hole_offset,diameter*r+hole_offset,hole_diam,hole_diam);
        }

    }

}

void BoardWidget::changed(int row, int col) {
    update(col*diameter,row*diameter,diameter,diameter);
}


void BoardWidget::mousePressEvent(QMouseEvent *ev) {
    QWidget::mousePressEvent(ev);
    int column = ev->x() / diameter;

    int rows;
    int cols;
    board->get_size(&rows,&cols);

    if (column >= cols)
        return;

    player_t t = board->get_turn();
    board->place(column,t);
}


QSize BoardWidget::minimumSizeHint() {
    int rows;
    int cols;
    board->get_size(&rows,&cols);

    return QSize(cols*30,rows*30);
}

QSize BoardWidget::sizeHint() {
    int rows;
    int cols;
    board->get_size(&rows,&cols);

    return QSize(cols*diameter,rows*diameter);
}
