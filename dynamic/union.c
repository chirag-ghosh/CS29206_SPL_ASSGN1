#include "union.h"

#include <stdio.h>
#include <stdlib.h>

UNION_FIND createUF(int n) {
    UNION_FIND newUF;
    newUF.capacity = n;
    newUF.length = 0;
    newUF.nodeArray = (NODE_PTR *)malloc(n * sizeof(NODE_PTR));
    return newUF;
}

UNION_FIND makeSetUF(UNION_FIND F, int x, int *i) {
    NODE_PTR newNode;
    newNode.node = (NODE *)malloc(sizeof(NODE));
    newNode.node->value = x;
    newNode.node->rank = 0;
    newNode.node->parent = newNode.node;
    *i = F.length;
    F.nodeArray[F.length] = newNode;
    F.length++;
    return F;
}

NODE_PTR findUF(UNION_FIND F, int i) {
    NODE_PTR requiredNodePTR = F.nodeArray[i];
    while (requiredNodePTR.node->parent != requiredNodePTR.node) requiredNodePTR.node = requiredNodePTR.node->parent;
    return requiredNodePTR;
}

void unionUF(UNION_FIND F, int i, int j) {
    if (findUF(F, i).node == findUF(F, j).node) return;

    if (findUF(F, i).node->rank < findUF(F, j).node->rank) {
        findUF(F, i).node->parent = findUF(F, j).node;
        findUF(F, j).node->rank += 1;
    } else {
        findUF(F, j).node->parent = findUF(F, i).node;
        findUF(F, i).node->rank += 1;
    }
}