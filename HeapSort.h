#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "SortBase.h"

class HeapSort: public SortBase{

    public:
        HeapSort(int size): SortBase(size) {}

    private:
        void sort(long long& caseSum) override;
        void buildMaxHeap();
        void maxHeapify(int index);

        int rightNode(int index);
        int leftNode(int index);

        int heapSize;

};


#endif
