#include "mainwindow.h"
#include <QApplication>
#include "logindialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    LoginDialog dlg;
    if(dlg.exec() == QDialog::Accepted) { // 如果登陆窗口返回accept()，则显示主页面
        w.show();
        return a.exec();
    } else {
        return 0;
    }
}
