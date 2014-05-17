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

/**
 * @brief Board::Board
 *
 * Default board: 6*7, red player starts
 */
Board::Board() {
    init(6,7,PLAYER_RED);
}

Board::Board(int rows, int cols, player_t initial): QObject() {
    init(rows,cols,initial);
}

/**
 * @brief Board::Board
 * @param initial: the player which starts
 *
 * Default 6*7 board
 */
Board::Board(player_t initial): QObject() {
    init(6,7,initial);
}

/**
 * @brief Board::Board
 * @param rows
 * @param cols
 *
 * Red player starts
 */
Board::Board(int rows, int cols): QObject() {
    init(rows,cols,PLAYER_RED);
}

void Board::init(int rows, int cols, player_t initial) {
    this->turn = initial;
    this->rows = rows;
    this->cols = cols;
    this->size = rows*cols;

    this->internal_board = new cell_t[size];
    memset(internal_board, 0, size*sizeof(cell_t));
}


Board::~Board() {
    delete this->internal_board;
}

/**
 * @brief Board::get_size
 * @param rows
 * @param cols
 *
 * The pointed variables will be set with
 * the values of rows and columns.
 */
void Board::get_size(int *rows, int *cols) {
    *rows = this->rows;
    *cols = this->cols;
}

/**
 * @brief Board::free_slot
 * @param col
 * @return the position of the free
 * slot in the column, or -1 if
 * there is no free slot.
 */
int Board::free_slot(int col) {

    int current_cell = col+((rows-1)*cols);

    while (current_cell>=0) {
        if (this->internal_board[current_cell] == CELL_EMPTY) {
            int row = (current_cell-col)/cols;
            return row;
        } else {
            current_cell -= cols;
        }
    }

    return -1;
}

/**
 * @brief Board::place
 * @param col
 * @param player
 * @return
 *
 * Player makes a move and drops in column.
 *
 * Returns false if the player can't play there,
 * can't play at all or if the game is over
 */
bool Board::place(int col, player_t player) {

    if (turn != player || completed)
        return false;


    int row = this->free_slot(col);

    if (row == -1) {
        return false;
    }

    this->internal_board[col+row*cols] = (cell_t)player;
    turn = (player_t)~turn;
    emit changed(row,col);
    check_winner(row,col);
    return true;
}

void Board::check_winner(int row, int col) {

    cell_t current = get_content(row,col);
    player_t current_player = (player_t)current;

    // diagonal
    {
        int count = 0;
        for (int i = -3; i<=col+3; i++) {
            if (get_content(row+i,col+i) == current)
                count++;
            else
                count = 0;

            if (count == 4) {
                goto win;
            }
        }
    }

    {
        int count = 0;
        for (int i = -3; i<=col+3; i++) {
            if (get_content(row+i,col-i) == current)
                count++;
            else
                count = 0;

            if (count == 4) {
                goto win;
            }
        }
    }

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

/**
 * @brief Board::get_turn
 * @return the player that needs to play
 */
player_t Board::get_turn() {
    return turn;
}

/**
 * @brief Board::dump
 *
 * Prints the board on stdout
 */
void Board::dump() {
    for (int r=0;r<rows;r++) {
        for (int c=0;c<cols;c++) {
            char cell;
            switch (this->internal_board[r*cols+c]) {
                case CELL_RED:
                    cell='X';
                    break;
                case CELL_YELLOW:
                    cell='O';
                    break;
                default:
                    cell= '.';
                    break;
            }
            printf ("%c ",cell);
        }
        printf("\n");
    }
}


/**
 * @brief Board::get_content
 * @param row
 * @param col
 * @return the content for the specified cell.
 *
 * Boundary checks are performed so if the cell
 * is out of the board, it is considered as an
 * empty cell.
 */
cell_t Board::get_content(int row, int col) {
    if (row<rows && col < cols)
        return this->internal_board[col+row*cols];
    else
        return CELL_EMPTY;
}
