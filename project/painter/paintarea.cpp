#include "paintarea.h"
#include <QPainter>
#include <QPainterPath>
#include <QMouseEvent>

paintArea::paintArea(QWidget *parent) : QWidget(parent) {
    setAutoFillBackground(true);
    QPalette pal = palette();
    pal.setBrush(QPalette::Background, Qt::white);
    setPalette(pal); // 设置背景颜色
}

void paintArea::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setBrush(Qt::blue);
    foreach(QPainterPath *line, path_list) {
        painter.drawPath(*line);
    }
}

void paintArea::mousePressEvent(QMouseEvent *e) {
    QPainterPath temp_path;
    current_path = temp_path;
    current_path.moveTo(e->x(), e->y());
}

void paintArea::mouseMoveEvent(QMouseEvent *e) {
    current_path.lineTo(e->x(), e->y());
    update();
}

void paintArea::mouseReleaseEvent(QMouseEvent *e) {
    current_path.lineTo(e->x(), e->y());
    path_list.append(&current_path);
}
