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

/* options */
int Order = 0;      /* option -d      */
int Special = 0;    /* option -s      */
int Number = 0;     /* option -n XXXX */
char* Name = 0;     /* option -N YYYY */

int ProcessOptions(int,char **);
void Fatal(char *,...);

int main(int argc,char **argv) {
    int argIndex;

    argIndex = ProcessOptions(argc,argv);

    printf("Sorting in %s order\n", Order == 0? "increasing" : "decreasing");
    printf("Special is %s\n", Special == 0? "false" : "true");
    printf("Number is %d\n", Number);
    printf("Name is %s\n", Name == 0? "missing" : Name);

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
                Number = atoi(arg);
                argUsed = 1;
                break;
            case 's':
                Special = 1;
                break;
            case 'N':
                Name = strdup(arg);
                argUsed = 1;
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

// #include <stdio.h>
// #include <stdlib.h>
//
// void readNums(int **, int *, int);
//
// int main(int argc, char const *argv[]) {
//     int *nums, numsSize;
//     int capacity = 100;
//
//     nums = malloc(sizeof(int) * capacity);
//     readNums(&nums, &numsSize, capacity);
//
//     //Testing editing code through atom
//
//     for (int i = 0; i < numsSize; i++) {
//         printf("%d\n", nums[i]);
//     }
//
//     return 0;
// }
//
// void readNums(int **nums, int *numsSize, int capacity) {
//     FILE *fp;
//     fp = fopen("integers1", "r");
//
//     int sampleSize = 0;
//     while (!feof(fp)) {
//         int temp;
//         nums[sampleSize] = malloc(sizeof(nums));
//         fscanf(fp, "%d", &temp);
//         //printf("%D\n", temp);
//         *nums[sampleSize] = temp;
//         ++sampleSize;
//         printf("capacity: %d\n", capacity);
//         printf("sampleSize: %d\n", sampleSize);
//         if (sampleSize >= capacity) {
//             capacity *= 2;
//             // Remember to use sizeof(int) you idiot...
//             *nums = realloc(*nums, sizeof(int) * capacity);
//             if(*nums == NULL) {
//                 printf("That's not good...\n");
//             }
//         }
//     }
//
//     *numsSize = sampleSize - 1;
//     fclose(fp);
// }
