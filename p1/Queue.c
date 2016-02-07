/*Queue - Linked List implementation*/
#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"
#include "Node.h"

Queue *newQueue() {
	Queue *q = malloc(sizeof(Queue));
    if (q == 0) { fprintf(stderr,"NOT ENOUGH MEMORY...EXITING\n"); exit(-1); }

	q->front = NULL;
	q->back = NULL;
    q->size = 0;
	return q;
}

// To Enqueue an integer
void enqueue(Queue *q, TreeNode *tn) {
    q->size++;
	Node *temp = newNode(tn);
	if (q->front == NULL && q->back == NULL){
		q->front = q->back = temp;
		return;
	}
	q->back->next = temp;
	q->back = temp;
}

// To Dequeue an integer.
void dequeue(Queue *q) {
	Node *temp = q->front;
	if (q->front == NULL) {
		printf("Queue is Empty!\n");
		return;
	}
    q->size = 0;
	if (q->front == q->back)
        q->front = q->back = NULL;
    else
		q->front = q->front->next;

    free(temp);
}

void printQueue(Queue *q) {
	Node *temp = q->front;
	while(temp != NULL) {
		printf("%d ", temp->treeNode->value);
		temp = temp->next;
	}
	printf("\n");
}
