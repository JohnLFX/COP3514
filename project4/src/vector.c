/**
 * COP3514 Project 4
 * This program multiplies two vectors together
 * and also calculates the complement of them.
 *
 * @author John Cameron (jcameron2)
 */
#include <stdio.h>

void multi_vec(int *v1, int *v2, int *v3, int n);

int comp_vec(int *v1, int *v2, int n);

int main(void) {

    int vectorLength;

    //ask the user to enter the length of the vectors
    printf("Enter the length of the vectors:\n");
    scanf("%d", &vectorLength);

    //declare two arrays with the length

    int v1[vectorLength];
    int v2[vectorLength];

    //read in the values for two vectors

    int *p;

    printf("Enter the first vector:\n");

    for (p = v1; p < v1 + vectorLength; p++)
        scanf("%d", p);

    printf("Enter the second vector:\n");

    for (p = v2; p < v2 + vectorLength; p++)
        scanf("%d", p);

    //call the two functions to compute the multiplication and comparison of them
    //The main function should display the result.

    int v3[vectorLength];

    multi_vec(v1, v2, v3, vectorLength);

    printf("The multiplication of the vectors is: ");

    for (p = v3; p < v3 + vectorLength; p++)
        printf("%d ", *p);

    printf("\n");

    //Function returns 1 if true, else 0 if false
    if (comp_vec(v1, v2, vectorLength)) {
        printf("The vectors are the same.\n");
    } else {
        printf("The vectors are not the same.\n");
    }

    return 0;
}

/**
 * The multi_vec function multiplies vectors v1 and v2
 * and stores the result in v3. n is the length of the vectors.
 *
 * @param v1 Vector 1
 * @param v2 Vector 2
 * @param v3 Resultant vector
 * @param n Length of all the vectors
 */
void multi_vec(int *v1, int *v2, int *v3, int n) {

    // Two vectors are multiplied on an entry-by-entry basis
    // e.g. (1, 2, 3) * (4, 5, 6) = (4, 10, 18).

    /*
     * The functions should use pointer arithmetic (instead of array subscripting).
     * In other words, eliminate the loop index variables
     * and all use of the [] operator in the functions.
     */

    int *p;

    for (p = v1; p < v1 + n; p++)
        *(v3++) = (*p * *(v2++));

    /*for(i = 0; i < n; i++)
        v3[i] = (v1[i] * v2[i]);*/

}

/**
 * The comp_vec function compares v1 and v2, return 1 if vectors v1 and v2 are equal
 * (their corresponding components are equal), and 0 otherwise. n is the length of the vectors.
 *
 * @param v1 Vector 1
 * @param v2 Vector 2
 * @param n Length of the vectors
 * @return Returns 1 if vectors are equal, otherwise 0
 */
int comp_vec(int *v1, int *v2, int n) {

    /*
     * The functions should use pointer arithmetic (instead of array subscripting).
     * In other words, eliminate the loop index variables
     * and all use of the [] operator in the functions.
     */

    int *p;

    for (p = v1; p < v1 + n; p++)
        if (*p != *v2++)
            return 0;

    /*for(i = 0; i < n; i++)
        if(v1[i] != v2[i])
            return 0;*/

    return 1;
}