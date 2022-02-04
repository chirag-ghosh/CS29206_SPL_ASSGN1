#include "llist.h"

typedef struct _stack {
    LLIST list;
} STACK;

STACK createStack();

int isEmptyStack(STACK S);

STACK push(STACK S, int k);

STACK pop(STACK S, int *k);