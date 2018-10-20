#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H
#include <QDialog>
class QLabel;
class QLineEdit;
class QPushButton;

class LoginDialog : public QDialog
{
    Q_OBJECT // 使用信号和槽等特性必须添加该宏
public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog(); // 析构函数
private:
    QLabel *usrLabel;
    QLabel *pwdLabel;
    QLineEdit *usrLineEdit;
    QLineEdit *pwdLineEdit;
    QPushButton *loginBtn;
    QPushButton *exitBtn;
private slots:
    void login();
};

#endif // LOGINDIALOG_H
