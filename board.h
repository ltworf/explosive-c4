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

#include <QObject>

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
    Board(int rows, int cols);
    Board(int rows, int cols, player_t initial);
    Board(player_t initial);
    ~Board();

    void get_size(int *rows, int *cols);
    virtual bool place(int col, player_t player);
    cell_t get_content(int row, int col);
    player_t get_turn();

    void dump();

protected:
    int rows;
    int cols;
    int size;
    cell_t *internal_board;

    player_t turn = PLAYER_RED;
    void check_winner(int row, int col);
    void init(int rows, int cols, player_t initial);
    int free_slot(int col);

    bool completed = false;

signals:
    void winner(player_t,int row, int col);
    void changed(int row, int col);
};

#endif // BOARD_H
