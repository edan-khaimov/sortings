#include "TestWindow.h"

TestWindow::TestWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Тестирование");
    resize(800, 600);

    auto *label = new QLabel("Окно тестирования", this);
    label->setAlignment(Qt::AlignCenter);
    setCentralWidget(label);
}
