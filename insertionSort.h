#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "iSorter.h"

template<typename T>
class InsertionSorter final : public ISorter<T> {
public:
    Sequence<T>* Sort(Sequence<T>& sequence, int (*cmp)(const T&, const T&)) const override {
        for (int i = 1; i < sequence.GetLength(); i++) {
            T key = sequence[i];
            int j = i - 1;
            while (j >= 0 && cmp(key, sequence[j]) < 0) {
                sequence[j + 1] = sequence[j];
                j--;
            }
            sequence[j + 1] = key;
        }
        return &sequence;
    }
};
#endif // INSERTIONSORT_H
