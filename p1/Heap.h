#include "TreeNode.h"
#include "Queue.h"
#include "Stack.h"

typedef struct HeapObject {

    // Min or Max heap?
    TreeNode *root;
    int size;
    int (*cmp)(int, int);

} Heap;

extern Heap *newHeap(int Order);
extern void insert(Heap *h, Queue *q, Stack *s, int x);
extern void siftUp(Heap *h, TreeNode *tn);
extern void siftDown(Heap *h);
extern void swap(int *x, int *y);
extern int lt(int, int);
extern int gt(int, int);
