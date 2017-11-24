/**
 * COP3514 Project 4
 * This program reads a set of numbers from user input and
 * stores them in an array represented with 0s and 1s. It
 * then calculates the difference of set A and B, complement
 * of set A, and complement of set B.
 *
 * @author John Cameron (jcameron2)
 */
#include <stdio.h>

//Define functions
void promptArray(int *array, char name);

void set_difference(int *a, int *b, int n, int *difference);

void set_complement(int *a, int n, int *complement);

//Define the array size constant
#define ARRAY_SIZE 10

int main(void) {

    //Initialize array A and B
    int arrayA[ARRAY_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int arrayB[ARRAY_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    //Prompt the user to enter the numbers each array will represent
    promptArray(arrayA, 'A');
    promptArray(arrayB, 'B');

    printf("The difference of set A and B is: ");

    int difference[ARRAY_SIZE];

    set_difference(arrayA, arrayB, ARRAY_SIZE, difference);

    int i;

    for (i = 0; i < ARRAY_SIZE; i++)
        if (difference[i] == 1)
            printf("%d ", i);

    printf("\n");

    //Determine the complement of both arrays
    //and print the result from the main method

    //Print complement for array A
    int complement[ARRAY_SIZE];

    set_complement(arrayA, ARRAY_SIZE, complement);

    printf("The complement of set A is: ");

    for (i = 0; i < ARRAY_SIZE; i++)
        if (complement[i] == 1)
            printf("%d ", i);

    //Print complement for array B
    set_complement(arrayB, ARRAY_SIZE, complement);

    printf("\nThe complement of set B is: ");

    for (i = 0; i < ARRAY_SIZE; i++)
        if (complement[i] == 1)
            printf("%d ", i);

    printf("\n");

    return 0;
}

/*
 * Both functions should use pointer arithmetic –not subscripting– to visit array elements.
 * In other words, eliminate the loop index variables and all use of the [] operator in the function.
 */

/**
 * set_difference function: it should find the difference of the set represented by array a
 * and set represented by array band store the result in the set represented by array difference.
 *
 * @param a Array A
 * @param b Array B
 * @param n The size of all the arrays
 * @param difference The array to store the difference result in
 */
void set_difference(int *a, int *b, int n, int *difference) {

    int *p;

    for (p = a; p < a + n; p++) {

        if (*p == 1 && *b == 0)
            *difference = 1;
        else
            *difference = 0;

        //Increment by 1 every loop
        b++;
        difference++;

    }

}

/**
 * set_complement function: it should find the complement of the set represented by array a
 * store the result in the set represented by array complement.
 *
 * @param a The Array
 * @param n Size of Array
 * @param complement The array to store the complement result in
 */
void set_complement(int *a, int n, int *complement) {

    int *p;

    for (p = a; p < a + n; p++) {

        if (*p == 0)
            *complement = 1;
        else
            *complement = 0;

        complement++;

    }

}

/**
 * Prompts the user to enter input data for the given array
 *
 * @param array The array
 * @param name The name of the Array
 */
void promptArray(int *array, char name) {

    printf("Please enter the number of elements in set %c:\n", name);

    int elements;
    scanf("%d", &elements);

    printf("Enter the numbers in set %c:\n", name);

    int *p;

    /*
     * Read each number from the console and use the
     * number as the index in the array to set it to 1.
     * Input is restricted from 0-9
     */
    for (p = array; p < array + elements; p++) {

        int number;
        scanf("%d", &number);

        *(array + number) = 1;

    }

}