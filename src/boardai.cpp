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

#include <QSet>

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

    //Blacklist columns that would make the opponent win
    QSet<int> blacklist;
    {
        for (int c=0; c< this->cols; c++) {
            int r = free_slot(c);
            if (r == -1 || (r> 0 && winning_move(r-1,c,other_player)))
                    blacklist << c;

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

                    if (r1== row && !blacklist.contains(col-1)) {
                        printf("Prevent horizontal lineup of 3 pieces %d\n",__LINE__);
                        place(col-1, aiplayer);
                        return;
                    } else if (r2== row && !blacklist.contains(col+2)){
                        printf("Prevent horizontal lineup of 3 pieces %d\n",__LINE__);
                        place(col+2,aiplayer);
                        return;
                    } else if (r3== row&& !blacklist.contains(col+1)) {
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

                    if (r1== row-1&& !blacklist.contains(col-1)) {
                        place(col-1, aiplayer);
                        printf("Prevent diagonal lineup of 3 pieces %d\n",__LINE__);
                        return;
                    } else if (r2== row+2&& !blacklist.contains(col+2)){
                        place(col+2,aiplayer);
                        printf("Prevent diagonal lineup of 3 pieces %d\n",__LINE__);
                        return;
                    } else if (r3== row+1&& !blacklist.contains(col+1)) {
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

                    if (r1== row+1&& !blacklist.contains(col-1)) {
                        place(col-1, aiplayer);
                        printf("Prevent diagonal lineup of 3 pieces %d\n",__LINE__);
                        return;
                    } else if (r2== row-2&& !blacklist.contains(col+2)){
                        place(col+2,aiplayer);
                        printf("Prevent diagonal lineup of 3 pieces %d\n",__LINE__);
                        return;
                    } else if (r3== row-1&& !blacklist.contains(col+1)) {
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
        printf("Randomly… %d: ",__LINE__);
        int c;
        while (true) {
            c = rand() % this->cols;
            printf("Selecting column %d\n",c);

            if (blacklist.contains(c) && blacklist.size() < this->cols)
                continue;
            if (this->place(c,this->aiplayer))
                break;
        }
    }
}
