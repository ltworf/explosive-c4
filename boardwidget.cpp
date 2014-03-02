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

#include "boardwidget.h"

BoardWidget::BoardWidget() {
    QWidget();
    board = new Board(7,7);
}

BoardWidget::~BoardWidget() {
    delete board;
}

void BoardWidget::paintEvent(QPaintEvent * p) {
    QWidget::paintEvent(p);
    QPainter painter(this);

    QSize size = this->size();

    unsigned int rows;
    unsigned int cols;
    board->get_size(&rows,&cols);

    unsigned int w_max = size.width() / cols;
    unsigned int h_max = size.height() / rows;
    unsigned int diameter = w_max < h_max ? w_max : h_max;

    painter.setRenderHint(QPainter::Antialiasing, true);

    for (unsigned int r=0; r<rows;r++){
        for (unsigned int c=0; c<cols;c++) {
            cell_t cell = board->get_content(r,c);
             switch (cell) {
                case CELL_RED:
                    painter.setPen(QPen(Qt::red, 1));
                    break;
                case CELL_YELLOW:
                    painter.setPen(QPen(Qt::yellow, 1));
                    break;
                case CELL_EMPTY:
                    painter.setPen(QPen(Qt::white, 1));
                    break;
            }

            painter.drawEllipse(diameter*r,diameter*c,diameter-2,diameter-2);
        }

    }

}


#include "boardwidget.moc"
