#include "TestWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QElapsedTimer>
#include <QCoreApplication>
#include <QThread>

TestWindow::TestWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Тестирование");
    resize(800, 600);

    auto *centralWidget = new QWidget(this);
    auto *layout = new QVBoxLayout(centralWidget);

    // Тестирование
    auto *testLayout = new QVBoxLayout();
    runTestsButton = new QPushButton("Запустить тесты", this);
    testLayout->addWidget(runTestsButton);
    testStatusLabel = new QLabel("Тесты еще не запущены.", this);
    testStatusLabel->setWordWrap(true);
    testLayout->addWidget(testStatusLabel);
    layout->addLayout(testLayout);
    connect(runTestsButton, &QPushButton::clicked, this, &TestWindow::runTests);

    // Разделительная линия
    auto *separator = new QFrame(this);
    separator->setFrameShape(QFrame::HLine);
    separator->setFrameShadow(QFrame::Sunken);
    layout->addWidget(separator);

    // Проверка сортировки
    auto *sortParameterLayout = new QVBoxLayout();
    sortParameterLayout->addWidget(new QLabel("Выберите параметр сортировки:", this));
    sortParameterComboBox = new QComboBox(this);
    sortParameterComboBox->addItems({"Возраст", "Вес", "Рост", "Зарплата"});
    sortParameterLayout->addWidget(sortParameterComboBox);
    layout->addLayout(sortParameterLayout);

    auto *sortOrderLayout = new QVBoxLayout();
    sortOrderLayout->addWidget(new QLabel("Выберите порядок сортировки:", this));
    sortOrderComboBox = new QComboBox(this);
    sortOrderComboBox->addItems({"По возрастанию", "По убыванию"});
    sortOrderLayout->addWidget(sortOrderComboBox);
    layout->addLayout(sortOrderLayout);

    // Выбор файла
    auto *fileLayout = new QHBoxLayout();
    fileLayout->addWidget(new QLabel("Выберите CSV файл:", this));
    filePathLineEdit = new QLineEdit(this);
    filePathLineEdit->setReadOnly(true);
    fileLayout->addWidget(filePathLineEdit);
    auto *fileButton = new QPushButton("Выбрать файл", this);
    fileLayout->addWidget(fileButton);
    layout->addLayout(fileLayout);
    connect(fileButton, &QPushButton::clicked, this, &TestWindow::selectFile);

    // Кнопка проверки сортировки
    checkSortingButton = new QPushButton("Проверить, отсортирован ли файл", this);
    layout->addWidget(checkSortingButton);
    connect(checkSortingButton, &QPushButton::clicked, this, &TestWindow::checkIfFileIsSorted);

    // Результат проверки
    resultLabel = new QLabel("Результат будет отображён здесь.", this);
    resultLabel->setWordWrap(true);
    layout->addWidget(resultLabel);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

void TestWindow::runTests() {
    testStatusLabel->setText("Запуск тестов...");
    QCoreApplication::processEvents();

    // Пример выполнения тестов
    bool test1 = true;  // Здесь должен быть ваш тест
    QThread::sleep(1); // Симуляция работы
    if (test1) {
        testStatusLabel->setText("Тест 1 успешно пройден.");
    } else {
        testStatusLabel->setText("Тест 1 провален.");
        return;
    }
    QCoreApplication::processEvents();

    QThread::sleep(1); // Симуляция второго теста
    bool test2 = true;  // Еще один тест
    if (test2) {
        testStatusLabel->setText("Тест 2 успешно пройден.");
    } else {
        testStatusLabel->setText("Тест 2 провален.");
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
