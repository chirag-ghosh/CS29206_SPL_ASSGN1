#include "llist.h"

typedef struct _queue {
    LLIST list;
} QUEUE;

QUEUE createQueue();

int isEmptyQueue(QUEUE Q);

QUEUE enqueue(QUEUE Q, int k);

QUEUE dequeue(QUEUE Q, int *k);