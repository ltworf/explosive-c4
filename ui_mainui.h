/********************************************************************************
** Form generated from reading UI file 'mainui.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINUI_H
#define UI_MAINUI_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainUI
{
public:
    QHBoxLayout *horizontalLayout_2;
    QFrame *frmInitial;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_4;
    QPushButton *cmdLocalGame;
    QSpacerItem *verticalSpacer;
    QPushButton *cmdIAGame;
    QSpacerItem *verticalSpacer_2;
    QPushButton *cmdNetworkGame;
    QSpacerItem *verticalSpacer_3;
    QFrame *frmAIGame;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *cmdLocalBackAI;
    QPushButton *cmdNewAIGame;
    QFrame *frmLocalGame;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *cmdLocalBack;
    QPushButton *cmdNewLocalGame;

    void setupUi(QWidget *MainUI)
    {
        if (MainUI->objectName().isEmpty())
            MainUI->setObjectName(QString::fromUtf8("MainUI"));
        MainUI->resize(457, 640);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush2);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush3(QColor(15, 15, 15, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush1);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush);
        QBrush brush4(QColor(255, 0, 255, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Link, brush4);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush5(QColor(255, 128, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush1);
        QBrush brush6(QColor(128, 128, 128, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush2);
        QBrush brush7(QColor(88, 88, 88, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush1);
        QBrush brush8(QColor(114, 114, 114, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush2);
        MainUI->setPalette(palette);
        MainUI->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        horizontalLayout_2 = new QHBoxLayout(MainUI);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        frmInitial = new QFrame(MainUI);
        frmInitial->setObjectName(QString::fromUtf8("frmInitial"));
        frmInitial->setFrameShape(QFrame::NoFrame);
        frmInitial->setFrameShadow(QFrame::Plain);
        frmInitial->setLineWidth(0);
        verticalLayout = new QVBoxLayout(frmInitial);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_4 = new QSpacerItem(20, 24, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        cmdLocalGame = new QPushButton(frmInitial);
        cmdLocalGame->setObjectName(QString::fromUtf8("cmdLocalGame"));
        cmdLocalGame->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        cmdLocalGame->setAutoDefault(false);
        cmdLocalGame->setFlat(true);

        verticalLayout->addWidget(cmdLocalGame);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        cmdIAGame = new QPushButton(frmInitial);
        cmdIAGame->setObjectName(QString::fromUtf8("cmdIAGame"));
        cmdIAGame->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        cmdIAGame->setAutoDefault(false);
        cmdIAGame->setFlat(true);

        verticalLayout->addWidget(cmdIAGame);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        cmdNetworkGame = new QPushButton(frmInitial);
        cmdNetworkGame->setObjectName(QString::fromUtf8("cmdNetworkGame"));
        cmdNetworkGame->setEnabled(false);
        cmdNetworkGame->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        cmdNetworkGame->setAutoDefault(false);
        cmdNetworkGame->setFlat(true);

        verticalLayout->addWidget(cmdNetworkGame);

        verticalSpacer_3 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        horizontalLayout_2->addWidget(frmInitial);

        frmAIGame = new QFrame(MainUI);
        frmAIGame->setObjectName(QString::fromUtf8("frmAIGame"));
        frmAIGame->setFrameShape(QFrame::NoFrame);
        frmAIGame->setFrameShadow(QFrame::Plain);
        verticalLayout_2 = new QVBoxLayout(frmAIGame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        cmdLocalBackAI = new QPushButton(frmAIGame);
        cmdLocalBackAI->setObjectName(QString::fromUtf8("cmdLocalBackAI"));

        horizontalLayout_3->addWidget(cmdLocalBackAI);

        cmdNewAIGame = new QPushButton(frmAIGame);
        cmdNewAIGame->setObjectName(QString::fromUtf8("cmdNewAIGame"));

        horizontalLayout_3->addWidget(cmdNewAIGame);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_2->addWidget(frmAIGame);

        frmLocalGame = new QFrame(MainUI);
        frmLocalGame->setObjectName(QString::fromUtf8("frmLocalGame"));
        frmLocalGame->setFrameShape(QFrame::NoFrame);
        frmLocalGame->setFrameShadow(QFrame::Plain);
        verticalLayout_3 = new QVBoxLayout(frmLocalGame);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cmdLocalBack = new QPushButton(frmLocalGame);
        cmdLocalBack->setObjectName(QString::fromUtf8("cmdLocalBack"));

        horizontalLayout->addWidget(cmdLocalBack);

        cmdNewLocalGame = new QPushButton(frmLocalGame);
        cmdNewLocalGame->setObjectName(QString::fromUtf8("cmdNewLocalGame"));

        horizontalLayout->addWidget(cmdNewLocalGame);


        verticalLayout_3->addLayout(horizontalLayout);


        horizontalLayout_2->addWidget(frmLocalGame);


        retranslateUi(MainUI);
        QObject::connect(cmdLocalBack, SIGNAL(clicked()), frmLocalGame, SLOT(hide()));
        QObject::connect(cmdLocalBack, SIGNAL(clicked()), frmInitial, SLOT(show()));
        QObject::connect(cmdLocalGame, SIGNAL(clicked()), frmInitial, SLOT(hide()));
        QObject::connect(cmdLocalGame, SIGNAL(clicked()), frmLocalGame, SLOT(show()));
        QObject::connect(cmdLocalBackAI, SIGNAL(clicked()), frmInitial, SLOT(show()));
        QObject::connect(cmdLocalBackAI, SIGNAL(clicked()), frmAIGame, SLOT(hide()));
        QObject::connect(cmdIAGame, SIGNAL(clicked()), frmAIGame, SLOT(show()));
        QObject::connect(cmdIAGame, SIGNAL(clicked()), frmInitial, SLOT(hide()));

        QMetaObject::connectSlotsByName(MainUI);
    } // setupUi

    void retranslateUi(QWidget *MainUI)
    {
        MainUI->setWindowTitle(QApplication::translate("MainUI", "Form", 0, QApplication::UnicodeUTF8));
        cmdLocalGame->setText(QApplication::translate("MainUI", "Two local players", 0, QApplication::UnicodeUTF8));
        cmdIAGame->setText(QApplication::translate("MainUI", "Play against computer", 0, QApplication::UnicodeUTF8));
        cmdNetworkGame->setText(QApplication::translate("MainUI", "Play on the network", 0, QApplication::UnicodeUTF8));
        cmdLocalBackAI->setText(QApplication::translate("MainUI", "\342\206\220", 0, QApplication::UnicodeUTF8));
        cmdNewAIGame->setText(QApplication::translate("MainUI", "\342\206\235", 0, QApplication::UnicodeUTF8));
        cmdLocalBack->setText(QApplication::translate("MainUI", "\342\206\220", 0, QApplication::UnicodeUTF8));
        cmdNewLocalGame->setText(QApplication::translate("MainUI", "\342\206\235", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainUI: public Ui_MainUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINUI_H
