#include "quickSortTest.h"

#include "../../sequences/arraySequence.h"
#include "../Person.h"
#include "../PersonComparators.h"
#include "../quickSort.h"
#include "filesHelper.h"

int quickSortDescAgeTest(const std::string& path) {
    ArraySequence<Person> persons;
    readAndSort(path, QuickSorter<Person>(), persons, descendingComparatorByAge);

    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getAge() < persons[i + 1].getAge()) {
            return 1;
        }
    }
    return 0;
}

int quickSortAscAgeTest(const std::string& path) {
    ArraySequence<Person> persons;
    readAndSort(path, QuickSorter<Person>(), persons, ascendingComparatorByAge);

    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getAge() > persons[i + 1].getAge()) {
            return 1;
        }
    }
    return 0;
}

int quickSortDescSalaryTest(const std::string& path) {
    ArraySequence<Person> persons;
    readAndSort(path, QuickSorter<Person>(), persons, descendingComparatorBySalary);

    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getSalary() < persons[i + 1].getSalary()) {
            return 1;
        }
    }
    return 0;
}

int quickSortAscSalaryTest(const std::string& path) {
    ArraySequence<Person> persons;
    readAndSort(path, QuickSorter<Person>(), persons, ascendingComparatorBySalary);

    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getSalary() > persons[i + 1].getSalary()) {
            return 1;
        }
    }
    return 0;
}

int quickSortDescWeightTest(const std::string& path) {
    ArraySequence<Person> persons;
    readAndSort(path, QuickSorter<Person>(), persons, descendingComparatorByWeight);

    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getWeight() < persons[i + 1].getWeight()) {
            return 1;
        }
    }
    return 0;
}

int quickSortAscWeightTest(const std::string& path) {
    ArraySequence<Person> persons;
    readAndSort(path, QuickSorter<Person>(), persons, ascendingComparatorByWeight);

    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getWeight() > persons[i + 1].getWeight()) {
            return 1;
        }
    }
    return 0;
}

int quickSortDescHeightTest(const std::string& path) {
    ArraySequence<Person> persons;
    readAndSort(path, QuickSorter<Person>(), persons, descendingComparatorByHeight);

    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getHeight() < persons[i + 1].getHeight()) {
            return 1;
        }
    }
    return 0;
}

int quickSortAscHeightTest(const std::string& path) {
    ArraySequence<Person> persons;
    readAndSort(path, QuickSorter<Person>(), persons, ascendingComparatorByHeight);

    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getHeight() > persons[i + 1].getHeight()) {
            return 1;
        }
    }
    return 0;
}

