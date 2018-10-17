#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* 创建一个菜单项的流程
     * 1. 添加菜单项到菜单栏
     * 2. 向新建的菜单项中添加动作
     */
    QMenu *menu_E = ui->menuBar->addMenu(tr("编辑(&E)")); // 创建

    QAction *findAction = new QAction(tr("&Find"), this); // 添加动作
    QIcon icon2(":/myimages/image/find.png");
    findAction->setIcon(icon2);
    findAction->setShortcut(QKeySequence(tr("Ctrl+F")));
    menu_E->addAction(findAction);

    // 向已有的菜单项中添加动作
    QAction *openAction = new QAction(tr("&Open"), this);
    QIcon icon(":/myimages/image/open.png"); // 使用资源文件，需要在最开始使用冒号，然后添加前缀，之后才是文件的路径
    openAction->setIcon(icon);
    openAction->setShortcut(QKeySequence(tr("Ctrl+O")));
    ui->menu->addAction(openAction);
}

MainWindow::~MainWindow()
{
    delete ui;
}
