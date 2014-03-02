#include <QtGui/QApplication>
#include "explosive-c4.h"

#include "board.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    explosive_c4 foo;
    foo.show();
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
