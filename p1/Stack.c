/*
Stack implemented in linked list
 */
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

Stack *newStack() {
    Stack *s = malloc(sizeof(Stack));
    if (s == 0) { fprintf(stderr, "NOT ENOUGH MEMORY...EXITING\n"); exit(-1); }

    s->top = NULL;
    s->size = 0;
    return s;
}

// To push a value onto the stack
void push(Stack *s, TreeNode *tn) {
    s->size++;
    Node *temp = newNode(tn);
    if (s->top == NULL) {
        s->top = temp;
        return;
    }
    temp->next = s->top;
    s->top = temp;
}

// To pop a value from the stack
void pop(Stack *s) {
    Node *temp = s->top;
    if (s->top == NULL) {
        printf("Stack is Empty!\n");
        return;
    }
    s->size--;
    s->top = s->top->next;
    free(temp);
}

void printStack(Stack *s) {
    Node *temp = s->top;
    while (temp != NULL) {
        printf("%d ", temp->treeNode->value);
        temp = temp->next;
    }
    printf("\n");
}

void checkStack(Stack *s) {
    Node *temp = s->top;
    while (temp != NULL) {
        TreeNode *tn = temp->treeNode;
        printf("VALUE: %d, ", tn->value);
        if (tn->parent == NULL) {
            printf("NO PARENT, ");
        } else {
            printf("PARENT: %d, ", tn->parent->value);
        }
        if (tn->LC == NULL) {
            printf("NO LC, ");
        } else {
            printf("LC: %d, ", tn->LC->value);
        }
        if (tn->RC == NULL) {
            printf("NO RC");
        } else {
            printf("RC: %d", tn->RC->value);
        }
        temp = temp->next;
        printf("\n");
    }
}
