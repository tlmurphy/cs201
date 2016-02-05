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

#include "Queue.h"
#include "Stack.h"
#include "Heap.h"

/* options */
int Order = 0;      /* option -d      */
int Desc = 0;       /* option -v      */

int ProcessOptions(int,char **);
void Fatal(char *,...);
void buildHeap(Heap *h, Queue *q, Stack *s);

int main(int argc,char **argv) {
    int argIndex;

    argIndex = ProcessOptions(argc,argv);

    printf("Sorting in %s order\n", Order == 0? "increasing" : "decreasing");
    printf("Dash v is %s\n", Desc == 0? "not enabled" : "enabled");

    Queue *q;
    Stack *s;
    Heap *h;
    q = newQueue();
    s = newStack();
    h = newHeap();
    buildHeap(h, q, s);
    printStack(s);
    printf("%d\n", pop(s)->value);
    printf("%d\n", dequeue(q)->value);
    free(q);
    free(s);
    free(h);

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
    fp = fopen("integers1", "r");
    int temp;
    while (fscanf(fp, "%d", &temp) > 0) {
        insert(h, q, s, temp);
        printQueue(q);
    }

    fclose(fp);
}
