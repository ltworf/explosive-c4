#include "explosive-c4.h"

#include <QtGui/QMenuBar>
#include <QtGui/QAction>

#include "mainui.h"

explosive_c4::explosive_c4() {
    mainui = new MainUI(this);
    setCentralWidget(mainui);

    setPalette(mainui->palette());
    resize(457, 640);

    setWindowTitle("explosive-c4");

//     QAction* a = new QAction(this);
//     a->setText( "Quit" );
//     connect(a, SIGNAL(triggered()), SLOT(close()) );
}

explosive_c4::~explosive_c4() {
    delete mainui;
}

#include "explosive-c4.moc"
