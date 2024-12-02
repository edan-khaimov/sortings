#include "SortWindow.h"
#include <QElapsedTimer>
#include <QPushButton>
#include <QVBoxLayout>

SortWindow::SortWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Сортировка");
    resize(800, 600);

    auto *centralWidget = new QWidget(this);
    auto *layout = new QVBoxLayout(centralWidget);

    layout->addSpacing(10);

    auto *sortTypeLayout = new QVBoxLayout();
    sortTypeLayout->addWidget(new QLabel("Выберите тип сортировки:", this));

    sortTypeComboBox = new QComboBox(this);
    sortTypeComboBox->addItems({"Пирамидальная", "Быстрая"});
    sortTypeLayout->addWidget(sortTypeComboBox);
    layout->addLayout(sortTypeLayout);

    auto *sortParameterLayout = new QVBoxLayout();
    sortParameterLayout->addWidget(new QLabel("Выберите параметр сортировки:", this));
    sortParameterComboBox = new QComboBox(this);
    sortParameterComboBox->addItems({"Возраст", "Вес", "Рост", "Зарплата"});
    sortParameterLayout->addWidget(sortParameterComboBox);
    layout->addLayout(sortParameterLayout);

    layout->addSpacing(20);

    auto *fileLayout = new QHBoxLayout();
    fileLayout->addWidget(new QLabel("Выберите CSV файл:", this));
    filePathLineEdit = new QLineEdit(this);
    filePathLineEdit->setReadOnly(true);
    fileLayout->addWidget(filePathLineEdit);
    auto *fileButton = new QPushButton("Выбрать файл", this);
    fileButton->setObjectName("selectFileButton");
    fileLayout->addWidget(fileButton);
    layout->addLayout(fileLayout);
    connect(fileButton, &QPushButton::clicked, this, &SortWindow::selectFile);

    auto *startButtonLayout = new QVBoxLayout();
    auto *startButton = new QPushButton("Начать сортировку", this);
    startButtonLayout->addWidget(startButton);
    layout->addLayout(startButtonLayout);
    connect(startButton, &QPushButton::clicked, this, &SortWindow::startSorting);

    resultLabel = new QLabel("Результат будет отображён здесь.", this);
    resultLabel->setWordWrap(true);
    layout->addWidget(resultLabel);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

void SortWindow::selectFile() {
    if (const QString filePath = QFileDialog::getOpenFileName(this, "Выберите CSV файл", "", "CSV файлы (*.csv)");
        !filePath.isEmpty()) {
        filePathLineEdit->setText(filePath);
    }
}

void SortWindow::startSorting() const {
    QString sortType = sortTypeComboBox->currentText();
    QString sortParameter = sortParameterComboBox->currentText();
    QString filePath = filePathLineEdit->text();

    if (filePath.isEmpty()) {
        resultLabel->setText("Ошибка: Не выбран файл для сортировки.");
        return;
    }

    QElapsedTimer timer;
    timer.start();

    // sort(...)

    qint64 elapsedTime = timer.elapsed();

    QString outputFile = filePath + "_sorted.csv";

    resultLabel->setText(
        QString("Сортировка завершена!\nТип: %1\nПараметр: %2\n"
                "Входной файл: %3\nВыходной файл: %4\nВремя: %5 мс")
            .arg(sortType, sortParameter, filePath, outputFile)
            .arg(elapsedTime)
    );
}
