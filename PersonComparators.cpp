#include "PersonComparators.h"
#include "DefaultComparators.h"

int ascendingComparatorByAge(const Person& a, const Person& b) {
    return ascendingComparator(a.getAge(), b.getAge());
}

int descendingComparatorByAge(const Person& a, const Person& b) {
    return descendingComparator(a.getAge(), b.getAge());
}

int ascendingComparatorBySalary(const Person& a, const Person& b) {
    return ascendingComparator(a.getSalary(), b.getSalary());
}

int descendingComparatorBySalary(const Person& a, const Person& b) {
    return descendingComparator(a.getSalary(), b.getSalary());
}

int ascendingComparatorByHeight(const Person& a, const Person& b) {
    return ascendingComparator(a.getHeight(), b.getHeight());
}

int descendingComparatorByHeight(const Person& a, const Person& b) {
    return descendingComparator(a.getHeight(), b.getHeight());
}

int ascendingComparatorByWeight(const Person& a, const Person& b) {
    return ascendingComparator(a.getWeight(), b.getWeight());
}

int descendingComparatorByWeight(const Person& a, const Person& b) {
    return descendingComparator(a.getWeight(), b.getWeight());
}