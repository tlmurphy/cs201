/*Queue - Linked List implementation*/
#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"

Queue *newQueue() {
	Queue *q = malloc(sizeof(Queue));
    if (q == 0) { fprintf(stderr,"out of memory"); exit(-1); }

	q->front = NULL;
	q->back = NULL;
	return q;
}

// To Enqueue an integer
void enqueue(Queue *q, int x) {
	Node *temp = newNode(x);
	if(q->front == NULL && q->back == NULL){
		q->front = q->back = temp;
		return;
	}
	q->back->next = temp;
	q->back = temp;
	q->size++;
}

// To Dequeue an integer.
void dequeue(Queue *q) {
	Node *temp = q->front;
	if(q->front == NULL) {
		printf("Queue is Empty!\n");
		return;
	}
	if(q->front == q->back) {
		q->front = q->back = NULL;
	}
	else {
		q->front = q->front->next;
	}
	q->size--;
	free(temp);
}

void printQueue(Queue *q) {
	Node *temp = q->front;
	while(temp != NULL) {
		printf("%d ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}
