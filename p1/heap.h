#include "node.h"

typedef struct heapobject {

    node *root;

} heap;

extern node *newNode(int value, node *parent);
