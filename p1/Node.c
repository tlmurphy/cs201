#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

Node *newTreeNode(int value, Node *parent) {
    Node *n = (Node *) malloc(sizeof(Node));
    if (n == 0) { fprintf(stderr,"out of memory"); exit(-1); }

    n->value = value;
    n->parent = parent;
    n->LC = NULL;
    n->RC = NULL;
    return n;
}

Node *newNode(int value) {
    Node *n = malloc(sizeof(Node));
    if (n == 0) { fprintf(stderr,"out of memory"); exit(-1); }
    n->value = value;
    n->next = NULL;
    return n;
}
