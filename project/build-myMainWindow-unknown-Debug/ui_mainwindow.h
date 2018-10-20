/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_N;
    QAction *actionopen;
    QAction *actionclose;
    QAction *actionsave;
    QAction *actionsaveas;
    QAction *actionexit;
    QAction *actionreturn;
    QAction *actioncut;
    QAction *actioncopy;
    QAction *actionpaste;
    QAction *actionfind;
    QAction *actionversion;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_H;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(659, 448);
        action_N = new QAction(MainWindow);
        action_N->setObjectName(QStringLiteral("action_N"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/myimages/image/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_N->setIcon(icon);
        actionopen = new QAction(MainWindow);
        actionopen->setObjectName(QStringLiteral("actionopen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/myimages/image/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionopen->setIcon(icon1);
        actionclose = new QAction(MainWindow);
        actionclose->setObjectName(QStringLiteral("actionclose"));
        actionsave = new QAction(MainWindow);
        actionsave->setObjectName(QStringLiteral("actionsave"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/myimages/image/saveas.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionsave->setIcon(icon2);
        actionsaveas = new QAction(MainWindow);
        actionsaveas->setObjectName(QStringLiteral("actionsaveas"));
        actionsaveas->setIcon(icon2);
        actionexit = new QAction(MainWindow);
        actionexit->setObjectName(QStringLiteral("actionexit"));
        actionreturn = new QAction(MainWindow);
        actionreturn->setObjectName(QStringLiteral("actionreturn"));
        actioncut = new QAction(MainWindow);
        actioncut->setObjectName(QStringLiteral("actioncut"));
        actioncopy = new QAction(MainWindow);
        actioncopy->setObjectName(QStringLiteral("actioncopy"));
        actionpaste = new QAction(MainWindow);
        actionpaste->setObjectName(QStringLiteral("actionpaste"));
        actionfind = new QAction(MainWindow);
        actionfind->setObjectName(QStringLiteral("actionfind"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/myimages/image/find.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionfind->setIcon(icon3);
        actionversion = new QAction(MainWindow);
        actionversion->setObjectName(QStringLiteral("actionversion"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 659, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QStringLiteral("menu_H"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        MainWindow->insertToolBarBreak(mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_H->menuAction());
        menu->addAction(action_N);
        menu->addAction(actionopen);
        menu->addAction(actionclose);
        menu->addSeparator();
        menu->addAction(actionsave);
        menu->addAction(actionsaveas);
        menu->addSeparator();
        menu->addAction(actionexit);
        menu_2->addAction(actionreturn);
        menu_2->addSeparator();
        menu_2->addAction(actioncut);
        menu_2->addAction(actioncopy);
        menu_2->addAction(actionpaste);
        menu_2->addSeparator();
        menu_2->addAction(actionfind);
        menu_H->addAction(actionversion);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_N);
        mainToolBar->addAction(actionopen);
        mainToolBar->addAction(actionsave);
        mainToolBar->addAction(actionfind);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action_N->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272(&N)", 0));
        action_N->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionopen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200(&N)", 0));
        actionopen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionclose->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255(&C)", 0));
        actionclose->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", 0));
        actionsave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230(&S)", 0));
        actionsave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionsaveas->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272(&A)", 0));
        actionexit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272(&X)", 0));
        actionexit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        actionreturn->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200(&Z)", 0));
        actionreturn->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0));
        actioncut->setText(QApplication::translate("MainWindow", "\345\211\252\345\210\207(&X)", 0));
        actioncut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0));
        actioncopy->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266(&C)", 0));
        actioncopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0));
        actionpaste->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264(&V)", 0));
        actionpaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", 0));
        actionfind->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276(&F)", 0));
        actionfind->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", 0));
        actionversion->setText(QApplication::translate("MainWindow", "\347\211\210\346\234\254\350\257\264\346\230\216", 0));
        actionversion->setShortcut(QApplication::translate("MainWindow", "Ctrl+H", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221(&E)", 0));
        menu_H->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
