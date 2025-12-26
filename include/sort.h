#pragma once

#include <stdlib.h>

extern "C" {
    void recursiveBubbleSort(long long *arr, size_t n);
    void recursiveBubbleSort(long *arr, size_t n);
    void recursiveBubbleSort(int *arr, size_t n);
}
template<class T>
void recursiveBubbleSort(T *arr, size_t n);