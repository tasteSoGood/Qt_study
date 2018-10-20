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

## debug(QSound报错的问题)

如果没有QSound类，需要做两步（linux平台下）
1. 在pro文件最后加上 QT += multimedia
2. 如果第一步报错，则需要在系统终端安装 sudo apt-get install qtmultimedia5-dev

## QSS(Qt Style Sheet)

QSS的设计理念和网页设计中的CSS文件是一样的，其语法也是CSS的一个子集，可以直接拿来使用。这种设计理念的初衷是将对象的逻辑和对象的样式分离，这对application的样式设计是很有帮助的。由于已经有Web设计的经验，这部分的内容就不再赘述了。

和CSS一样，QSS也有两种使用方法，一种是在代码中直接添加，比如有一个对象`QObject *obj`，那么它的样式可以直接写作：

```c++
obj->setStyleSheet("QObject {"
                   		"width: 10px;"
                   		"height: 10px;"
                   "}");
```

此处如果不在样式表前加特定的类型，会出现无法解析的错误。

还有一种就是样式表和代码的完全分离，直接新建一个.qss文件在工程目录中，然后将这个文件加载为项目的资源文件，最后在代码中加载此文件。具体的步骤之后需要大量样式设计的时候再给出。

加入样式表说明了Qt的设计理念是很完善的，这大大增加了软件的弹性，减小了设计的复杂度。