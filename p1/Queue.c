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
}

// // To Dequeue an integer.
// void Dequeue() {
// 	Node* temp = front;
// 	if(front == NULL) {
// 		printf("Queue is Empty\n");
// 		return;
// 	}
// 	if(front == rear) {
// 		front = rear = NULL;
// 	}
// 	else {
// 		front = front->next;
// 	}
// 	free(temp);
// }
//
// int Front() {
// 	if(front == NULL) {
// 		printf("Queue is empty\n");
// 		return;
// 	}
// 	return front->data;
// }
//
// void Print() {
// 	Node* temp = front;
// 	while(temp != NULL) {
// 		printf("%d ",temp->data);
// 		temp = temp->next;
// 	}
// 	printf("\n");
// }
//
// int main(){
// 	/* Drive code to test the implementation. */
// 	// Printing elements in Queue after each Enqueue or Dequeue
// 	Enqueue(2); Print();
// 	Enqueue(4); Print();
// 	Enqueue(6); Print();
// 	Dequeue();  Print();
// 	Enqueue(8); Print();
// }
