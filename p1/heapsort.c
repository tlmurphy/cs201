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
void printDescription();
void printTable();
void buildTree(Heap *h, Queue *q, Stack *s, char *);
void buildHeap(Heap *h, Stack *s);
void sort(Heap *h, Stack *s);
void printLevelOrder(TreeNode* root);
void printGivenLevel(TreeNode* root, int level);
int height(TreeNode* node);

int main(int argc,char **argv) {
    clock_t t;
    t = clock();

    ProcessOptions(argc,argv);

    if (Desc == 1 ) {
        printDescription();
        printTable();
        return 0;
    }

    Queue *q;
    Stack *s;
    Heap *h;

    q = newQueue();
    s = newStack();
    h = newHeap(Order);

    if (Order == 0) h->cmp = lt;
    else h->cmp = gt;

    char *file;

    // Check for input file and set input file string
    // based on arguments.
    if (argc == 1) {
        printf("INPUT FILE NOT FOUND...EXITING\n");
        exit(-1);
    } else if (argc == 2) {
        file = argv[1];
    } else
        file = argv[2];

    buildTree(h, q, s, file);
    buildHeap(h, s);

    sort(h, s);
    free(q);
    free(s);
    free(h);

    t = clock() - t;
    // double time_taken = ((double) t)/CLOCKS_PER_SEC;
    // printf("%f seconds to execute...\n", time_taken);
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

// only -oXXX  or -o XXX options
// Lusth's function to handle the -d and -v arguments
int ProcessOptions(int argc, char **argv) {
    int argIndex;
    int argUsed;
    int separateArg;

    argIndex = 1;

    while (argIndex < argc && *argv[argIndex] == '-') {
        /* check if stdin, represented by "-" is an argument */
        /* if so, the end of options has been reached */
        if (argv[argIndex][1] == '\0') return argIndex;

        separateArg = 0;
        argUsed = 0;

        switch (argv[argIndex][1]) {
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

void printDescription() {
    printf("AUTHOR: Trevor Murphy\n");
    printf("Read numbers from file (n)\n");
    printf("Convert tree to heap (n)\n");
    printf("Sort (n log n)\n");
    printf("TOTAL TIME: n + n + n log n = n log n\n");
}

void printTable() {
    printf("\n");
    printf("TIME CALCULATED WHEN OUTPUT IS PRINTED TO CONSOLE...\n");
    printf("\nINPUT SIZE VS TIME\n");
    printf("------------------\n");
    printf("n            time   \n");
    printf("%-13.1d%lf s\n", 1,        0.000070);
    printf("%-13.1d%lf s\n", 10,       0.000075);
    printf("%-13.1d%lf s\n", 100,      0.000155);
    printf("%-13.1d%lf s\n", 1000,     0.001020);
    printf("%-13.1d%lf s\n", 10000,    0.012000);
    printf("%-13.1d%lf s\n", 100000,   0.135000);
    printf("%-13.1d%lf s\n", 1000000,  1.780000);
    printf("%-13.1d%lf s\n", 10000000, 22.00000);

}

void buildTree(Heap *h, Queue *q, Stack *s, char *f) {
    FILE *fp;
    fp = fopen(f, "r");
    int temp = 0; // Just in case
    while (fscanf(fp, "%d", &temp) > 0)
        insert(h, q, s, temp);
    fclose(fp);
}

void buildHeap(Heap *h, Stack *s) {
    Node *iter = s->top;
    while (iter != NULL && iter->next != NULL) {
        siftDown(h, iter->treeNode->parent);
        if (iter->next->next == NULL) // If left child of root
            iter = iter->next;
        else
            iter = iter->next->next; // Skip siblings
    }
}

void sort(Heap *h, Stack *s) {
    printf("%d ", h->root->value);
    h->root->value = s->top->treeNode->value;
    pop(s);
    while (s->top != NULL) {
        siftDown(h, h->root);
        printf("%d ", h->root->value);
        h->root->value = s->top->treeNode->value;
        pop(s);
    }
    printf("\n");
}
