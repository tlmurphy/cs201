#include "Heap.h"
#include <stdio.h>
#include <stdlib.h>

int lt(int x, int y) {
    return x < y;
}

int gt(int x, int y) {
    return x > y;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

Heap *newHeap(int Order) {
	Heap *h = malloc(sizeof(Heap));
    if (h == 0) { fprintf(stderr,"NOT ENOUGH MEMORY...EXITING\n"); exit(-1); }

    if (Order == 0) {
        h->cmp = &lt;
    } else {
        h->cmp = &gt;
    }
	h->root = NULL;
	return h;
}

void siftDown(Heap *h, TreeNode *n) {
    TreeNode *iter = n;
    //((x) > 32 ? (x) : (2 * (x)))

    // if (n->RC == NULL) {
    //     if (n->LC == NULL) return;
    //     if (h->cmp(n->LC->value, n->value)) {
    //         swap(&n->LC->value, &n->value);
    //         siftDown(h, n->LC);
    //     } else return;
    // } else {
    //     if (h->cmp(n->LC->value, n->RC->value)) {
    //         if (h->cmp(n->LC->value, n->value)) {
    //             swap(&n->LC->value, &n->value);
    //             siftDown(h, n->LC);
    //         } else return;
    //     } else {
    //         if (h->cmp(n->RC->value, n->value)) {
    //             swap(&n->RC->value, &n->value);
    //             siftDown(h, n->RC);
    //         } else return;
    //     }
    // }


    while (1) {
        if (iter->RC == NULL) {
            if (iter->LC == NULL) return;
            if (h->cmp(iter->LC->value, iter->value)) {
                swap(&iter->LC->value, &iter->value);
                iter = iter->LC;
            } else return;
        } else {
            if (h->cmp(iter->LC->value, iter->RC->value)) {
                if (h->cmp(iter->LC->value, iter->value)) {
                    swap(&iter->LC->value, &iter->value);
                    iter = iter->LC;
                } else return;
            } else {
                if (h->cmp(iter->RC->value, iter->value)) {
                    swap(&iter->RC->value, &iter->value);
                    iter = iter->RC;
                } else return;
            }
        }
    }
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
        } else {
            parent->RC = tn;
            dequeue(q);
        }
        push(s, tn);
    }
}
