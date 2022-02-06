typedef struct _llist {
    int length;
    NODE *head;
    NODE *tail;
} LLIST;

// creates an empty linked list, and returns it
LLIST createList();

// searches for the value k in the list H. Returns 1 if k is found, 0 otherwise.
int searchList(LLIST H, int k);

// inserts the value k at the beginning of the list H. Returns the new list
LLIST insertAtFront(LLIST H, int k);

// inserts the value k at the end of the list H. Returns the new list
LLIST insertAtEnd(LLIST H, int k);

// deletes the first element from the list and returns the value stored in that node using the pointer k. Returns the new list as the return value
LLIST deleteFromFront(LLIST H, int *k);

// deletes the last element from the list and returns the value stored in that node using the pointer k. Returns the new list as the return value.
LLIST deleteFromEnd(LLIST H, int *k);

// deletes the value k from the list H if it is present. Returns the new list. If the value k occurs multiple times, only its first occurrence in the list is deleted
LLIST deleteList(LLIST H, int k);