#include <stdlib.h>
#include <sort.h>
extern "C" {
    void recursiveBubbleSort(long long *arr, size_t n) {
        // Base case: if the size is 1 or 0, return
        if(1 < n){
            // Perform one pass of bubble sort and reduce the size for the next recursive call
            for (int i = 0; i < n - 1; i++) {
                if (arr[i] > arr[i + 1]) {
                    // Swap the elements if they are in the wrong order
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                }
            }

            // Recursive call for the remaining unsorted part
            recursiveBubbleSort(arr, n - 1);
        }
    }
    void recursiveBubbleSort(long *arr, size_t n) {
        // Base case: if the size is 1 or 0, return
        if(1 < n){
            // Perform one pass of bubble sort and reduce the size for the next recursive call
            for (int i = 0; i < n - 1; i++) {
                if (arr[i] > arr[i + 1]) {
                    // Swap the elements if they are in the wrong order
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                }
            }

            // Recursive call for the remaining unsorted part
            recursiveBubbleSort(arr, n - 1);
        }
    }
        void recursiveBubbleSort(int *arr, size_t n) {
        // Base case: if the size is 1 or 0, return
        if(1 < n){
            // Perform one pass of bubble sort and reduce the size for the next recursive call
            for (int i = 0; i < n - 1; i++) {
                if (arr[i] > arr[i + 1]) {
                    // Swap the elements if they are in the wrong order
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                }
            }

            // Recursive call for the remaining unsorted part
            recursiveBubbleSort(arr, n - 1);
        }
    }
}
template<class T>
void recursiveBubbleSort(T *arr, size_t n) {
    // Base case: if the size is 1 or 0, return
    if(1 < n){
        // Perform one pass of bubble sort and reduce the size for the next recursive call
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                // Swap the elements if they are in the wrong order
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }

        // Recursive call for the remaining unsorted part
        recursiveBubbleSort(arr, n - 1);
    }
}