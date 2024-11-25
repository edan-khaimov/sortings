#include "PersonComparators.h"
#include "filesHelper.h"
#include "quickSort.h"
#include "heapSort.h"
#include "insertionSort.h"

int main() {
    const std::string inputFile = "D:/labs_sem3/sorting/files/testOut.csv";
    const std::string outputFile = "D:/labs_sem3/sorting/files/out.csv";
    personCSVSort(inputFile, outputFile, HeapSorter<Person>(), ascendingComparatorByAge);
    return 0;
}