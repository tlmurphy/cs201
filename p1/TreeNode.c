#include <stdio.h>
#include <stdlib.h>
#include "TreeNode.h"

TreeNode *newTreeNode(int value, TreeNode *parent) {
    TreeNode *tn = malloc(sizeof(TreeNode));
    if (tn == 0) { fprintf(stderr,"out of memory"); exit(-1); }
    
    tn->value = value;
    tn->parent = parent;
    tn->LC = NULL;
    tn->RC = NULL;
    return tn;
}
