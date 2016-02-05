#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int main() {
    Node *n, *p, *q;

    n = newTreeNode(5, NULL);
    p = newTreeNode(78, n);
    q = newTreeNode(12, n);
    n->LC = p;
    n->RC = q;

    printf("ROOT: %d\n", n->value);
    printf("LEFT CHILD: %d\n", n->LC->value);
    printf("RIGHT CHILD: %d\n", n->RC->value);
    if (p->LC != NULL && p->RC != NULL) {
        printf("LEFT CHILD OF NODE 78: %d\n", p->LC->value);
        printf("RIGHT CHILD OF NODE 78: %d\n", p->RC->value);
    } else {
        printf("The values of these nodes are NULL!\n");
    }

    Queue *hey;
    hey = newQueue();
    enqueue(hey, 55);
    enqueue(hey, 90);
    enqueue(hey, 100);
    printQueue(hey);
    printf("DEQUEUE 1 VALUE...\n");
    dequeue(hey);
    printQueue(hey);

    return 0;
}
