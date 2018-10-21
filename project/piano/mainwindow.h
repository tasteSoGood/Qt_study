#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSound>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
    void timerEvent(QTimerEvent *);

private:
    Ui::MainWindow *ui;
    QVector<QString> note_name; // 音名
    QVector<QSound *> notes; // 音符
    QVector<QPushButton *> keys; // 琴键
    int section_cnt, note_cnt;
    QVector< QVector< QVector<int> > > music; // 曲谱
};

#endif // MAINWINDOW_H
