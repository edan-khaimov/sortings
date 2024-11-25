#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "iSorter.h"

template<typename T>
class HeapSorter final : public ISorter<T> {
    void heapify(Sequence<T>& sequence, const int& n, const int& i, int (*cmp)(const T&, const T&)) const {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && cmp(sequence[l], sequence[largest]) > 0) {
            largest = l;
        }

        if (r < n && cmp(sequence[r], sequence[largest]) > 0) {
            largest = r;
        }

        if (largest != i) {
            std::swap(sequence[i], sequence[largest]);
            heapify(sequence, n, largest, cmp);
        }
    }

public:
    Sequence<T>* Sort(Sequence<T>& sequence, int (*cmp)(const T&, const T&)) const override {
        const int n = sequence.GetLength();
        for (int i = n / 2 - 1; i >= 0; --i) {
            heapify(sequence, n, i, cmp);
        }

        for (int i = n - 1; i > 0; --i) {
            std::swap(sequence[0], sequence[i]);
            heapify(sequence, i, 0, cmp);
        }
        return &sequence;
    }
};
#endif // HEAPSORT_H
