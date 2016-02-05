#include "Node.h"

typedef struct QueueObject {

    Node *front;
    Node *back;
    int size;

} Queue;

extern Queue *newQueue();
extern void enqueue(Queue *q, int x);
extern void dequeue(Queue *q);
extern void printQueue(Queue *q);
