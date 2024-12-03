#include "SortWindow.h"
#include <QElapsedTimer>
#include <QPushButton>
#include <QVBoxLayout>
#include <fstream>
#include <iostream>
#include <qcoreapplication.h>

#include "../PersonComparators.h"
#include "../heapSort.h"
#include "../../sequences/arraySequence.h"
#include "../quickSort.h"

SortWindow::SortWindow(QWidget* parent) : QMainWindow(parent) {
    setWindowTitle("Сортировка");
    resize(800, 600);

    auto* centralWidget = new QWidget(this);
    auto* layout = new QVBoxLayout(centralWidget);

    layout->addSpacing(10);

    auto* sortTypeLayout = new QVBoxLayout();
    sortTypeLayout->addWidget(new QLabel("Выберите тип сортировки:", this));
    sortTypeComboBox = new QComboBox(this);
    sortTypeComboBox->addItems({"Пирамидальная", "Быстрая"});
    sortTypeLayout->addWidget(sortTypeComboBox);
    layout->addLayout(sortTypeLayout);

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

    layout->addSpacing(20);

    auto *separator = new QFrame(this);
    separator->setFrameShape(QFrame::HLine);
    separator->setFrameShadow(QFrame::Sunken);
    layout->addWidget(separator);

    auto* fileLayout = new QHBoxLayout();
    fileLayout->addWidget(new QLabel("Выберите CSV файл:", this));
    filePathLineEdit = new QLineEdit(this);
    filePathLineEdit->setReadOnly(true);
    fileLayout->addWidget(filePathLineEdit);
    auto* fileButton = new QPushButton("Выбрать файл", this);
    fileButton->setObjectName("selectFileButton");
    fileLayout->addWidget(fileButton);
    layout->addLayout(fileLayout);
    connect(fileButton, &QPushButton::clicked, this, &SortWindow::selectFile);

    auto* startButtonLayout = new QVBoxLayout();
    auto* startButton = new QPushButton("Начать сортировку", this);
    startButtonLayout->addWidget(startButton);
    layout->addLayout(startButtonLayout);
    connect(startButton, &QPushButton::clicked, this, &SortWindow::startSorting);

    // Прогресс-бар
    progressBar = new QProgressBar(this);
    progressBar->setRange(0, 3); // Чтение, сортировка, запись (3 этапа)
    progressBar->setValue(0);
    layout->addWidget(progressBar);

    // Статус выполнения
    statusLabel = new QLabel("Ожидание действий пользователя...", this);
    statusLabel->setWordWrap(true);
    layout->addWidget(statusLabel);

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
    QString sortOrder = sortOrderComboBox->currentText();
    QString inputFilePath = filePathLineEdit->text();

    if (inputFilePath.isEmpty()) {
        resultLabel->setText("Ошибка: Не выбран файл для сортировки.");
        return;
    }

    statusLabel->setText("Чтение файла...");
    progressBar->setValue(1);
    QCoreApplication::processEvents(); // Обновляем интерфейс
    QElapsedTimer timer;
    timer.start();

    ArraySequence<Person> a;
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Person person;
    std::ifstream inputFile(inputFilePath.toStdString());
    if (!inputFile.is_open()) {
        throw std::runtime_error("Cannot open file for reading");
    }

    std::string line;
    std::getline(inputFile, line);
    while (std::getline(inputFile, line)) {
        std::istringstream stream(line);
        std::string tmp;

        std::getline(stream, tmp, ',');
        person.setSurname(tmp);
        std::getline(stream, tmp, ',');
        person.setName(tmp);
        std::getline(stream, tmp, ',');
        person.setPatronymic(tmp);
        std::getline(stream, tmp, ',');
        person.setGender(tmp);
        std::getline(stream, tmp, ',');
        person.setAge(std::stoi(tmp));
        std::getline(stream, tmp, ',');
        person.setWeight(std::stoi(tmp));
        std::getline(stream, tmp, ',');
        person.setHeight(std::stoi(tmp));
        std::getline(stream, tmp, ',');
        person.setEducation(tmp);
        std::getline(stream, tmp, ',');
        person.setMaritalStatus(tmp);
        std::getline(stream, tmp, ',');
        person.setPassportSeries(std::stoi(tmp));
        std::getline(stream, tmp, ',');
        person.setPassportNumber(std::stoi(tmp));
        std::getline(stream, tmp, ',');
        person.setSalary(std::stoi(tmp));
        a.Append(person);
    }
    inputFile.close();
    qint64 readElapsedTime = timer.elapsed();

    statusLabel->setText("Сортировка...");
    progressBar->setValue(2);
    QCoreApplication::processEvents();

    timer.start();
    if (sortType == "Пирамидальная") {
        HeapSorter<Person> sort;
        if (sortParameter == "Возраст") {
            if (sortOrder == "По возрастанию") {
                sort.Sort(a, ascendingComparatorByAge);
            } else {
                sort.Sort(a, descendingComparatorByAge);
            }
        } else if (sortParameter == "Зарплата") {
            if (sortOrder == "По возрастанию") {
                sort.Sort(a, ascendingComparatorBySalary);
            } else {
                sort.Sort(a, descendingComparatorBySalary);
            }
        } else if (sortParameter == "Вес") {
            if (sortOrder == "По возрастанию") {
                sort.Sort(a, ascendingComparatorByWeight);
            } else {
                sort.Sort(a, descendingComparatorByWeight);
            }
        } else if (sortParameter == "Рост") {
            if (sortOrder == "По возрастанию") {
                sort.Sort(a, ascendingComparatorByHeight);
            } else {
                sort.Sort(a, descendingComparatorByHeight);
            }
        }
    } else {
        QuickSorter<Person> sort;
        if (sortParameter == "Возраст") {
            if (sortOrder == "По возрастанию") {
                sort.Sort(a, ascendingComparatorByAge);
            } else {
                sort.Sort(a, descendingComparatorByAge);
            }
        } else if (sortParameter == "Зарплата") {
            if (sortOrder == "По возрастанию") {
                sort.Sort(a, ascendingComparatorBySalary);
            } else {
                sort.Sort(a, descendingComparatorBySalary);
            }
        } else if (sortParameter == "Вес") {
            if (sortOrder == "По возрастанию") {
                sort.Sort(a, ascendingComparatorByWeight);
            } else {
                sort.Sort(a, descendingComparatorByWeight);
            }
        } else if (sortParameter == "Рост") {
            if (sortOrder == "По возрастанию") {
                sort.Sort(a, ascendingComparatorByHeight);
            } else {
                sort.Sort(a, descendingComparatorByHeight);
            }
        }
    }
    qint64 sortElapsedTime = timer.elapsed();

    statusLabel->setText("Запись в файл...");
    progressBar->setValue(3);
    QCoreApplication::processEvents();
    timer.start();
    QString outputFilePath = inputFilePath.chopped(4) + "_sorted.csv";
    std::ofstream outputFile(outputFilePath.toStdString());
    if (!outputFile.is_open()) {
        throw std::runtime_error("Cannot open file for writing");
    }
    outputFile << "Фамилия,Имя,Отчество,Пол,Возраст,Вес,Рост,Образование,Семейное положение,Серия паспорта,Номер "
                  "паспорта,Зарплата"
               << '\n';
    for (size_t i = 0; i < a.GetLength(); i++) {
        outputFile << a[i].getSurname() << "," << a[i].getName() << "," << a[i].getPatronymic() << ","
                   << a[i].getGender() << "," << a[i].getAge() << "," << a[i].getWeight() << "," << a[i].getHeight()
                   << "," << a[i].getEducation() << "," << a[i].getMaritalStatus() << "," << a[i].getPassportSeries()
                   << "," << a[i].getPassportNumber() << "," << a[i].getSalary() << '\n';
    }
    qint64 writeElapsedTime = timer.elapsed();

    resultLabel->setText(QString("Сортировка завершена!\n"
                                 "Входной файл: %1\nВыходной файл: %2\nВремя чтения: %3 мс\nВремя сортировки: %4 "
                                 "мс\nВремя записи: %5 мс")
                                 .arg(inputFilePath, outputFilePath)
                                 .arg(readElapsedTime)
                                 .arg(sortElapsedTime)
                                 .arg(writeElapsedTime));
}
