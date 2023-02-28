#include "HeapSort.h"
#include <chrono>


void HeapSort::sort(long long& caseSum) {
    auto begin = std::chrono::high_resolution_clock::now();

    buildMaxHeap();

    for(int i=size-1; i>0; i--) {
        swap(0,i);
        heapSize--;

        maxHeapify(0);
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    caseSum += elapsed.count();
}

void HeapSort::buildMaxHeap() {
    heapSize = size -1;

    for(int index= size/2; index >= 0; index--) {
        maxHeapify(index);
    }
}

void HeapSort::maxHeapify(int index) {

    int left = leftNode(index);
    int right = rightNode(index);
    int largest;

    if(left <= heapSize && values[left] > values[index]) {
        largest = left;

    } else {
        largest = index;
    }

    if(right <= heapSize && values[right] > values[largest]) {
        largest = right;
    }

    if(largest != index) {
        swap(index, largest);
        maxHeapify(largest);
    }
}

int HeapSort::leftNode(int index) {
    return (index * 2) + 1;
}

int HeapSort::rightNode(int index) {
    return (index * 2) + 2;
}
