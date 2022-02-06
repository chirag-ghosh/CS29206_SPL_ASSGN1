#include <node.h>

typedef struct _llist {
    int length;
    NODE *head;
    NODE *tail;
} LLIST;

LLIST createList();

int searchList(LLIST H, int k);

LLIST insertAtFront(LLIST H, int k);

LLIST insertAtEnd(LLIST H, int k);

LLIST deleteFromFront(LLIST H, int *k);

LLIST deleteFromEnd(LLIST H, int *k);

LLIST deleteList(LLIST H, int k);