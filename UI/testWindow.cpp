#include "TestWindow.h"
#include <QCoreApplication>
#include <QVBoxLayout>
#include <functional>
#include "../tests/heapSortTest.h"
#include "../tests/quickSortTest.h"

TestWindow::TestWindow(QWidget* parent) : QMainWindow(parent) {
    setWindowTitle("Тестирование");
    resize(800, 600);

    auto* centralWidget = new QWidget(this);
    auto* layout = new QVBoxLayout(centralWidget);

    runTestsButton = new QPushButton("Запустить тесты", this);
    layout->addWidget(runTestsButton);

    testLog = new QTextEdit(this);
    testLog->setReadOnly(true);
    testLog->setText("Тесты еще не запущены.\n");
    layout->addWidget(testLog);

    progressBar = new QProgressBar(this);
    progressBar->setRange(0, 16);
    progressBar->setValue(0);
    progressBar->setTextVisible(true);
    layout->addWidget(progressBar);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(runTestsButton, &QPushButton::clicked, this, &TestWindow::runTests);
}

void TestWindow::runTests() {
    testLog->clear();
    progressBar->setValue(0);

    struct Test {
        QString name;
        std::function<int()> func;
    };

    const Test tests[] = {
            {"Тест 1 (Heap Sort Asc Age)", []() { return heapSortAscAgeTest(); }},
            {"Тест 2 (Quick Sort Asc Age)", []() { return quickSortAscAgeTest(); }},
            {"Тест 3 (Heap Sort Desc Age)", []() { return heapSortDescAgeTest(); }},
            {"Тест 4 (Quick Sort Desc Age)", []() { return quickSortDescAgeTest(); }},
            {"Тест 5 (Heap Sort Asc Weight)", []() { return heapSortAscWeightTest(); }},
            {"Тест 6 (Quick Sort Asc Weight)", []() { return quickSortAscWeightTest(); }},
            {"Тест 7 (Heap Sort Desc Weight)", []() { return heapSortDescWeightTest(); }},
            {"Тест 8 (Quick Sort Desc Weight)", []() { return quickSortDescWeightTest(); }},
            {"Тест 9 (Heap Sort Asc Height)", []() { return heapSortAscHeightTest(); }},
            {"Тест 10 (Quick Sort Asc Height)", []() { return quickSortAscHeightTest(); }},
            {"Тест 11 (Heap Sort Desc Height)", []() { return heapSortDescHeightTest(); }},
            {"Тест 12 (Quick Sort Desc Height)", []() { return quickSortDescHeightTest(); }},
            {"Тест 13 (Heap Sort Asc Salary)", []() { return heapSortAscSalaryTest(); }},
            {"Тест 14 (Quick Sort Asc Salary)", []() { return quickSortAscSalaryTest(); }},
            {"Тест 15 (Heap Sort Desc Salary)", []() { return heapSortDescSalaryTest(); }},
            {"Тест 16 (Quick Sort Desc Salary)", []() { return quickSortDescSalaryTest(); }},
    };

    constexpr int totalTests = std::size(tests);

    for (int i = 0; i < totalTests; ++i) {
        const bool success = (tests[i].func() == 0);

        QString result = success ? "УСПЕШНО" : "НЕУСПЕШНО";
        testLog->append(QString("%1: %2").arg(tests[i].name).arg(result));

        if (!success) {
            testLog->append("Тестирование остановлено из-за ошибки.");
            progressBar->setValue(i + 1);
            return;
        }

        progressBar->setValue(i + 1);
        QCoreApplication::processEvents();
    }

    testLog->append("\nВсе тесты успешно завершены!");
    progressBar->setValue(totalTests);
}
