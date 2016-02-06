#ifndef TREENODE_H
#define TREENODE_H

typedef struct TreeNodeObject {

    int value;

    struct TreeNodeObject *parent;
    struct TreeNodeObject *LC;
    struct TreeNodeObject *RC;

} TreeNode;

extern TreeNode *newTreeNode(int value, TreeNode *parent);

#endif /* TREENODE_H */
