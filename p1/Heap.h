#include "TreeNode.h"
#include "Queue.h"
#include "Stack.h"

typedef struct HeapObject {

    TreeNode *root;
    int (*cmp)(int, int); // Function pointer for either min or max heap

} Heap;

extern Heap *newHeap(int Order);
extern void insert(Heap *h, Queue *q, Stack *s, int x);
extern void siftDown(Heap *h, TreeNode *n);
extern void swap(int *x, int *y);
extern int lt(int, int);
extern int gt(int, int);
