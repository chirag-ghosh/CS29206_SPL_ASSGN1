typedef LLIST QUEUE;

// Creates an empty queue, and returns it.
QUEUE createQueue();

// returns 1 if the queue Q is empty, 0 otherwise
int isEmptyQueue(QUEUE Q);

//  adds a value k to the back of the queue, and returns the new queue
QUEUE enqueue(QUEUE Q, int k);

// removes the element at the front and returns that element using the pointer k. Returns the new queue as the return value
QUEUE dequeue(QUEUE Q, int *k);