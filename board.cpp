/*
 * explosive-c4
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
#include <stdio.h>

#include "board.h"

Board::Board() {
    Board(6,7);
}

Board::Board(int rows, int cols, player_t initial): QObject() {
    turn = initial;
    Board(rows,cols);
}

Board::Board(player_t initial): QObject() {
    turn = initial;
    Board();
}



Board::Board(int rows, int cols): QObject() {
    this->rows = rows;
    this->cols = cols;
    this->size = rows*cols;

    this->internal_board = new cell_t[size];
    memset(internal_board, 0, size*sizeof(cell_t));
}


Board::~Board() {
    delete this->internal_board;
}

void Board::get_size(int *rows, int *cols) {
    *rows = this->rows;
    *cols = this->cols;
}

bool Board::place(int col, player_t player) {

    if (turn != player || completed)
        return false;

    int current_cell = col+((rows-1)*cols);

    while (current_cell>=0) {

        if (this->internal_board[current_cell] == CELL_EMPTY) {
            int row = (current_cell-col)/cols;

            this->internal_board[current_cell] = (cell_t)player;
            turn = (player_t)~turn;
            check_winner(row,col);
            emit changed(row,col);
            return true;
        } else {
            current_cell -= cols;
        }

    }

    return false;
}

void Board::check_winner(int row, int col) {

    cell_t current = get_content(row,col);
    player_t current_player = (player_t)current;


    //Horizontal
    {
        int count = 0;
        for (int i = col - 3; i <= col + 3; i++) {

            if (get_content(row,i) == current)
                count++;
            else
                count = 0;

            if (count == 4) {
                goto win;
            }
        }
    }

    //Vertical
    {
        int count = 0;
        for (int i = row+1; i <=row+3; i++) {
            if (get_content(i,col) == current)
                count ++;
        }
        if (count == 3)
            goto win;
    }
    return;
win:
    emit winner(current_player,row,col);
    completed = true;
}

player_t Board::get_turn() {
    return turn;
}


void Board::dump() {
    for (int r=0;r<rows;r++) {
        for (int c=0;c<cols;c++) {
            char cell;
            switch (this->internal_board[r*cols+c]) {
                case CELL_EMPTY:
                    cell= '.';
                    break;
                case CELL_RED:
                    cell='X';
                    break;
                case CELL_YELLOW:
                    cell='O';
                    break;
            }
            printf ("%c ",cell);
        }
        printf("\n");
    }
}

cell_t Board::get_content(int row, int col) {
    if (row<rows && col < cols)
        return this->internal_board[col+row*cols];
    else
        return CELL_EMPTY;
}


#include "board.moc"
