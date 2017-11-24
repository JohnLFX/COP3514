/**
 * COP3514 Project 10
 * This program prints its command arguments in alphabetical order.
 *
 * @author John Cameron (jcameron2)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_strings(const void *p, const void *q);

int main(int argc, char *argv[]) {

    // Set the initial position in the array to skip
    // the first element. The first element is the executable path
    // of the program, which is something that should not be included.

    // Because of the first element being skipped, the arguments count (argc)
    // should be decreased by one to maintain array bounds.
    qsort(++argv, --argc, sizeof(char *), compare_strings);

    //Use subscripts in a for-loop to access each argument
    int i;
    for (i = 0; i < argc; i++)
        printf("%s ", argv[i]);

    printf("\n");

    return 0;
}

/**
 * A comparator used for string arrays
 * This function was designed for qsort
 * @param p Pointer to first value
 * @param q Pointer to second value
 * @return The result of strcmp(p, q)
 */
int compare_strings(const void *p, const void *q) {
    return strcmp(*(char **) p, *(char **) q);
}