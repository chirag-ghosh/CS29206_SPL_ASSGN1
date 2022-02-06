#include "graph.h"

#include <basic.h>
#include <stdio.h>
#include <stdlib.h>

void mergesort(EDGE *edgeList, int n) {
    EDGE *tempList;
    int LS, LE, RS, RE, i, j, k;

    if (n <= 1) return;

    mergesort(edgeList, n / 2);
    mergesort(edgeList + n / 2, n - n / 2);

    /* Merging */
    tempList = (EDGE *)malloc(n * sizeof(EDGE));

    LS = 0;
    LE = n / 2 - 1;
    RS = LE + 1;
    RE = n - 1;

    i = LS;
    j = RS;
    k = 0;
    while ((i <= LE) || (j <= RE)) {
        if (i > LE)
            tempList[k] = edgeList[j++];
        else if (j > RE)
            tempList[k] = edgeList[i++];
        else if (edgeList[i].weight <= edgeList[j].weight)
            tempList[k] = edgeList[i++];
        else
            tempList[k] = edgeList[j++];
        ++k;
    }
    for (i = 0; i < n; ++i) edgeList[i] = tempList[i];
    free(tempList);
}

GRAPH createGraph(int nodeCount, int edgeCount) {
    static GRAPH newGraph;
    newGraph.nodeCount = nodeCount;
    newGraph.edgeCount = edgeCount;
    newGraph.adjMatrix = (int **)malloc(nodeCount * sizeof(int *));
    for (int i = 0; i < nodeCount; i++) {
        newGraph.adjMatrix[i] = (int *)malloc(nodeCount * sizeof(int));
        for (int j = 0; j < nodeCount; j++) {
            newGraph.adjMatrix[i][j] = 0;
        }
    }
    newGraph.edgeList = (EDGE *)malloc(edgeCount * sizeof(EDGE));
    return newGraph;
}

GRAPH readGraph(char *FName) {
    FILE *filePointer;
    filePointer = fopen(FName, "r");

    int nodeCount, edgeCount;
    fscanf(filePointer, "%d", &nodeCount);
    fscanf(filePointer, "%d", &edgeCount);

    GRAPH graph = createGraph(nodeCount, edgeCount);

    for (int i = 0; i < edgeCount; i++) {
        int u, v, weight;
        fscanf(filePointer, "%d %d %d", &u, &v, &weight);
        graph.adjMatrix[u][v] = weight;
        graph.adjMatrix[v][u] = weight;

        EDGE newEdge;
        newEdge.u = u;
        newEdge.v = v;
        newEdge.weight = weight;
        graph.edgeList[i] = newEdge;
    }

    return graph;
}

void DFS(GRAPH G) {
    int *visited;
    visited = (int *)malloc(G.nodeCount * sizeof(int));
    for (int i = 0; i < G.nodeCount; i++) visited[i] = 0;
    STACK myStack = createStack();

    for (int i = 0; i < G.nodeCount; i++) {
        if (visited[i] == 1) continue;

        myStack = push(myStack, i);
        visited[i] = 1;

        while (!isEmptyStack(myStack)) {
            int currentNode;
            myStack = pop(myStack, &currentNode);
            printf("%d ", currentNode);

            for (int j = 0; j < G.nodeCount; j++) {
                if (G.adjMatrix[currentNode][j] != 0 && visited[j] == 0) {
                    myStack = push(myStack, j);
                    visited[j] = 1;
                }
            }
        }
    }
}

void BFS(GRAPH G) {
    int *visited;
    visited = (int *)malloc(G.nodeCount * sizeof(int));
    for (int i = 0; i < G.nodeCount; i++) visited[i] = 0;
    QUEUE myQueue = createQueue();

    for (int i = 0; i < G.nodeCount; i++) {
        if (visited[i] == 1) continue;

        myQueue = enqueue(myQueue, i);
        visited[i] = 1;
        while (!isEmptyQueue(myQueue)) {
            int currentNode;
            myQueue = dequeue(myQueue, &currentNode);
            printf("%d ", currentNode);

            for (int j = 0; j < G.nodeCount; j++) {
                if (G.adjMatrix[currentNode][j] != 0 && visited[j] == 0) {
                    myQueue = enqueue(myQueue, j);
                    visited[j] = 1;
                }
            }
        }
    }
}

void MST(GRAPH G) {
    mergesort(G.edgeList, G.edgeCount);

    UNION_FIND F = createUF(G.nodeCount);

    int *k = (int *)malloc(sizeof(int));
    for (int i = 0; i < G.nodeCount; i++) {
        F = makeSetUF(F, i, k);
    }
    free(k);

    int cost = 0;
    printf("MST Edges:\n");
    printf("From\tTo\tWeight\n");
    for (int i = 0; i < G.edgeCount; i++) {
        if (findUF(F, G.edgeList[i].u).node != findUF(F, G.edgeList[i].v).node) {
            unionUF(F, G.edgeList[i].u, G.edgeList[i].v);
            cost += G.edgeList[i].weight;
            printf("%d\t%d\t%d\n", G.edgeList[i].u, G.edgeList[i].v, G.edgeList[i].weight);
        }
    }
    printf("MST cost: %d\n", cost);
}