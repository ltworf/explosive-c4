#ifndef MAINUI_H
#define MAINUI_H

#include <QWidget>

#include "boardwidget.h"

namespace Ui {
class MainUI;
}

class MainUI : public QWidget
{
    Q_OBJECT

public:
    explicit MainUI(QWidget *parent = 0);
    ~MainUI();

private:
    Ui::MainUI *ui;
    BoardWidget * board_local = NULL;
    BoardWidget * board_AI = NULL;
};

#endif // MAINUI_H
