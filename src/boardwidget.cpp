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
#include <stdio.h>

#include "boardwidget.h"
#include "boardai.h"

// map cell type to pen and brush color
static QMap<cell_t, QPair<QColor, QColor> > cell_color;

static const QColor board_color0 = QColor("#434343");
static const QColor board_color1 = QColor("#333333");

static const QColor win_color0 = QColor("#f3f3f3");
static const QColor win_color1 = QColor("#030303");

static QLinearGradient board_gradient, ring_gradient;
static QLinearGradient win_gradient, ring_win_gradient;

BoardWidget::BoardWidget(boardwidget_t board_type) {
    QWidget();
    this->board_type = board_type;

    // initialize color table and gradients
    if (cell_color.empty()) {
        cell_color[CELL_RED]    = qMakePair(QColor("#ff4500"), Qt::red);
        cell_color[CELL_YELLOW] = qMakePair(Qt::yellow, QColor("#ffd700"));
        cell_color[CELL_EMPTY]  = qMakePair(Qt::white, Qt::white);

        board_gradient.setStart(0.73, 0.92);
        board_gradient.setFinalStop(0.4, 0.6);
        board_gradient.setCoordinateMode(QGradient::ObjectMode);
        board_gradient.setColorAt(0, board_color0);
        board_gradient.setColorAt(1, board_color1);

        ring_gradient = board_gradient;
        ring_gradient.setColorAt(0, board_color1);
        ring_gradient.setColorAt(1, board_color0);

        win_gradient = board_gradient;
        win_gradient.setColorAt(0, win_color0);
        win_gradient.setColorAt(1, win_color1);

        ring_win_gradient = win_gradient;
        ring_win_gradient.setColorAt(0, win_color1);
        ring_win_gradient.setColorAt(1, win_color0);
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

    int rows;
    int cols;
    board->get_size(&rows,&cols);

    int w_max = size.width()  / cols;
    int h_max = size.height() / rows;
    diameter = w_max < h_max ? w_max : h_max;

    // we want the hole to take ~3/4th of a cell, so the offset
    // for the circle within the cell is 1/8 of the cell width.
    // we want at least 1px anyway
    int hole_offset = diameter < 8 ? 1 : diameter/8;
    // the hole ring is half the hole_offset.
    // it's OK if this is 0, which only happens for very small boards
    // (in this case there will be no ring)
    int ring_offset = hole_offset/2;
    // ensure that the hole_offset is even (rounds down)
    if (ring_offset > 0)
	    hole_offset = ring_offset*2;

    // the hole diameter will be what's left from the cell diameter
    // given symmetric offset
    int hole_diam = diameter - 2*hole_offset;
    int ring_diam = diameter - 2*ring_offset;

    int grid_width  = diameter*cols;
    int grid_height = diameter*rows;
    margin_x = (size.width()  - grid_width )/2;
    margin_y = (size.height() - grid_height)/2;

    painter.fillRect(0, 0, size.width(), size.height(), Qt::black);
    painter.fillRect(margin_x, margin_y, grid_width, grid_height, board_gradient);

    painter.setRenderHint(QPainter::Antialiasing, true);

    for (int r=0; r<rows;r++){
        for (int c=0; c<cols;c++) {
            bool winner_pos = (c==winner_col and r==winner_row);
            int x_corner = margin_x + diameter*c;
            int y_corner = margin_y + diameter*r;
            if (winner_pos)
                painter.fillRect(x_corner, y_corner, diameter, diameter, win_gradient);

            cell_t cell = board->get_content(r,c);

            painter.setPen(QPen(cell_color[cell].first, ring_offset));
            painter.setBrush(QBrush(cell_color[cell].second, Qt::SolidPattern));

            painter.drawEllipse(x_corner + hole_offset, y_corner + hole_offset, hole_diam, hole_diam);

	    if (ring_offset > 0) {
		    painter.setPen( QPen((winner_pos ? ring_win_gradient : ring_gradient), ring_offset) );
		    painter.setBrush( Qt::NoBrush );
		    painter.drawEllipse(x_corner + ring_offset, y_corner + ring_offset, ring_diam, ring_diam);
	    }

        }

    }

}

void BoardWidget::changed(int row, int col) {
    update(margin_x + col*diameter, margin_y + row*diameter, diameter, diameter);
}


void BoardWidget::mousePressEvent(QMouseEvent *ev) {
    QWidget::mousePressEvent(ev);
    int column = (ev->position().x() - margin_x) / diameter;

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
