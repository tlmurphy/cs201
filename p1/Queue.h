#include "Node.h"

typedef struct QueueObject {
    struct NodeObject *front;
    struct NodeObject *back;
    int size;
} Queue;

extern Queue *newQueue();
extern void enqueue(Queue *q, int x);
