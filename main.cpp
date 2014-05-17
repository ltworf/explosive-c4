#include <QApplication>


#include "mainui.h"

#include "board.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    MainUI* foo = new MainUI();
    foo->show();
    return app.exec();

/*
    Board *b = new Board(7,7);

    b->place(0,PLAYER_RED);
    b->place(0,PLAYER_YELLOW);
    b->place(0,PLAYER_YELLOW);
    b->place(0,PLAYER_YELLOW);

    b->place(6,PLAYER_RED);

    b->dump();*/
}
