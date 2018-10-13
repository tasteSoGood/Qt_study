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