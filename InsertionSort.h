#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "SortBase.h"

class InsertionSort: public SortBase {

    public:

        //Purpose: create an array of the specified size
        //Pre: size cannot be negative
        //Post: array of size "size" with random int values
        InsertionSort(int size): SortBase(size) {}


    private:
        //Purpose: sorts the array and increases passed value by elapsed time
        //Pre: none
        //Post: array sorted
        void sort(long long& caseSum) override;



};

#endif
