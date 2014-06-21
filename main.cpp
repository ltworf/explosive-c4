#include <QApplication>


#include "mainui.h"

#include "board.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    MainUI* foo = new MainUI();
    foo->show();
    return app.exec();

}
