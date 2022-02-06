#include <stack.h>

STACK createStack() {
    STACK s;
    s.list = createList();
    return s;
}

int isEmptyStack(STACK S) {
    return (S.list.length == 0);
}

STACK push(STACK S, int k) {
    S.list = insertAtFront(S.list, k);
    return S;
}

STACK pop(STACK S, int *k) {
    if (isEmptyStack(S)) return S;
    S.list = deleteFromFront(S.list, k);
    return S;
}