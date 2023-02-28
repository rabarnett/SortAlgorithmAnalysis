#include "InsertionSort.h"
#include <chrono>


void InsertionSort::sort(long long& caseSum) {
    //Start clock
    auto begin = std::chrono::high_resolution_clock::now();

    //Insertion sort
    int key, i;
    for(int j=1; j<size; j++) {
        key = values[j];
        i = j-1;
        while(i>=0 && values[i] > key) {
            values[i+1] = values[i];
            i--;
        }
        values[i+1] = key;
    }

    //Stop clock
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    //Increase case sum by time taken to sort
    caseSum += elapsed.count();
}