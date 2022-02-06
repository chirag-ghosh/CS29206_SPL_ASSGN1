typedef struct _node {
    int value;
    int rank;
    struct _node* parent;
} NODE;

typedef struct _nodeptr {
    NODE* node;
} NODE_PTR;

typedef struct _unionfind {
    int capacity;
    int length;
    NODE_PTR* nodeArray;
} UNION_FIND;

UNION_FIND createUF(int n);

UNION_FIND makeSetUF(UNION_FIND F, int x, int* i);

NODE_PTR findUF(UNION_FIND F, int i);

void unionUF(UNION_FIND F, int i, int j);