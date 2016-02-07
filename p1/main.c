//============================================================================
// Name        : Project 1
// Author      : Trevor Murphy
// Version     : 1.0
// Description : Heap Sort using a Binary Tree
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>

#include "Queue.h"
#include "Stack.h"
#include "Heap.h"

/* options */
int Order = 0;      /* option -d      */
int Desc = 0;       /* option -v      */

int ProcessOptions(int,char **);
void Fatal(char *,...);
void buildHeap(Heap *h, Queue *q, Stack *s);
void sort(Heap *h, Stack *s);
void printLevelOrder(TreeNode* root);
void printGivenLevel(TreeNode* root, int level);
int height(TreeNode* node);

int main(int argc,char **argv) {
    //int argIndex;
    clock_t t;
    t = clock();

    ProcessOptions(argc,argv);

    printf("Sorting in %s order\n", Order == 0? "increasing" : "decreasing");
    printf("Dash v is %s\n", Desc == 0? "not enabled" : "enabled");

    Queue *q;
    Stack *s;
    Heap *h;
    q = newQueue();
    s = newStack();
    h = newHeap(Order);

    if (Order == 0) h->cmp = lt;
    else h->cmp = gt;

    buildHeap(h, q, s);
    //printf("THE STACK: \n");
    //printStack(s);
    //printf("THE QUEUE: \n");
    //printQueue(q);
    //checkStack(s);
    //printf("HEAP ROOT: %d\n", h->root->value);
    // printf("HEAP LC: %d\n", h->root->LC->value);
    // printf("HEAP RC: %d\n", h->root->RC->value);
    // printf("HEAP LC LC %d\n", h->root->LC->LC->value);
    // printf("STACK HEAD: %d\n", s->top->treeNode->value);

    printf("BEGINNING SORT!\n");
    sort(h, s);
    free(q);
    free(s);
    free(h);

    t = clock() - t;
    double time_taken = ((double) t)/CLOCKS_PER_SEC;
    printf("%f seconds to execute...\n", time_taken);
    return 0;
}

void Fatal(char *fmt, ...) {
    va_list ap;

    fprintf(stderr,"An error occured: ");
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);

    exit(-1);
}

/* only -oXXX  or -o XXX options */

int ProcessOptions(int argc, char **argv) {
    int argIndex;
    int argUsed;
    int separateArg;
    char *arg;

    argIndex = 1;

    while (argIndex < argc && *argv[argIndex] == '-') {
        /* check if stdin, represented by "-" is an argument */
        /* if so, the end of options has been reached */
        if (argv[argIndex][1] == '\0') return argIndex;

        separateArg = 0;
        argUsed = 0;

        if (argv[argIndex][2] == '\0') {
            arg = argv[argIndex+1];
            separateArg = 1;
        } else
            arg = argv[argIndex]+2;

        switch (argv[argIndex][1]) {
            /*
             * when option has an argument, do this
             *
             *     examples are -m4096 or -m 4096
             *
             *     case 'm':
             *         MemorySize = atol(arg);
             *         argUsed = 1;
             *         break;
             *
             *
             * when option does not have an argument, do this
             *
             *     example is -a
             *
             *     case 'a':
             *         PrintActions = 1;
             *         break;
             */
            case 'd':
                Order = 1;
                break;
            case 'v':
                Desc = 1;
                break;
            default:
                Fatal("option %s not understood\n",argv[argIndex]);
            }

        if (separateArg && argUsed)
            ++argIndex;

        ++argIndex;
        }

    return argIndex;
}

void buildHeap(Heap *h, Queue *q, Stack *s) {
    FILE *fp;
    fp = fopen("integers2", "r");
    int temp;
    while (fscanf(fp, "%d", &temp) > 0) {
        insert(h, q, s, temp);
    }

    fclose(fp);
}

void sort(Heap *h, Stack *s) {
    //printLevelOrder(s->tailRoot->treeNode);
    //s->tailRoot->treeNode->value = s->top->treeNode->value;
    printf("%d\n", h->root->value);
    h->root->value = s->top->treeNode->value;
    pop(s);
    //checkStack(s);
    //printf("\n");
    while (s->top != NULL) {
        siftDown(h);
        //printLevelOrder(s->tailRoot->treeNode);
        //checkStack(s);
        if (h->root == NULL) {
            printf("ERROR!\n");
        }
        printf("%d\n", h->root->value);
        h->root->value = s->top->treeNode->value;
        pop(s);
        //printf("\n");
    }
}

/* Function to print level order traversal a tree*/
void printLevelOrder(TreeNode* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i);
}

/* Print nodes at a given level */
void printGivenLevel(TreeNode* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->value);
    else if (level > 1)
    {
        printGivenLevel(root->LC, level-1);
        printGivenLevel(root->RC, level-1);
    }
}

/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(TreeNode* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->LC);
        int rheight = height(node->RC);

        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}
