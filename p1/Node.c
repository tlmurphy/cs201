// Node struct for Queue and Stack
// Contains a tree node as its data

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

Node *newNode(TreeNode *tn) {
    Node *n = malloc(sizeof(Node));
    if (n == 0) { fprintf(stderr, "NOT ENOUGH MEMORY...EXITING"); exit(-1); }
    n->treeNode = tn;
    n->next = NULL;
    return n;
}
