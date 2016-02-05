#ifndef NODE_H
#define NODE_H

typedef struct NodeObject {

    int value;

    struct NodeObject *parent;
    struct NodeObject *LC;
    struct NodeObject *RC;

    struct NodeObject *next;

} Node;

extern Node *newTreeNode(int value, Node *parent);
extern Node *newNode(int value);

#endif /* NODE_H */
