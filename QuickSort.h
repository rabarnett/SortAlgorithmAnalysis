#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "SortBase.h"

class QuickSort: public SortBase {

    public:
        QuickSort(int size): SortBase(size) {}

    private:
        void sort(long long& caseSum) override;
        void quickSort(int startIndex, int endIndex);
        int partition(int startIndex, int endIndex);


};


#endif
