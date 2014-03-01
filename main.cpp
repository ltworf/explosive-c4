#include <QtGui/QApplication>
#include "explosive-c4.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    explosive_c4 foo;
    foo.show();
    return app.exec();
}
