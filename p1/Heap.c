// Heap Structure

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

// Constructor
Heap *newHeap(int Order) {
	Heap *h = malloc(sizeof(Heap));
    if (h == 0) { fprintf(stderr, "NOT ENOUGH MEMORY...EXITING\n"); exit(-1); }
    if (Order == 0) {       // If ascending set to min heap comparison
        h->cmp = &lt;
    } else {                // Else set to max heap comparison
        h->cmp = &gt;
    }
	h->root = NULL;
	return h;
}

// Used to maintain heap structure.
// Compares parent with children, swaps if children are
// more important than parent (less for min heap, greater for max heap).
// Used a loop in place of recursion. From various tests, my recursion
// method was a second slower.
void siftDown(Heap *h, TreeNode *n) {
    TreeNode *iter = n;
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

// Insert values into binary tree (unordered heap)
// utilizing a queue to help in children assignments
// and a stack to keep track of the bottom right node in the tree.
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
