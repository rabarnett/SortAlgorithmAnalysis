#ifndef MERGESORT_H
#define MERGESORT_H

#include "SortBase.h"

class MergeSort: public SortBase{

    public:
        MergeSort(int size): SortBase(size){}

    private:
        void sort(long long& caseSum) override;
        void mergeSort(int startIndex, int endIndex);
        void merge(int startIndex, int midIndex, int endIndex);

};


#endif
