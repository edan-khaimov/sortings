#ifndef FILESHELPER_H
#define FILESHELPER_H

#include <string>
#include "../../sequences/arraySequence.h"
#include "../Person.h"
#include "../iSorter.h"

void readAndSort(const std::string& path, const ISorter<Person>& sorter, ArraySequence<Person>& a,
                 int (*cmp)(const Person&, const Person&));

#endif // FILESHELPER_H
