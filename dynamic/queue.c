#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

QUEUE createQueue() {
    QUEUE q;
    q = createList();
    return q;
}

int isEmptyQueue(QUEUE Q) {
    return (Q.length == 0);
}

QUEUE enqueue(QUEUE Q, int k) {
    Q = insertAtEnd(Q, k);
    return Q;
}

QUEUE dequeue(QUEUE Q, int *k) {
    if (isEmptyQueue(Q)) return Q;
    Q = deleteFromEnd(Q, k);
    return Q;
}