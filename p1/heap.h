#include "Node.h"
#include "Queue.h"
#include "Stack.h"

typedef struct HeapObject {

    // Min or Max heap?
    Node *root;
    int size;

} Heap;

extern Heap *newHeap();
extern void insert(Heap *h, Queue *q, Stack *s, int x);
