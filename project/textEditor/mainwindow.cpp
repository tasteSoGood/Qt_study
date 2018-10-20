#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextEdit>
#include <QGridLayout>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowTitle(tr("文本编辑器"));
    setMinimumSize(500, 500); // 仅设置最小的大小，相关的设置还有setFixedSize和setMaximumSize
    /* 文件(a+f)
     * 		打开(c+o)
     * 		新建(c+n) -> newFile()
     * 		保存(c+s) -> saveFile()
     * 		另存为
     * 		退出(c+w)
     * 编辑(a+e)
     * 		复制(c+c) -> copyText()
     * 		粘贴(c+v) -> pasteText()
     * 		查找(c+f)
     */

    QMenu *menu_F = ui->menuBar->addMenu(tr("文件(&F)"));
    QAction *open = new QAction(tr("打开"), this);
    open->setShortcut(tr("Ctrl+O"));
    QAction *new_file = new QAction(tr("新建"), this);
    new_file->setShortcut(tr("Ctrl+N"));
    connect(new_file, SIGNAL(triggered()), this, SLOT(newFile())); // 绑定槽
    QAction *save = new QAction(tr("保存"), this);
    save->setShortcut(tr("Ctrl+S"));
    connect(save, SIGNAL(triggered()), this, SLOT(saveFile())); // 绑定槽
    QAction *save_as = new QAction(tr("另存为"), this);
    QAction *exit = new QAction(tr("退出"), this);
    exit->setShortcut(tr("Ctrl+W"));
    menu_F->addAction(open);
    menu_F->addAction(new_file);
    menu_F->addAction(save);
    menu_F->addAction(save_as);
    menu_F->addAction(exit);

    QMenu *menu_E = ui->menuBar->addMenu(tr("编辑(&E)"));
    QAction *copy = new QAction(tr("复制"), this);
    copy->setShortcut(tr("Ctrl+C"));
    connect(copy, SIGNAL(triggered()), this, SLOT(copyText()));
    QAction *paste = new QAction(tr("粘贴"), this);
    paste->setShortcut(tr("Ctrl+V"));
    connect(paste, SIGNAL(triggered()), this, SLOT(pasteText()));
    QAction *find = new QAction(tr("查找"), this);
    find->setShortcut(tr("Ctrl+F"));
    menu_E->addAction(copy);
    menu_E->addAction(paste);
    menu_E->addAction(find);

    // 文本框的布局
    QGridLayout *layout = new QGridLayout;
    QTextEdit *edit_area = new QTextEdit(this);
    layout->addWidget(edit_area, 1, 1, 1, 1);
    ui->centralWidget->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFile() {
    is_unsaved = true;
    current_file_path = tr("未命名");
    setWindowTitle(current_file_path);
    QTextEdit *edit_area = this->findChild<QTextEdit *>();
    edit_area->clear();
    edit_area->setVisible(true);
}

bool MainWindow::saveFile() {
    // 多态 此函数为真正的事件槽
    if (is_unsaved) {
        QString file_name = QFileDialog::getSaveFileName(this, tr("另存为"), current_file_path);
        if (file_name.isEmpty())
            return false;
        return saveFile(file_name);
    } else {
        return saveFile(current_file_path);
    }
}

bool MainWindow::saveFile(const QString &file_name) {
    QFile file(file_name);
    QTextEdit *edit_area = this->findChild<QTextEdit *>();
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("文档编辑器"), tr("无法写入文件 %1: /n %2").arg(file_name).arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << edit_area->toPlainText();
    QApplication::restoreOverrideCursor();
    is_unsaved = false;
    current_file_path = QFileInfo(file_name).canonicalFilePath();
    setWindowTitle(current_file_path);
    return true;
}

void MainWindow::copyText() {
    this->findChild<QTextEdit *>()->copy();
}

void MainWindow::pasteText() {
    this->findChild<QTextEdit *>()->paste();
}
