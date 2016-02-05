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
    enqueue(q, x);
    if (h->root == NULL) {
        h->root = newTreeNode(x, NULL);
        q->size--; // Don't want increment this when root
    } else {
        if (q->size == 2) {
            Node *temp = dequeue(q);
            push(s, temp->value);
            free(temp);
        }
    }


    // min heap comparison
    // if (q->back->value < q->front->value) {
    //     int temp = q->back->value;
    //     q->back->value = q->front->value;
    //     q->front->value = temp;
    // }


    // if (h->size == 0) {
    //     h->root = newTreeNode(x, NULL);
    // } else {
    //     //Node *tNode = newTreeNode(x, q->front);
    // }
}
