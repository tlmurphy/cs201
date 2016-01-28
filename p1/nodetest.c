#include <stdio.h>
#include "Node.h"

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


    return 0;
}
