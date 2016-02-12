// Linked-list implemenation of Queue

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Node.h"

Queue *newQueue() {
	Queue *q = malloc(sizeof(Queue));
    if (q == 0) { fprintf(stderr, "NOT ENOUGH MEMORY...EXITING\n"); exit(-1); }
	q->front = NULL;
	q->back = NULL;
	return q;
}

void enqueue(Queue *q, TreeNode *tn) {
	Node *temp = newNode(tn);
	if (q->front == NULL && q->back == NULL) { // Queue is Empty
		q->front = q->back = temp;
		return;
	}
	q->back->next = temp;
	q->back = temp;
}

void dequeue(Queue *q) {
	Node *temp = q->front;
	if (q->front == NULL) {
		printf("Queue is Empty!\n");
		return;
	}
	if (q->front == q->back) // Only one item left
        q->front = q->back = NULL;
    else
		q->front = q->front->next;
    free(temp);
}

void printQueue(Queue *q) {
	Node *iter = q->front;
	while (iter != NULL) {
		printf("%d ", iter->treeNode->value);
		iter = iter->next;
	}
	printf("\n");
}
