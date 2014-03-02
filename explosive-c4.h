#ifndef explosive_c4_H
#define explosive_c4_H

#include <QtGui/QMainWindow>

#include "mainui.h"

class explosive_c4 : public QMainWindow
{
Q_OBJECT
public:
    explosive_c4();
    virtual ~explosive_c4();
private:
    MainUI *mainui;
};

#endif // explosive_c4_H
