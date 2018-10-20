#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QSound>
#include <QGridLayout>
#include <QKeyEvent>

/* debug:
 * 此处如果没有QSound类，需要做两步（linux平台下）
 * 1. 在pro文件最后加上 QT += multimedia
 * 2. 如果第一步报错，则需要在系统终端安装 sudo apt-get install qtmultimedia5-dev
 */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // 白键的长度和宽度
    int key_height = 100, key_width = 20;
    ui->setupUi(this);
    this->setStyleSheet("QPushButton {"
                        "border: 1px solid;"
                        "border-left: 0px;"
                        "border-radius: 0px;"
                        "padding: 0px;"
                        "margin: 0px;"
                        "}");
    setWindowTitle(tr("钢琴"));
    setMinimumSize(key_width * 52, key_height); // 白键有52个

    // 定义音名
    note_name = {
        "a0", "a0m", "b0",
        "c1", "c1m", "d1", "d1m", "e1", "f1", "f1m", "g1", "g1m", "a1", "a1m", "b1",
        "c2", "c2m", "d2", "d2m", "e2", "f2", "f2m", "g2", "g2m", "a2", "a2m", "b2",
        "c3", "c3m", "d3", "d3m", "e3", "f3", "f3m", "g3", "g3m", "a3", "a3m", "b3",
        "c4", "c4m", "d4", "d4m", "e4", "f4", "f4m", "g4", "g4m", "a4", "a4m", "b4",
        "c5", "c5m", "d5", "d5m", "e5", "f5", "f5m", "g5", "g5m", "a5", "a5m", "b5",
        "c6", "c6m", "d6", "d6m", "e6", "f6", "f6m", "g6", "g6m", "a6", "a6m", "b6",
        "c7", "c7m", "d7", "d7m", "e7", "f7", "f7m", "g7", "g7m", "a7", "a7m", "b7",
        "c8"
    };
    keys.resize(88); // 先resize，解决黑键不能叠在白键上面的bug

    // 产生音符
    for(int i = 0; i < 88; i++) {
        QSound *temp = new QSound(tr(":/notes/raw/%1.wav").arg(note_name[i]), this);
        notes.push_back(temp);
    }

    int white = 0, black = 0;
    int black_width = key_width * 0.7, black_height = key_height * 0.6;
    int black_pos[] = {1, 3, 4, 6, 7, 8, 10, 11, 13, 14, 15, 17, 18, 20, 21, 22, 24, 25, 27, 28, 29, 31, 32, 34, 35, 36, 38, 39, 41, 42, 43, 45, 46, 48, 49, 50}; // 黑键的位置（相对于白键）
    // 产生白键
    for(int i = 0; i < 88; i++) {
        if (!note_name[i].contains(tr("m"))) { // 白键
            QPushButton *temp_btn = new QPushButton(this);
            temp_btn->setGeometry((white++) * key_width, 0, key_width, key_height);
            temp_btn->setStyleSheet("QPushButton {"
                                    "background-color: #ffffff;"
                                    "}");
            keys[i] = temp_btn;
            connect(keys[i], SIGNAL(clicked()), notes[i], SLOT(play()));
        }
    }
    // 产生黑键
    for(int i = 0; i < 88; i++) {
        if (note_name[i].contains(tr("m"))) { // 黑键
            QPushButton *temp_btn = new QPushButton(this);
            temp_btn->setGeometry((key_width * black_pos[black++]) - black_width / 2 - 1, 0, black_width, black_height);
            temp_btn->setStyleSheet("QPushButton {"
                                    "background-color: #000000;"
                                    "}");
            keys[i] = temp_btn;
            connect(keys[i], SIGNAL(clicked()), notes[i], SLOT(play()));
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e) {
    QVector<int> keyboard({
        Qt::Key_A, Qt::Key_S, Qt::Key_D, Qt::Key_F, Qt::Key_G, Qt::Key_H, Qt::Key_J, Qt::Key_K
    });
    for(int i = 0; i < keyboard.size(); i++) {
        if (e->key() == keyboard[i]) {
            notes[i + 20]->play();
            if (note_name[i].contains(tr("m")))
                keys[i]->setStyleSheet("QPushButton {background-color: #444444}");
            else
                keys[i]->setStyleSheet("QPushButton {background-color: #aaaaaa}");
            break;
        }
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *e) {
    QVector<int> keyboard({
        Qt::Key_A, Qt::Key_S, Qt::Key_D, Qt::Key_F, Qt::Key_G, Qt::Key_H, Qt::Key_J, Qt::Key_K
    });
    for(int i = 0; i < keyboard.size(); i++) {
        if (e->key() == keyboard[i]) {
            if (note_name[i].contains(tr("m")))
                keys[i]->setStyleSheet("QPushButton {background-color: #000000}");
            else
                keys[i]->setStyleSheet("QPushButton {background-color: #ffffff}");
            break;
        }
    }
}
