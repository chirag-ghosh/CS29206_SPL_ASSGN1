typedef LLIST STACK;

//  Creates an empty stack, and returns it
STACK createStack();

// returns 1 if the stack S is empty, 0 otherwise.
int isEmptyStack(STACK S);

//  pushes a value k in the stack S, and returns the new stack.
STACK push(STACK S, int k);

// pops the top element from the stack, and returns that element using the pointer k. Returns the new stack as the return value
STACK pop(STACK S, int *k);