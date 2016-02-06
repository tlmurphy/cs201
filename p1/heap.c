#include "Heap.h"
#include <stdio.h>
#include <stdlib.h>

Heap *newHeap() {
	Heap *h = malloc(sizeof(Heap));
    if (h == 0) { fprintf(stderr,"NOT ENOUGH MEMORY...EXITING\n"); exit(-1); }

	h->root = NULL;
    h->size = 0;
	return h;
}

void insert(Heap *h, Queue *q, Stack *s, int x) {
    if (h->root == NULL) {
        h->root = newTreeNode(x, NULL);
        enqueue(q, h->root);
        push(s, h->root);
    } else {
        TreeNode *parent = q->front->treeNode;
        TreeNode *leftChild = q->front->treeNode->LC;
        TreeNode *tn = newTreeNode(x, parent);
        enqueue(q, tn);
        if (leftChild == NULL) {
            parent->LC = tn;
            TreeNode *iter = tn;
            while (iter->parent != NULL && iter->value < iter->parent->value) {
                int temp = iter->value;
                iter->value = iter->parent->value;
                iter->parent->value = temp;
                iter = iter->parent;
            }
        } else {
            parent->RC = tn;
            TreeNode *iter = tn;
            while (iter->parent != NULL && iter->value < iter->parent->value) {
                int temp = iter->value;
                iter->value = iter->parent->value;
                iter->parent->value = temp;
                iter = iter->parent;
            }
            dequeue(q);
        }
        push(s, tn);
    }
}
