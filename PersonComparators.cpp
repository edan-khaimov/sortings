#include "PersonComparators.h"

int ascendingComparatorByAge(const Person& a, const Person& b) {
    if (a.getAge() < b.getAge()) {
        return 1;
    }
    if (a.getAge() > b.getAge()) {
        return -1;
    }
    return 0;
}

int descendingComparatorByAge(const Person& a, const Person& b) {
    if (a.getAge() < b.getAge()) {
        return -1;
    }
    if (a.getAge() > b.getAge()) {
        return 1;
    }
    return 0;
}

int ascendingComparatorBySalary(const Person& a, const Person& b) {
    if (a.getSalary() < b.getSalary()) {
        return 1;
    }
    if (a.getSalary() > b.getSalary()) {
        return -1;
    }
    return 0;
}

int descendingComparatorBySalary(const Person& a, const Person& b) {
    if (a.getSalary() < b.getSalary()) {
        return -1;
    }
    if (a.getSalary() > b.getSalary()) {
        return 1;
    }
    return 0;
}

int ascendingComparatorByHeight(const Person& a, const Person& b) {
    if (a.getHeight() < b.getHeight()) {
        return 1;
    }
    if (a.getHeight() > b.getHeight()) {
        return -1;
    }
    return 0;
}

int descendingComparatorByHeight(const Person& a, const Person& b) {
    if (a.getHeight() < b.getHeight()) {
        return -1;
    }
    if (a.getHeight() > b.getHeight()) {
        return 1;
    }
    return 0;
}

int ascendingComparatorByWeight(const Person& a, const Person& b) {
    if (a.getWeight() < b.getWeight()) {
        return 1;
    }
    if (a.getWeight() > b.getWeight()) {
        return -1;
    }
    return 0;
}

int descendingComparatorByWeight(const Person& a, const Person& b) {
    if (a.getWeight() < b.getWeight()) {
        return -1;
    }
    if (a.getWeight() > b.getWeight()) {
        return 1;
    }
    return 0;
}
