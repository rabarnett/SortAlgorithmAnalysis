#ifndef SORTBASE_H
#define SORTBASE_H


class SortBase {

    public:
        ~SortBase();

        void allSortCasesAvg(float replications);

    protected:
        SortBase(int size);

        virtual void sort(long long& caseSum);

        void reverse();

        void swap(int index1, int index2);

        int* values;
        int size;
};


#endif
