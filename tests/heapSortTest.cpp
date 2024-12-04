#include "heapSortTest.h"

#include "../../sequences/arraySequence.h"
#include "../Person.h"
#include "../PersonComparators.h"
#include "../heapSort.h"
#include "filesHelper.h"

int heapSortAscAgeTest(const std::string& path) {
    ArraySequence<Person> persons;
    readAndSort(path, HeapSorter<Person>(), persons, ascendingComparatorByAge);

    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getAge() > persons[i + 1].getAge()) {
            return 1;
        }
    }
    return 0;
}

int heapSortAscHeightTest(const std::string& path) {
    ArraySequence<Person> persons;
    readAndSort(path, HeapSorter<Person>(), persons, ascendingComparatorByHeight);

    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getHeight() > persons[i + 1].getHeight()) {
            return 1;
        }
    }
    return 0;
}

int heapSortAscWeightTest(const std::string& path) {
    ArraySequence<Person> persons;
    readAndSort(path, HeapSorter<Person>(), persons, ascendingComparatorByWeight);

    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getWeight() > persons[i + 1].getWeight()) {
            return 1;
        }
    }
    return 0;
}

int heapSortAscSalaryTest(const std::string& path) {
    ArraySequence<Person> persons;
    readAndSort(path, HeapSorter<Person>(), persons, ascendingComparatorBySalary);

    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getSalary() > persons[i + 1].getSalary()) {
            return 1;
        }
    }
    return 0;
}

int heapSortDescAgeTest(const std::string& path) {
    ArraySequence<Person> persons;
    readAndSort(path, HeapSorter<Person>(), persons, descendingComparatorByAge);

    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getAge() < persons[i + 1].getAge()) {
            return 1;
        }
    }
    return 0;
}

int heapSortDescHeightTest(const std::string& path) {
    ArraySequence<Person> persons;
    readAndSort(path, HeapSorter<Person>(), persons, descendingComparatorByHeight);

    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getHeight() < persons[i + 1].getHeight()) {
            return 1;
        }
    }
    return 0;
}

int heapSortDescWeightTest(const std::string& path) {
    ArraySequence<Person> persons;
    readAndSort(path, HeapSorter<Person>(), persons, descendingComparatorByWeight);

    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getWeight() < persons[i + 1].getWeight()) {
            return 1;
        }
    }
    return 0;
}

int heapSortDescSalaryTest(const std::string& path) {
    ArraySequence<Person> persons;
    readAndSort(path, HeapSorter<Person>(), persons, descendingComparatorBySalary);

    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getSalary() < persons[i + 1].getSalary()) {
            return 1;
        }
    }
    return 0;
}