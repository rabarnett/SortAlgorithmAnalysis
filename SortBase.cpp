#include "SortBase.h"
#include <iostream>
#include <cstdlib>
#include <chrono>


SortBase::SortBase(int size) {
    srand(time(nullptr));

    values = new int[size];
    this->size = size;

    for(int i=0; i<size; i++) {
        values[i] = rand();
    }
}

SortBase::~SortBase() {
    delete [] values;
    values = nullptr;
}

void SortBase::sort(long long &caseSum) {
    throw std::runtime_error("Failed to override sort");
}

void SortBase::allSortCasesAvg(float replications) {
    long long randomCaseSum = 0;
    long long sortedCaseSum = 0;
    long long reverseCaseSum = 0;

    for(int i=0; i<replications; i++) {
        //Random Case
        sort(randomCaseSum);

        //Sorted Case (already sorted from previous case)
        sort(sortedCaseSum);

        //Reverse Case
        reverse();
        sort(reverseCaseSum);
    }

    printf("Random Case: %.3f nanoseconds\n", randomCaseSum/replications);
    printf("Sorted Case: %.3f nanoseconds\n", sortedCaseSum/replications);
    printf("Reverse Case: %.3f nanoseconds\n", reverseCaseSum/replications);

}

void SortBase::reverse() {
    // Shell sort
    for (int gap = size/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i += 1)
        {
            int temp = values[i];
            int j;

            for (j = i; j >= gap && values[j - gap] < temp; j -= gap)
                values[j] = values[j - gap];

            values[j] = temp;
        }
    }
}

void SortBase::swap(int index1, int index2) {
    int temp = values[index1];
    values[index1] = values[index2];
    values[index2] = temp;
}