#include "Node.h"
typedef struct HeapObject {

    // Min or Max heap?
    Node *root;
    int size;

} Heap;

extern Heap *newHeap();
