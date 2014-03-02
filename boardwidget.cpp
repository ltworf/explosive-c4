/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2014  Salvo Tomaselli <tiposchi@tiscali.it>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <QtGui/QPainter>
#include <QtGui/QMouseEvent>
#include <QtGui/QColor>
#include <QtGui/QBrush>

#include "boardwidget.h"

BoardWidget::BoardWidget() {
    QWidget();
    board = new Board(6,7);
    connect(board,
            SIGNAL(changed(unsigned int,unsigned int)),
            this,
            SLOT(changed(unsigned int, unsigned int))
           );
    connect(board,
            SIGNAL(winner(player_t,unsigned int,unsigned int)),
            this,
            SLOT(winner(player_t,unsigned int,unsigned int))
           );
}

BoardWidget::~BoardWidget() {
    delete board;
}

void BoardWidget::winner(player_t winner, unsigned int row, unsigned int col) {
    winner_row = row;
    winner_col = col;
}


void BoardWidget::paintEvent(QPaintEvent * p) {
    QWidget::paintEvent(p);
    QPainter painter(this);

    QSize size = this->size();

    painter.fillRect(0,0,size.width(),size.height(),QColor(0,0,0));

    unsigned int rows;
    unsigned int cols;
    board->get_size(&rows,&cols);

    unsigned int w_max = size.width() / cols;
    unsigned int h_max = size.height() / rows;
    diameter = w_max < h_max ? w_max : h_max;

    painter.setRenderHint(QPainter::Antialiasing, true);

    //TODO full circles
    for (unsigned int r=0; r<rows;r++){
        for (unsigned int c=0; c<cols;c++) {
            cell_t cell = board->get_content(r,c);
             switch (cell) {
                case CELL_RED:
                    painter.setPen(QPen(Qt::red, 1));
                    painter.setBrush(QBrush (Qt::red,Qt::SolidPattern));
                    break;
                case CELL_YELLOW:
                    painter.setPen(QPen(Qt::yellow, 1));
                    painter.setBrush(QBrush (Qt::yellow,Qt::SolidPattern));
                    break;
                case CELL_EMPTY:
                    painter.setPen(QPen(Qt::white, 1));
                    painter.setBrush(QBrush (Qt::white,Qt::SolidPattern));
                    break;
            }

            if (c==winner_col and r==winner_row)
                painter.fillRect(diameter*c,diameter*r,diameter-2,diameter-2,QColor(255,255,255));


            painter.drawEllipse(diameter*c,diameter*r,diameter-2,diameter-2);
        }

    }

}

void BoardWidget::changed(unsigned int row, unsigned int col) {
    update(col*diameter,row*diameter,diameter,diameter);
}




void BoardWidget::mousePressEvent(QMouseEvent *ev) {
    QWidget::mousePressEvent(ev);
    int column = ev->x() / diameter;

    unsigned int rows;
    unsigned int cols;
    board->get_size(&rows,&cols);

    if (column >= cols)
        return;

    player_t t = board->get_turn();
    board->place(column,t);
}


QSize BoardWidget::minimumSizeHint() {
    unsigned int rows;
    unsigned int cols;
    board->get_size(&rows,&cols);

    return QSize(cols*30,rows*30);
}

QSize BoardWidget::sizeHint() {
    unsigned int rows;
    unsigned int cols;
    board->get_size(&rows,&cols);

    return QSize(cols*diameter,rows*diameter);
}


#include "boardwidget.moc"
