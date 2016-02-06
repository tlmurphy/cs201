#ifndef NODE_H
#define NODE_H

#include "TreeNode.h"

typedef struct NodeObject {

    TreeNode *treeNode;
    struct NodeObject *next;

} Node;

extern Node *newNode(TreeNode *tn);

#endif /* NODE_H */
