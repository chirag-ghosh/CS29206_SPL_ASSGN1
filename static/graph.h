typedef struct _edge {
    int u;
    int v;
    int weight;
} EDGE;

typedef struct _graph {
    int nodeCount;
    int edgeCount;
    int **adjMatrix;
    EDGE *edgeList;
} GRAPH;

GRAPH readGraph(char *FName);

void DFS(GRAPH G);

void BFS(GRAPH G);

void MST(GRAPH G);