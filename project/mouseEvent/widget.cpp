#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
#include <QKeyEvent>
#include <QDateTime>
#include <QTimer>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    setWindowTitle(tr("鼠标点击及键盘事件"));
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::timerUpdate);
    timer->start(1000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *e) {
    ui->pushButton->setText(tr("%1, %2").arg(e->x()).arg(e->y()));
}

void Widget::keyPressEvent(QKeyEvent *e) {
    int x = ui->pushButton->x();
    int y = ui->pushButton->y();
    switch (e->key()) {
    case Qt::Key_W:
        ui->pushButton->move(x, y - 10);
        break;
    case Qt::Key_S:
        ui->pushButton->move(x, y + 10);
        break;
    case Qt::Key_A:
        ui->pushButton->move(x - 10, y);
        break;
    case Qt::Key_D:
        ui->pushButton->move(x + 10, y);
        break;
    }
}

void Widget::timerUpdate() {
    QDateTime time = QDateTime::currentDateTime();
    ui->label->setText(time.toString("yyyy-MM-dd hh:mm:ss dddd"));
}
