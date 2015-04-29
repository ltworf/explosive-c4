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
#include <unordered_set>

#include "boardai.h"


bool BoardAI::place(int col, player_t player) {

    bool r = Board::place(col,player);

    if (!r)
        return false;

    if (player != this->aiplayer) {
        //Play AI round
        airound();
    }

    return true;

}

void BoardAI::airound() {

    player_t other_player = (player_t)~aiplayer;

    //Do nothing if the game is already over
    if (this->completed) {
        return;
    }

    //Win in 1 move
    {
        for (int c=0; c<this->cols; c++) {
            int r = free_slot(c);

            if (r != -1 && winning_move(r,c,aiplayer)) {
                printf("Win in 1 move\n");
                place(c,aiplayer);
                return;
            }

        }
    }

    //Prevent win in 1 move
    {
        for (int c=0; c<this->cols; c++) {
            int r = free_slot(c);

            if (r != -1 && winning_move(r,c,other_player)) {
                printf("Prevent win in 1 move\n");
                place(c,aiplayer);
                return;
            }
        }
    }

    //Block lineup of 3 central pieces

    //Horizontal
    {
        for (int row = 0; row< this->rows; row ++) {
            for (int col = 1; col < this->cols-2; col++) {
                if (
                (
                get_content(row,col-1) == CELL_EMPTY &&
                get_content(row,col) == (cell_t)other_player &&
                get_content(row,col+1) == (cell_t)other_player &&
                get_content(row,col+2) == CELL_EMPTY
                ) ||
                (
                get_content(row,col-1) == CELL_EMPTY &&
                get_content(row,col) == (cell_t)other_player &&
                get_content(row,col+1) == CELL_EMPTY &&
                get_content(row,col+2) == (cell_t)other_player
                )) {
                    int r1 = free_slot(col-1);
                    int r2= free_slot(col+2);
                    int r3 = free_slot(col+1);

                    if (r1== row) {
                        printf("Prevent horizontal lineup of 3 pieces %d\n",__LINE__);
                        place(col-1, aiplayer);
                        return;
                    } else if (r2== row){
                        printf("Prevent horizontal lineup of 3 pieces %d\n",__LINE__);
                        place(col+2,aiplayer);
                        return;
                    } else if (r3== row) {
                        printf("Prevent horizontal lineup of 3 pieces %d\n",__LINE__);
                        place(col+1,aiplayer);
                        return;
                    }
                }
            }
        }
    }
    //Diagonal
    {
        for (int row = 1; row< this->rows-1; row ++) {
            for (int col = 2; col < this->cols-2; col++) {
                if (
                (
                get_content(row-1,col-1) == CELL_EMPTY &&
                get_content(row,col) == (cell_t)other_player &&
                get_content(row+1,col+1) == (cell_t)other_player &&
                get_content(row+2,col+2) == CELL_EMPTY
                ) ||
                (
                get_content(row-1,col-1) == CELL_EMPTY &&
                get_content(row,col) == (cell_t)other_player &&
                get_content(row+1,col+1) == CELL_EMPTY &&
                get_content(row+2,col+2) == (cell_t)other_player
                )) {
                    int r1 = free_slot(col-1);
                    int r2= free_slot(col+2);
                    int r3 = free_slot(col+1);

                    if (r1== row-1) {
                        place(col-1, aiplayer);
                        printf("Prevent diagonal lineup of 3 pieces %d\n",__LINE__);
                        return;
                    } else if (r2== row+2){
                        place(col+2,aiplayer);
                        printf("Prevent diagonal lineup of 3 pieces %d\n",__LINE__);
                        return;
                    } else if (r3== row+1) {
                        place(col+1,aiplayer);
                        printf("Prevent diagonal lineup of 3 pieces %d\n",__LINE__);
                        return;
                    }
                }
            }
        }
    }
    {
        for (int row = 1; row< this->rows-1; row ++) {
            for (int col = 2; col < this->cols-2; col++) {
                if (
                (
                get_content(row+1,col-1) == CELL_EMPTY &&
                get_content(row,col) == (cell_t)other_player &&
                get_content(row-1,col+1) == (cell_t)other_player &&
                get_content(row-2,col+2) == CELL_EMPTY
                ) ||
                (
                get_content(row+1,col-1) == CELL_EMPTY &&
                get_content(row,col) == (cell_t)other_player &&
                get_content(row-1,col+1) == CELL_EMPTY &&
                get_content(row-2,col+2) == (cell_t)other_player
                )) {
                    int r1 = free_slot(col-1);
                    int r2= free_slot(col+2);
                    int r3 = free_slot(col+1);

                    if (r1== row+1) {
                        place(col-1, aiplayer);
                        printf("Prevent diagonal lineup of 3 pieces %d\n",__LINE__);
                        return;
                    } else if (r2== row-2){
                        place(col+2,aiplayer);
                        printf("Prevent diagonal lineup of 3 pieces %d\n",__LINE__);
                        return;
                    } else if (r3== row-1) {
                        place(col+1,aiplayer);
                        printf("Prevent diagonal lineup of 3 pieces %d\n",__LINE__);
                        return;
                    }
                }
            }
        }
    }


    //play randomly but blacklist some columns
    {
        printf("Randomly… %d\n",__LINE__);
        std::unordered_set<int> allowed_columns;
        for (int c=0; c< this->cols;c++)
            allowed_columns.insert(c);

        for (int c=0; c< this->cols;c++) {
            int r = free_slot(c)-1;
            if (r>=0 && winning_move(r,c,other_player)) {
                allowed_columns.erase(c);
            }
        }


            int c;
            do {
                c = rand() % this->cols;
                if ((!allowed_columns.empty()) && (allowed_columns.find(c) != allowed_columns.end()))
                    continue;
            } while(!this->place(c,this->aiplayer));
    }
}
