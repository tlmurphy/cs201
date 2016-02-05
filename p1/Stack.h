#include "Node.h"

typedef struct StackObject {

    Node *top;
    int size;

} Stack;

extern Stack *newStack();
extern void push(Stack *s, int x);
extern void pop(Stack *s);
extern void printStack(Stack *s);
