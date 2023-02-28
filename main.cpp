#include "HeapSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "InsertionSort.h"
#include <iostream>

int main() {

    int n;
    const int replications = 10;

    for(int i=1; i<=15; i++) {

        n = 2000 * i;

        MergeSort mergeValues(n);
        QuickSort quickValues(n);
        HeapSort heapValues(n);
        InsertionSort insertionSort(n);


        printf("\n\n\n%d\n\n\n", n);

        printf("\nMERGE - %d VALUES\n", n);
        mergeValues.allSortCasesAvg(replications);

        printf("\nQUICK - %d VALUES\n", n);
        quickValues.allSortCasesAvg(replications);

        printf("\nHEAP - %d VALUES\n", n);
        heapValues.allSortCasesAvg(replications);

        printf("\nINSERTION - %d VALUES\n", n);
        insertionSort.allSortCasesAvg(replications);

    }

    return 0;
}
