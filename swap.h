#ifndef MOVE_H
#define MOVE_H

#include "../smart_ptrs/move.h"

template<typename T>
void swap(T& a, T& b) noexcept {
    T tmp = move(a);
    a = move(b);
    b = move(tmp);
}

#endif // MOVE_H
