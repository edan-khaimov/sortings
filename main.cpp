#include "PersonComparators.h"
#include "filesHelper.h"
#include "quickSort.h"
#include "heapSort.h"

int main() {
    const std::string inputFile = "D:/labs_sem3/sortings/files/data.csv";
    const std::string outputFile = "D:/labs_sem3/sortings/files/out.csv";
    personCSVSort(inputFile, outputFile, HeapSorter<Person>(), ascendingComparatorByAge);
    return 0;
}