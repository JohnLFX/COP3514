/**
 * COP3514 Project 3
 * This program reads a set of numbers from user input and
 * stores them in an array represented with 0s and 1s. It
 * then calculates the difference of set A and B, complement
 * of set A, and complement of set B.
 *
 * @author John Cameron (jcameron2)
 */
#include <stdio.h>

//Define functions
void promptArray(int array[], char name);

void printComplement(int array[], char name);

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

    int i;

    for (i = 0; i < ARRAY_SIZE; i++) {

        //If the element is present in A (arrayA[i] == 1) but not in B, print out the current index (number)
        if (arrayA[i] == 1 && arrayB[i] == 0) {

            printf("%d ", i);

        }

    }

    printf("\n");

    //Print the complement of both array A and B
    printComplement(arrayA, 'A');
    printComplement(arrayB, 'B');

    return 0;
}

void promptArray(int array[], char name) {

    printf("Please enter the number of elements in set %c:\n", name);

    int elements;
    scanf("%d", &elements);

    printf("Enter the numbers in set %c:\n", name);

    int i;

    /*
     * Read each number from the console and use the
     * number as the index in the array to set it to 1.
     * Input is restricted from 0-9
     */
    for (i = 0; i < elements; i++) {

        int number;
        scanf("%d", &number);

        array[number] = 1;

    }

}

void printComplement(int array[], char name) {

    printf("The complement of set %c is: ", name);

    int i;

    /*
     * Loop through the entire array. If the element in
     * the array is 0, then the number is not present.
     */
    for (i = 0; i < ARRAY_SIZE; i++) {

        if (array[i] == 0) {

            printf("%d ", i);

        }

    }

    printf("\n");

}