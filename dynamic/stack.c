// import node here
#include "node.h"

// import llist here
#include "llist.h"

// import header
#include "stack.h"

STACK createStack() {
    STACK s;
    s = createList();
    return s;
}

int isEmptyStack(STACK S) {
    return (S.length == 0);
}

STACK push(STACK S, int k) {
    S = insertAtFront(S, k);
    return S;
}

STACK pop(STACK S, int *k) {
    if (isEmptyStack(S)) return S;
    S = deleteFromFront(S, k);
    return S;
}