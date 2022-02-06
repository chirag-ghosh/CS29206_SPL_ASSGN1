typedef struct _graph {

    int nodeCount;
    int edgeCount;
    int **adjMatrix;
}GRAPH;

GRAPH readGraph(char *FName);

void DFS(GRAPH G);

void BFS(GRAPH G);

void MST(GRAPH G);