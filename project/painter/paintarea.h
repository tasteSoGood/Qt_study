#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QWidget>
#include <QVector>
#include <QPainterPath>

class paintArea : public QWidget
{
    Q_OBJECT
public:
    explicit paintArea(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

signals:

public slots:

private:
    QVector<QPainterPath *> path_list;
    QPainterPath current_path;
};

#endif // PAINTAREA_H
