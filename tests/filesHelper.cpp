#include "filesHelper.h"
#include <fstream>
#include <iostream>
#include <sstream>

#include "../../sequences/arraySequence.h"

void readAndSort(const std::string& path, const ISorter<Person>& sorter, ArraySequence<Person>& a,
                 int (*cmp)(const Person&, const Person&)) {
    std::string line;
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Person person;
    std::ifstream inputFile(path);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Cannot open file for reading");
    }

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

    sorter.Sort(a, cmp);
}
