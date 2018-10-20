#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv); // 创建一个应用实体

    QWidget *window = new QWidget; // 创建窗口
    window->setWindowTitle("Enter Your Age");

    QSpinBox *spinBox = new QSpinBox;
    spinBox->setRange(0, 130);

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 130);

    QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
    spinBox->setValue(35);

    QHBoxLayout *layout = new QHBoxLayout; // 横向排列两个控件
    layout->addWidget(spinBox);
    layout->addWidget(slider);
    window->setLayout(layout); // 把布局绑定到window中去

    window->show();

    return app.exec();
}
