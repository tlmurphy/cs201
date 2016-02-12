// Tree node holds the actual integers
// and containers pointers to its parent,
// left child, and right child

#include <stdio.h>
#include <stdlib.h>
#include "TreeNode.h"

TreeNode *newTreeNode(int value, TreeNode *parent) {
    TreeNode *tn = malloc(sizeof(TreeNode));
    if (tn == 0) { fprintf(stderr, "NOT ENOUGH MEMORY...EXITING"); exit(-1); }
    tn->value = value;
    tn->parent = parent;
    tn->LC = NULL;
    tn->RC = NULL;
    return tn;
}
