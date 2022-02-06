#define MAX_CAPACITY 100

typedef struct _heap {
    int length;
    int array[MAX_CAPACITY];
} HEAP;

// Creates an empty heap, and returns it.
HEAP createHeap();

// Returns the minimum value in the heap H
int findMin(HEAP H);

// Deletes the minimum value from the heap and returns the modified heap
HEAP extractMin(HEAP H);

//  inserts the value k in the heap H, and returns the new heap.
HEAP insertHeap(HEAP H, int k);

// Returns 1 if the heap is full, 0 otherwise
int isFullHeap(HEAP H);

// Returns 1 if the heap is empty, 0 otherwise
int isEmptyHeap(HEAP H);