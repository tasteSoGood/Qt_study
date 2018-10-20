#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void mousePressEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *);

private slots:
    void timerUpdate();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
