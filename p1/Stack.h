#ifndef STACK_H
#define STACK_H

#include "Node.h"

typedef struct StackObject {

    Node *top;
    int size;

} Stack;

extern Stack *newStack();
extern void push(Stack *s, int x);
extern Node *pop(Stack *s);
extern void printStack(Stack *s);

#endif /* STACK_H */
