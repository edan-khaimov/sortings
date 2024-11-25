#ifndef PERSONCOMPARATORS_H
#define PERSONCOMPARATORS_H

#include "Person.h"

int ascendingComparatorByAge(const Person& a, const Person& b);
int descendingComparatorByAge(const Person& a, const Person& b);

int ascendingComparatorBySalary(const Person& a, const Person& b);
int descendingComparatorBySalary(const Person& a, const Person& b);

int ascendingComparatorByWeight(const Person& a, const Person& b);
int descendingComparatorByWeight(const Person& a, const Person& b);

int ascendingComparatorByHeight(const Person& a, const Person& b);
int descendingComparatorByHeight(const Person& a, const Person& b);


#endif // PERSONCOMPARATORS_H
