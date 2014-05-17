#include "mainui.h"
#include "ui_mainui.h"

MainUI::MainUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainUI)
{
    ui->setupUi(this);

    resize(457, 640);

    setWindowTitle("explosive-c4");

    board_local = new BoardWidget(BOARD_WIDGET_LOCAL);
    board_AI = new BoardWidget(BOARD_WIDGET_AI);

    ui->frmLocalGame->setVisible(false);
    ui->frmAIGame->setVisible(false);

    ui->frmLocalGame->layout()->addWidget(board_local);
    ui->frmAIGame->layout()->addWidget(board_AI);

    connect(ui->cmdNewLocalGame,SIGNAL(clicked()),board_local,SLOT(newgame()));
    connect(ui->cmdNewAIGame,SIGNAL(clicked()),board_AI,SLOT(newgame()));
}

MainUI::~MainUI() {
    delete ui;
    delete board_AI;
    delete board_local;
}
