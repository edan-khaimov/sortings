#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "iSorter.h"
#include <random>
#include <stack>

constexpr int insertionSortThreshold = 16;

template<typename T>
class QuickSorter final : public ISorter<T> {
    void insertionSort(Sequence<T>& sequence, const int left, const int right, int (*cmp)(const T&, const T&)) const {
        for (int i = left + 1; i <= right; i++) {
            T key = sequence[i];
            int j = i - 1;
            while (j >= left && cmp(sequence[j], key) > 0) {
                sequence[j + 1] = sequence[j];
                j--;
            }
            sequence[j + 1] = key;
        }
    }

    std::pair<int, int> partition(Sequence<T>& sequence, const int left, const int right, int (*cmp)(const T&, const T&)) const {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution dis(left, right);
        int pivotIndex = dis(gen);
        T pivot = sequence[pivotIndex];
        std::swap(sequence[pivotIndex], sequence[right]);

        int lt = left;
        int gt = right;
        int i = left;

        while (i <= gt) {
            if (cmp(sequence[i], pivot) < 0) {
                std::swap(sequence[i], sequence[lt]);
                ++lt;
                ++i;
            } else if (cmp(sequence[i], pivot) > 0) {
                std::swap(sequence[i], sequence[gt]);
                --gt;
            } else {
                ++i;
            }
        }
        return {lt, gt};
    }
public:
    Sequence<T>* Sort(Sequence<T>& sequence, int (*cmp)(const T&, const T&)) const override {
        std::stack<std::pair<int, int>> stack;
        stack.push({0, sequence.GetLength() - 1});
        while (!stack.empty()) {
            auto [left, right] = stack.top();
            stack.pop();
            if (right - left + 1 < insertionSortThreshold) {
                insertionSort(sequence, left, right, cmp);
                continue;
            }
            auto [lt, gt] = partition(sequence, left, right, cmp);
            if (lt - 1 > left) {
                stack.push({left, lt - 1});
            }
            if (gt + 1 < right) {
                stack.push({gt + 1, right});
            }
        }
        return &sequence;
    }
};

#endif // QUICKSORT_H
