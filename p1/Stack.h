#ifndef STACK_H
#define STACK_H

#include "Node.h"

typedef struct StackObject {

    Node *top;
    int size;

} Stack;

extern Stack *newStack();
extern void push(Stack *s, TreeNode *tn);
extern void pop(Stack *s);
extern void printStack(Stack *s);
extern void checkStack(Stack *s);

#endif /* STACK_H */
