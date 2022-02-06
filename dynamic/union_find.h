// special node for union find
typedef struct _unionnode {
    int value;
    int rank;
    struct _unionnode* parent;
} UNIONNODE;

typedef struct _nodeptr {
    UNIONNODE* node;
} NODE_PTR;

typedef struct _unionfind {
    int capacity;
    int length;
    NODE_PTR* nodeArray;
} UNION_FIND;

// creates a UNION_FIND data structure that can store n node pointers. Initially, all these pointers are NULL.
UNION_FIND createUF(int n);

// Creates a singleton set (a node) for the element x, adds to F a pointer to that node,
// and returns the modified UNION_FIND structure.
// An int pointer is passed additionally to return the insertion index.
UNION_FIND makeSetUF(UNION_FIND F, int x, int* i);

// returns the ID of the set to which the element pointed to by the i-th pointer in F belongs.
// The ID is a pointer to the root node of the tree containing that element.
NODE_PTR findUF(UNION_FIND F, int i);

// merges the sets containing the elements pointed to by the i-th and the j-th pointers of F.
//  the tree with the smaller number of nodes is made a subtree of the tree with the larger number of nodes
void unionUF(UNION_FIND F, int i, int j);