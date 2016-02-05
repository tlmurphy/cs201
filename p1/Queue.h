#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

typedef struct QueueObject {

    Node *front;
    Node *back;
    int size;

} Queue;

extern Queue *newQueue();
extern void enqueue(Queue *q, int x);
extern Node *dequeue(Queue *q);
extern void printQueue(Queue *q);

#endif /* QUEUE_H */
