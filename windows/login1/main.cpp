#include "mainwindow.h"
#include <QApplication>
#include "logindialog.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    LoginDialog dlg;
    if (dlg.exec() == QDialog::Accepted) {
        // 某种意义上来说，这也是一种connect，用来将show()槽与从logindialog传过来的accept()信号连接起来
        w.show();
        return a.exec();
    } else {
        return 0;
    }
}
