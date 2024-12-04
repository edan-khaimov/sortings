#include "TestWindow.h"
#include <QCoreApplication>
#include <QElapsedTimer>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QThread>
#include <QVBoxLayout>
#include "../tests/heapSortTest.h"
#include "../tests/quickSortTest.h"

TestWindow::TestWindow(QWidget* parent) : QMainWindow(parent) {
    setWindowTitle("Тестирование");
    resize(800, 600);

    auto* centralWidget = new QWidget(this);
    auto* layout = new QVBoxLayout(centralWidget);

    auto* testLayout = new QVBoxLayout();
    runTestsButton = new QPushButton("Запустить тесты", this);
    testLayout->addWidget(runTestsButton);
    testStatusLabel = new QLabel("Тесты еще не запущены.", this);
    testStatusLabel->setWordWrap(true);
    testLayout->addWidget(testStatusLabel);
    layout->addLayout(testLayout);
    connect(runTestsButton, &QPushButton::clicked, this, &TestWindow::runTests);

    auto* separator = new QFrame(this);
    separator->setFrameShape(QFrame::HLine);
    separator->setFrameShadow(QFrame::Sunken);
    layout->addWidget(separator);

    auto* sortParameterLayout = new QVBoxLayout();
    sortParameterLayout->addWidget(new QLabel("Выберите параметр сортировки:", this));
    sortParameterComboBox = new QComboBox(this);
    sortParameterComboBox->addItems({"Возраст", "Вес", "Рост", "Зарплата"});
    sortParameterLayout->addWidget(sortParameterComboBox);
    layout->addLayout(sortParameterLayout);

    auto* sortOrderLayout = new QVBoxLayout();
    sortOrderLayout->addWidget(new QLabel("Выберите порядок сортировки:", this));
    sortOrderComboBox = new QComboBox(this);
    sortOrderComboBox->addItems({"По возрастанию", "По убыванию"});
    sortOrderLayout->addWidget(sortOrderComboBox);
    layout->addLayout(sortOrderLayout);

    auto* fileLayout = new QHBoxLayout();
    fileLayout->addWidget(new QLabel("Выберите CSV файл:", this));
    filePathLineEdit = new QLineEdit(this);
    filePathLineEdit->setReadOnly(true);
    fileLayout->addWidget(filePathLineEdit);
    auto* fileButton = new QPushButton("Выбрать файл", this);
    fileLayout->addWidget(fileButton);
    layout->addLayout(fileLayout);
    connect(fileButton, &QPushButton::clicked, this, &TestWindow::selectFile);

    checkSortingButton = new QPushButton("Проверить, отсортирован ли файл", this);
    layout->addWidget(checkSortingButton);
    connect(checkSortingButton, &QPushButton::clicked, this, &TestWindow::checkIfFileIsSorted);

    resultLabel = new QLabel("Результат будет отображён здесь.", this);
    resultLabel->setWordWrap(true);
    layout->addWidget(resultLabel);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

void TestWindow::runTests() {
    testStatusLabel->setText("Запуск тестов...");
    QCoreApplication::processEvents();

    if (heapSortAscAgeTest() == 0) {
        testStatusLabel->setText("Тест 1 успешно пройден.");
    } else {
        testStatusLabel->setText("Тест 1 провален.");
        return;
    }
    QCoreApplication::processEvents();

    if (quickSortAscAgeTest() == 0) {
        testStatusLabel->setText("Тест 2 успешно пройден.");
    } else {
        testStatusLabel->setText("Тест 2 провален.");
        return;
    }
    QCoreApplication::processEvents();

    if (heapSortDescAgeTest() == 0) {
        testStatusLabel->setText("Тест 3 успешно пройден.");
    } else {
        testStatusLabel->setText("Тест 3 провален.");
        return;
    }
    QCoreApplication::processEvents();

    if (quickSortDescAgeTest() == 0) {
        testStatusLabel->setText("Тест 4 успешно пройден.");
    } else {
        testStatusLabel->setText("Тест 4 провален.");
        return;
    }
    QCoreApplication::processEvents();

    if (heapSortAscWeightTest() == 0) {
        testStatusLabel->setText("Тест 5 успешно пройден.");
    } else {
        testStatusLabel->setText("Тест 5 провален.");
        return;
    }
    QCoreApplication::processEvents();

    if (quickSortAscWeightTest() == 0) {
        testStatusLabel->setText("Тест 6 успешно пройден.");
    } else {
        testStatusLabel->setText("Тест 6 провален.");
        return;
    }
    QCoreApplication::processEvents();

    if (heapSortDescWeightTest() == 0) {
        testStatusLabel->setText("Тест 7 успешно пройден.");
    } else {
        testStatusLabel->setText("Тест 7 провален.");
        return;
    }
    QCoreApplication::processEvents();

    if (quickSortDescWeightTest() == 0) {
        testStatusLabel->setText("Тест 8 успешно пройден.");
    } else {
        testStatusLabel->setText("Тест 8 провален.");
        return;
    }
    QCoreApplication::processEvents();

    if (heapSortAscHeightTest() == 0) {
        testStatusLabel->setText("Тест 9 успешно пройден.");
    } else {
        testStatusLabel->setText("Тест 9 провален.");
        return;
    }
    QCoreApplication::processEvents();

    if (quickSortAscHeightTest() == 0) {
        testStatusLabel->setText("Тест 10 успешно пройден.");
    } else {
        testStatusLabel->setText("Тест 10 провален.");
        return;
    }
    QCoreApplication::processEvents();

    if (heapSortDescHeightTest() == 0) {
        testStatusLabel->setText("Тест 11 успешно пройден.");
    } else {
        testStatusLabel->setText("Тест 11 провален.");
        return;
    }
    QCoreApplication::processEvents();

    if (quickSortDescHeightTest() == 0) {
        testStatusLabel->setText("Тест 12 успешно пройден.");
    } else {
        testStatusLabel->setText("Тест 12 провален.");
        return;
    }
    QCoreApplication::processEvents();

    if (heapSortAscSalaryTest() == 0) {
        testStatusLabel->setText("Тест 13 успешно пройден.");
    } else {
        testStatusLabel->setText("Тест 13 провален.");
        return;
    }
    QCoreApplication::processEvents();

    if (quickSortAscSalaryTest() == 0) {
        testStatusLabel->setText("Тест 14 успешно пройден.");
    } else {
        testStatusLabel->setText("Тест 14 провален.");
        return;
    }
    QCoreApplication::processEvents();

    if (heapSortDescSalaryTest() == 0) {
        testStatusLabel->setText("Тест 15 успешно пройден.");
    } else {
        testStatusLabel->setText("Тест 15 провален.");
        return;
    }
    QCoreApplication::processEvents();

    if (quickSortDescSalaryTest() == 0) {
        testStatusLabel->setText("Тест 16 успешно пройден.");
    } else {
        testStatusLabel->setText("Тест 16 провален.");
        return;
    }

    testStatusLabel->setText("Все тесты успешно завершены!");
}

void TestWindow::selectFile() {
    QString filePath = QFileDialog::getOpenFileName(this, "Выберите CSV файл", "", "CSV файлы (*.csv)");
    if (!filePath.isEmpty()) {
        filePathLineEdit->setText(filePath);
    }
}

void TestWindow::checkIfFileIsSorted() {
    QString sortParameter = sortParameterComboBox->currentText();
    QString sortOrder = sortOrderComboBox->currentText();
    QString filePath = filePathLineEdit->text();

    if (filePath.isEmpty()) {
        resultLabel->setText("Ошибка: Не выбран файл для проверки.");
        return;
    }

    // Вызов вашей функции проверки отсортированности
    bool isSorted = true; // Ваша функция: checkIfSorted(filePath, sortParameter, sortOrder);

    if (isSorted) {
        resultLabel->setText("Файл отсортирован корректно.");
    } else {
        resultLabel->setText("Файл не отсортирован.");
    }
}
