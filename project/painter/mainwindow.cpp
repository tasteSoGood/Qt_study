#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "paintarea.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMinimumSize(500, 500);

    paintArea *paint_area = new paintArea(this);
    setCentralWidget(paint_area);
}

MainWindow::~MainWindow()
{
    delete ui;
}
