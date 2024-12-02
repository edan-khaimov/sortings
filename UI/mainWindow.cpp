#include "MainWindow.h"
#include "SortWindow.h"
#include "TestWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Главное меню");
    resize(800, 600);

    auto *centralWidget = new QWidget(this);
    auto *layout = new QVBoxLayout(centralWidget);

    auto *sortButton = new QPushButton("Сортировать", this);
    auto *testButton = new QPushButton("Тестировать", this);

    layout->addWidget(sortButton);
    layout->addWidget(testButton);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(sortButton, &QPushButton::clicked, this, &MainWindow::showSortWindow);
    connect(testButton, &QPushButton::clicked, this, &MainWindow::showTestWindow);
}

void MainWindow::showSortWindow() {
    auto *sortWindow = new SortWindow();
    sortWindow->show();
}

void MainWindow::showTestWindow() {
    auto *testWindow = new TestWindow();
    testWindow->show();
}
