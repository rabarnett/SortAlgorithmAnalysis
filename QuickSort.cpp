#include "QuickSort.h"
#include <chrono>


void QuickSort::sort(long long& caseSum) {
    auto begin = std::chrono::high_resolution_clock::now();

    quickSort(0,size-1);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    caseSum += elapsed.count();
}

void QuickSort::quickSort(int startIndex, int endIndex) {
    if(startIndex < endIndex) {
        int pivot = partition(startIndex, endIndex);
        quickSort(startIndex, pivot-1);
        quickSort(pivot+1, endIndex);
    }
}

int QuickSort::partition(int startIndex, int endIndex) {
    int pivot = values[endIndex];
    int i = startIndex - 1;

    for(int j=startIndex; j<endIndex; j++) {
        if(values[j] <= pivot) {
            i++;
            swap(i,j);
        }
    }

    swap(i+1, endIndex);

    return i+1;
}