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

#ifndef BOARD_H
#define BOARD_H

#include <qt4/QtCore/qobject.h>

typedef enum {
    PLAYER_RED=1,
    PLAYER_YELLOW=~1,
} player_t;

typedef enum {
    CELL_EMPTY=0,
    CELL_RED=1,
    CELL_YELLOW=~1,
} cell_t;

class Board : public QObject {
    Q_OBJECT

public:
    Board();
    Board(unsigned int rows, unsigned int cols);
    Board(unsigned int rows, unsigned int cols, player_t initial);
    Board(player_t initial);
    ~Board();

    void get_size(unsigned int *rows, unsigned int *cols);
    bool place(unsigned int col, player_t player);
    cell_t get_content(unsigned int row, unsigned int col);
    player_t get_turn();

    void dump();

private:
    unsigned int rows;
    unsigned int cols;
    unsigned int size;
    cell_t *internal_board;

    player_t turn = PLAYER_RED;
    void check_winner(unsigned int row, unsigned int col);

signals:
    void winner(player_t);
    void changed(unsigned int row, unsigned int col);
};

#endif // BOARD_H
