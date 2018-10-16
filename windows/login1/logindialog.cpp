#include "logindialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent) : QDialog(parent)
{
    usrLabel = new QLabel(this); // 实例化Lable并用本对话框作为父对象进行初始化
    usrLabel->move(70, 80);
    usrLabel->setText("用户名");
    usrLineEdit = new QLineEdit(this);
    usrLineEdit->move(140, 80);
    usrLineEdit->setPlaceholderText(tr("请输入用户名"));

    pwdLabel = new QLabel(this);
    pwdLabel->move(70, 130);
    pwdLabel->setText("密码");
    pwdLineEdit = new QLineEdit(this);
    pwdLineEdit->move(140, 130);
    pwdLineEdit->setPlaceholderText(tr("请输入密码"));

    loginBtn = new QPushButton(this);
    loginBtn->move(50, 200);
    loginBtn->setText(tr("登陆"));
    exitBtn = new QPushButton(this);
    exitBtn->move(210, 200);
    exitBtn->setText(tr("退出"));

    // 信号和槽
    connect(loginBtn, &QPushButton::clicked, this, &LoginDialog::login); // 在头文件中定义了login槽
    connect(exitBtn, &QPushButton::clicked, this, &LoginDialog::close);
}

LoginDialog::~LoginDialog() {
}

void LoginDialog::login() {
    if(usrLineEdit->text().trimmed() == tr("taster") && pwdLineEdit->text() == tr("123456")) {
        accept(); // signal
    } else {
        QMessageBox::warning(this, tr("警告"), tr("用户名或密码错误"), QMessageBox::Yes);
        // 清空，定位光标
        usrLineEdit->clear();
        pwdLineEdit->clear();
        usrLineEdit->setFocus();
    }
}
