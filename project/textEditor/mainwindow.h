#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void newFile();
    bool saveFile();
    bool saveFile(const QString &file_name);
    void copyText();
    void pasteText();

private:
    Ui::MainWindow *ui;
    bool is_unsaved;
    QString current_file_path;
};

#endif // MAINWINDOW_H
