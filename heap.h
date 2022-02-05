#define MAX_CAPACITY 100

typedef struct _heap {
    int length;
    int array[MAX_CAPACITY];
} HEAP;

HEAP createHeap();

int findMin(HEAP H);

HEAP extractMin(HEAP H);

HEAP insertHeap(HEAP H, int k);

int isFullHeap(HEAP H);

int isEmptyHeap(HEAP H);