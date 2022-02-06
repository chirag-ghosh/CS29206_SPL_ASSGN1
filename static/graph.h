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

// Reads the nodes and edges of a graph from a file with name FName
GRAPH readGraph(char *FName);

// Does a DFS traversal of the graph G using the STACK data type, and prints out the nodes in the DFS traversal order.
// Ignores weight
void DFS(GRAPH G);

// Does a BFS traversal of the graph G using the QUEUE data type, and prints out the nodes in the BFS traversal order.
// Ignores weight
void BFS(GRAPH G);

// Computes the minimum spanning tree of the graph G using Kruskal’s algorithm using UNION_FIND
void MST(GRAPH G);