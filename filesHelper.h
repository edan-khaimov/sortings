#ifndef FILESHELPER_H
#define FILESHELPER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../sequences/ArraySequence.h"
#include "Person.h"
#include "iSorter.h"

template<typename T>
void numericTxtSort(const std::string& inputFilePath, const std::string& outputFilePath, const ISorter<T>& sorter,
                    int (*cmp)(const T&, const T&)) {
    ArraySequence<T> a;
    std::ifstream inputFile(inputFilePath, std::ios_base::in);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Cannot open file for reading");
    }

    T value;
    while (inputFile >> value) {
        a.Append(value);
    }
    inputFile.close();

    sorter.Sort(a, cmp);

    std::ofstream outputFile(outputFilePath);
    if (!outputFile.is_open()) {
        throw std::runtime_error("Cannot open file for writing");
    }

    for (int i = 0; i < a.GetLength(); i++) {
        outputFile << a[i] << std::endl;
    }
    outputFile.close();
}

inline void personCSVSort(const std::string& inputFilePath, const std::string& outputFilePath,
                          const ISorter<Person>& sorter, int (*cmp)(const Person&, const Person&)) {
    ArraySequence<Person> a;
    Person person;
    std::ifstream inputFile(inputFilePath);
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
        person.setWeight(std::stod(tmp));
        std::getline(stream, tmp, ',');
        person.setHeight(std::stod(tmp));
        std::getline(stream, tmp, ',');
        person.setEducation(tmp);
        std::getline(stream, tmp, ',');
        person.setMarriageStatus(tmp);
        std::getline(stream, tmp, ',');
        person.setPassportSeries(std::stoi(tmp));
        std::getline(stream, tmp, ',');
        person.setPassportNumber(std::stoi(tmp));
        std::getline(stream, tmp, ',');
        person.setSalary(std::stoi(tmp));
        a.Append(person);
    }

    std::cout << 1;
    inputFile.close();
    sorter.Sort(a, cmp);
    std::cout << 2;

    std::ofstream outputFile(outputFilePath);
    if (!outputFile.is_open()) {
        throw std::runtime_error("Cannot open file for writing");
    }

    outputFile << "Фамилия,Имя,Отчество,Пол,Возраст,Вес,Рост,Образование,Семейное положение,Серия паспорта,Номер "
                  "паспорта,Зарплата"
               << '\n';
    for (size_t i = 0; i < a.GetLength(); i++) {
        outputFile << a[i].getSurname() << "," << a[i].getName() << "," << a[i].getPatronymic() << ","
                   << a[i].getGender() << "," << a[i].getAge() << "," << a[i].getWeight() << "," << a[i].getHeight()
                   << "," << a[i].getEducation() << "," << a[i].getMarriageStatus() << "," << a[i].getPassportSeries()
                   << "," << a[i].getPassportNumber() << "," << a[i].getSalary() << '\n';
    }
}


#endif // FILESHELPER_H
