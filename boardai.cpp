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

    if (this->completed) {
        return;
    }

    //Win in 1 move
    {
        for (int c=0; c<this->cols; c++) {
            int r = free_slot(c);

            if (r != -1 && winning_move(r,c,aiplayer)) {
                place(c,aiplayer);
                return;
            }

        }
    }

    //Play randomly
    {
        int c;
        do {
            c = rand() % this->cols;
        } while(!this->place(c,this->aiplayer));
    }
}
