#include "heap.h"

#include <stdio.h>
#include <stdlib.h>

int getParent(int index) {
    return (index - 1) / 2;
}

int getLeftChild(int index) {
    return (2 * index + 1);
}

int getRightChild(int index) {
    return (2 * index + 2);
}

void swapKeys(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int isFullHeap(HEAP H) {
    return (H.length == MAX_CAPACITY);
}

int isEmptyHeap(HEAP H) {
    return (H.length == 0);
}

HEAP minHeapify(HEAP myHeap, int index) {
    int left = getLeftChild(index);
    int right = getRightChild(index);

    int min = index;

    if (left < myHeap.length && myHeap.array[left] < myHeap.array[min]) {
        min = left;
    }
    if (right < myHeap.length && myHeap.array[right] < myHeap.array[min]) {
        min = right;
    }

    if (min != index) {
        swapKeys(&myHeap.array[min], &myHeap.array[index]);
        myHeap = minHeapify(myHeap, min);
    }

    return myHeap;
}

HEAP createHeap() {
    HEAP newHeap;
    newHeap.length = 0;
    return newHeap;
}

int findMin(HEAP H) {
    if (isEmptyHeap(H)) {
        printf("Heap empty");
        return -1;
    }
    return H.array[0];
}

HEAP extractMin(HEAP H) {
    if (isEmptyHeap(H)) {
        printf("Heap empty");
        return H;
    } else if (H.length == 1) {
        H.length--;
        return H;
    } else {
        int value = H.array[0];
        H.array[0] = H.array[--(H.length)];
        return minHeapify(H, 0);
    }
}

HEAP insertHeap(HEAP H, int k) {
    if (isFullHeap(H)) {
        printf("Heap full");
        return H;
    }

    int index = H.length;
    H.length++;
    H.array[index] = k;

    while (index != 0 && H.array[index] < H.array[getParent(index)]) {
        swapKeys(&H.array[index], &H.array[getParent(index)]);
        index = getParent(index);
    }
    return H;
}