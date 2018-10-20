# Qt笔记

## 第一条

在编译Qt5项目的时候，需要在.pro文件最后添加一行

```c++
QT += widgets
```

## 第二条

`SIGNAL`和`SLOT`宏是Qt语法中的两个很重要的宏，比如这句话

```c++
QObject::connect(button, SIGNAL(clicked()), &app, SLOT(quit()));
```

就将quit()行为与clicked()动作在button实体上连接起来，这句话就定义了一个完整的事件-处理链条。

## 第三条

Qt编程最常用的方式是

1. 声明所需的窗口部件
2. 设置它们所应该具备的属性
3. 把这些窗口部件添加到布局中

## 信号与槽

就像第二条所说的，信号与槽是非常重要的两个概念，现在我们来先梳理以下编写并运行一个可执行的Qt程序的大致步骤：

Qt遵守着严格的MVC模型，即`Model-View-Controller`，在创建一个应用的时候，以`./project/login1`中的项目代码为例，模型部分有着明显的父子关系的结构：

```
QApplication a->
	|
	-> MainWindow w
	-> LoginDialog dlg->
		|
		-> QLabel usrLabel
		-> QLabel pwdLabel
		-> QLineEdit usrLineEdit
		-> QLineEdit pwdLineEdit
		-> QPushButton loginBtn
		-> QPushButton exitBtn
```

控件的创建都是以父对象的this指针初始化的（这里的父子关系不是指类继承关系，而是模块之间的父子关系）

而信号和槽的机制就是在父对象中定义的，在`logindialog.cpp`中可以看到，`LoginDialog`对象中定义了信号和槽的连接关系

```c++
connect(loginBtn, &QPushButton::clicked, this, &LoginDialog::login);
connect(exitBtn, &QPushButton::clicked, this, &LoginDialog::close);
```

connect函数的原型是这样的：

```c++
bool QObject::connect(
    const QObject *sender,            // 信号的发出者
    const char *singal,               // 信号
    const QObject *receiver,          // 信号的接收者
    const char *member                // 槽
) [static]
```

我们可以说，信号是对象发出的一个**请求**，而槽是另一个对象对这个请求做出的**响应**。两者从本质上来说都是函数，但是在模型中所处的地位不同。