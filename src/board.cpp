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
    this->free_cells = rows*cols;

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
    if ((--this->free_cells) == 0)
        completed = true;
    check_winner(row,col);
    return true;
}

/**
 * @brief Board::winning_move
 * Check if playing in row,col is a winning move.
 *
 * It doesn't check if it's a valid move.
 *
 *
 * @param row
 * @param col
 * @return
 */
bool Board::winning_move(int row, int col, player_t player) {

    //Store the previous value of the cell
    cell_t previous = get_content(row,col);

    this->internal_board[col+row*cols] = (cell_t)player;

    cell_t current = (cell_t)player;

    // diagonal
    {
        printf("Diagonal 1\n");
        int count = 0;
        for (int i = -3; i<=3; i++) {
            if (get_content(row+i,col+i) == current)
                count++;
            else
                count = 0;

            printf("\tcount: %d\ti: %d\trow+i: %d\tcol+i: %d\tcontent: %d\n",count,i,row+i,col+i, get_content(row+i,col+i));

            if (count == 4) {
                goto win;
            }
        }
        printf("End Diagonal 1\n");
    }

    {
        printf("Diagonal 2\n");
        int count = 0;
        for (int i = -3; i<=3; i++) {
            if (get_content(row+i,col-i) == current)
                count++;
            else
                count = 0;

            printf("\tcount: %d\ti: %d\trow+i: %d\tcol+i: %d\tcontent: %d\n",count,i,row+i,col+i, get_content(row+i,col+i));

            if (count == 4) {
                goto win;
            }

        }
        printf("End Diagonal 2\n");
    }

    //Horizontal
    {
        printf("Horizontal\n");
        int count = 0;
        for (int i = col - 3; i <= col + 3; i++) {

            if (get_content(row,i) == current)
                count++;
            else
                count = 0;

            printf("\tcount: %d\ti: %d\trow+i: %d\tcol+i: %d\tcontent: %d\n",count,i,row,col, get_content(row,i));

            if (count == 4) {
                goto win;
            }
        }
        printf("End horizontal\n");
    }

    //Vertical
    {
        printf("Vertical\n");
        int count = 0;
        for (int i = row+1; i <=row+3; i++) {
            if (get_content(i,col) == current)
                count ++;
        }


        if (count == 3)
            goto win;
        printf("End vertical\n");
    }

    this->internal_board[col+row*cols] = previous;
    return false;
win:
    this->internal_board[col+row*cols] = previous;
    printf("END GAME\n");
    return true;
}

void Board::check_winner(int row, int col) {

    player_t player = (player_t)get_content(row,col);

    if (winning_move(row, col, player)) {
        emit winner(player,row,col);
        completed = true;
    }
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
    if (row<rows && col < cols && row>= 0 && col >= 0)
        return this->internal_board[col+row*cols];
    else
        return CELL_EMPTY;
}
