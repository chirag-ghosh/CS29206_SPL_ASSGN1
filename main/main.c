#include <basic.h>
#include <graph.h>
#include <stdio.h>
#include <stdlib.h>

// starting point of the code. takes file from user and performs graph operations
int main(int argc, char const* argv[]) {
    char* str = (char*)malloc(100 * sizeof(char));
    printf("Enter file name: ");
    scanf("%s", str);
    GRAPH G;
    G = readGraph(str);
    printf("\nDFS Traversal: ");
    DFS(G);
    printf("\n\n");
    printf("BFS Traversal: ");
    BFS(G);
    printf("\n\n");
    printf("Performing MST....\n");
    MST(G);
    return 0;
}
