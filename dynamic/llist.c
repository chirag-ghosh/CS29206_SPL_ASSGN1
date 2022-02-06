// import node here
#include "node.h"
// import header
#include "llist.h"

// system
#include <stdio.h>
#include <stdlib.h>

LLIST createList() {
    LLIST newllist;
    newllist.length = 0;
    newllist.head = NULL;
    newllist.tail = NULL;
    return newllist;
}

int searchList(LLIST H, int k) {
    NODE* currentNode = H.head;
    while (currentNode != NULL) {
        if (currentNode->value == k) return 1;
        currentNode = currentNode->next;
    }
    return 0;
}

LLIST insertAtFront(LLIST H, int k) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->value = k;
    newNode->next = H.head;
    H.head = newNode;
    H.length += 1;
    return H;
}

LLIST insertAtEnd(LLIST H, int k) {
    if (H.length == 0) return insertAtFront(H, k);
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->value = k;
    newNode->next = NULL;
    H.tail->next = newNode;
    H.tail = newNode;
    H.length += 1;
    return H;
}

LLIST deleteFromFront(LLIST H, int* k) {
    if (H.length == 0) {
        return H;
    }

    *k = H.head->value;
    NODE* existingNode = H.head;
    H.head = existingNode->next;
    free(existingNode);
    H.length -= 1;
    return H;
}

LLIST deleteFromEnd(LLIST H, int* k) {
    if (H.length == 0) {
        return H;
    }

    *k = H.tail->value;
    NODE* existingNode = H.tail;

    H.tail = NULL;
    NODE* tempNode = H.head;
    while (tempNode != NULL) {
        if (tempNode->next == existingNode) {
            H.tail = tempNode;
            break;
        }
        tempNode = tempNode->next;
    }
    free(existingNode);
    H.length -= 1;
    return H;
}

LLIST deleteList(LLIST H, int k) {
    NODE* tempNode = H.head;
    NODE* parentNode = NULL;
    while (tempNode != NULL) {
        if (tempNode->value == k) {
            if (tempNode == H.head)
                H.head = tempNode->next;
            else if (tempNode == H.tail)
                H.tail = parentNode;
            else
                parentNode->next = tempNode->next;
            free(tempNode);
            break;
        }
        parentNode = tempNode;
        tempNode = tempNode->next;
    }
    return H;
}