typedef struct _heap {
    int length;
    int array[100];
} HEAP;

HEAP createHeap();

int findMin(HEAP H);

HEAP extractMin(HEAP H);

HEAP insertHeap(HEAP H, int k);

int isFullHeap(HEAP H);

int isEmptyHeap(HEAP H);