#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "iSorter.h"
#include "swap.h"

template<typename T>
class QuickSorter final : public ISorter<T> {
    int partition(Sequence<T>& sequence, const int left, const int right, int (*cmp)(const T&, const T&)) const {
        T pivot = sequence[right];
        int i = left - 1;

        for (int j = left; j < right; j++) {
            if (cmp(sequence[j], pivot) < 0) {
                i++;
                swap(sequence[i], sequence[j]);
            }
        }

        swap(sequence[i + 1], sequence[right]);

        return i + 1;
    }

    void quickSort(Sequence<T>& sequence, const int left, const int right, int (*cmp)(const T&, const T&)) const {
        if (left < right) {
            const size_t pivot = partition(sequence, left, right, cmp);
            quickSort(sequence, left, pivot - 1, cmp);
            quickSort(sequence, pivot + 1, right, cmp);
        }
    }

public:
    Sequence<T>* Sort(Sequence<T>& sequence, int (*cmp)(const T&, const T&)) const override {
        quickSort(sequence, 0, sequence.GetLength() - 1, cmp);
        return &sequence;
    }
};

#endif // QUICKSORT_H
