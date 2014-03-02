#include "mainui.h"
#include "ui_mainui.h"



MainUI::MainUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainUI)
{
    ui->setupUi(this);

    board_local = new BoardWidget();
    //TODO AI board

    ui->frmLocalGame->setVisible(false);
    ui->frmAIGame->setVisible(false);

    ui->frmLocalGame->layout()->addWidget(board_local);
//     ui->frmLocalGame->layout()->addWidget(board_local);

    connect(ui->cmdNewLocalGame,SIGNAL(clicked()),board_local,SLOT(newgame()));

}

MainUI::~MainUI() {
    delete ui;
    delete board_AI;
    delete board_local;
}

#include "mainui.moc"
