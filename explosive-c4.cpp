#include "explosive-c4.h"

#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QAction>

#include "boardwidget.h"

explosive_c4::explosive_c4()
{
    BoardWidget *boardwidget = new BoardWidget();
    setCentralWidget( boardwidget );
    QAction* a = new QAction(this);
    a->setText( "Quit" );
    connect(a, SIGNAL(triggered()), SLOT(close()) );
    menuBar()->addMenu( "File" )->addAction( a );
}

explosive_c4::~explosive_c4()
{}

#include "explosive-c4.moc"
