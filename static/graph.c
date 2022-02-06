#include "graph.h"

#include <basic.h>
#include <stdio.h>
#include <stdlib.h>

GRAPH createGraph(int nodeCount, int edgeCount) {
    GRAPH newGraph;
    newGraph.nodeCount = nodeCount;
    newGraph.edgeCount = edgeCount;
    newGraph.adjMatrix = (int **)malloc(nodeCount * sizeof(int *));
    for (int i = 0; i < nodeCount; i++) {
        newGraph.adjMatrix[i] = (int *)malloc(nodeCount * sizeof(int));
        for (int j = 0; j < nodeCount; j++) {
            newGraph.adjMatrix[i][j] = 0;
        }
    }
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

int main() {
    GRAPH G = readGraph("testing.txt");
    printf("DFS traversal is : ");
    DFS(G);
    printf("\n");
    return 0;
}