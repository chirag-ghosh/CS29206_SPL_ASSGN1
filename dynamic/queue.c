#include <queue.h>
#include <stdio.h>
#include <stdlib.h>

QUEUE createQueue() {
    QUEUE q;
    q.list = createList();
    return q;
}

int isEmptyQueue(QUEUE Q) {
    return (Q.list.length == 0);
}

QUEUE enqueue(QUEUE Q, int k) {
    Q.list = insertAtEnd(Q.list, k);
    return Q;
}

QUEUE dequeue(QUEUE Q, int *k) {
    if (isEmptyQueue(Q)) return Q;
    Q.list = deleteFromEnd(Q.list, k);
    return Q;
}