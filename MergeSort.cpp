#include "MergeSort.h"
#include <climits>
#include <chrono>


void MergeSort::sort(long long& caseSum) {
    auto begin = std::chrono::high_resolution_clock::now();

    mergeSort(0,size-1);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    caseSum += elapsed.count();
}

void MergeSort::mergeSort(int startIndex, int endIndex) {
    if(startIndex < endIndex) {
        int midIndex = (startIndex + endIndex + 2) / 2;
        mergeSort(startIndex, midIndex - 1);
        mergeSort(midIndex, endIndex);
        merge(startIndex, midIndex - 1, endIndex);
    }
}

void MergeSort::merge(int startIndex, int midIndex, int endIndex) {

    int leftSize = midIndex - startIndex + 1;
    int rightSize = endIndex - midIndex;

    int* left = new int[leftSize+1];
    int* right = new int[rightSize+1];

    for(int i=0; i<leftSize; i++) {
        left[i] = values[startIndex + i];
    }

    for(int i=0; i<rightSize; i++) {
        right[i] = values[midIndex + 1 + i];
    }

    left[leftSize] = INT_MAX;
    right[rightSize] = INT_MAX;

    int i = 0, j = 0;

    for(int k=startIndex; k<endIndex+1; k++) {
        if(left[i] <= right[j]) {
            values[k] = left[i];
            i++;
        } else {
            values[k] = right[j];
            j++;
        }
    }

    delete[] left;
    left = nullptr;

    delete[] right;
    right = nullptr;
}