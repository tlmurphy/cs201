/*
Linked-list implementation of Stack
 */

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

Stack *newStack() {
    Stack *s = malloc(sizeof(Stack));
    if (s == 0) { fprintf(stderr, "NOT ENOUGH MEMORY...EXITING\n"); exit(-1); }

    s->top = NULL;
    return s;
}

void push(Stack *s, TreeNode *tn) {
    Node *temp = newNode(tn);
    if (s->top == NULL) {
        s->top = temp;
        return;
    }
    temp->next = s->top;
    s->top = temp;
}

void pop(Stack *s) {
    Node *temp = s->top;
    if (s->top == NULL) {
        printf("Stack is Empty!\n");
        return;
    }

    // Sever the parent-child connection when popping
    TreeNode *parent = temp->treeNode->parent;
    if (parent != NULL) {
        if (parent->LC != NULL) {
            if (parent->LC->value == temp->treeNode->value) {
                parent->LC = NULL;
            }
        }
        if (parent->RC != NULL) {
            if (parent->RC->value == temp->treeNode->value) {
                parent->RC = NULL;
            }
        }
    }
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

// Very handy in debugging
void checkStack(Stack *s) {
    Node *temp = s->top;
    while (temp != NULL) {
        TreeNode *tn = temp->treeNode;
        printf("VALUE: %d, ", tn->value);
        if (tn->parent == NULL)
            printf("NO PARENT, ");
        else
            printf("PARENT: %d, ", tn->parent->value);
        if (tn->LC == NULL)
            printf("NO LC, ");
        else
            printf("LC: %d, ", tn->LC->value);
        if (tn->RC == NULL)
            printf("NO RC");
        else
            printf("RC: %d", tn->RC->value);
        temp = temp->next;
        printf("\n");
    }
}
