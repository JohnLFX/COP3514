/**
 * COP3514 Project 3
 * This program converts different currencies found in the Harry Potter novels
 * by using a function with pointers as its parameters.
 *
 * @author John Cameron (jcameron2)
 */
#include <stdio.h>

//Define functions
void convert(int total_knuts, int *galleons, int *sickles, int *knuts);

//Define the knuts value for each galleon and sickle
//There are 29 knuts in one sickle and 17 sickles in one galleon
#define GALLEON_KNUTS_VALUE 493
#define SICKLE_KNUTS_VALUE 29

int main(void) {

    //Prompt and read input for the amount of knuts
    printf("Enter the amount of knuts:\n");

    int knutsInput;
    scanf("%d", &knutsInput);

    /* If the amount entered is less than zero or greater than one billion (1000000000),
     * output an error message and abort the program */
    if (knutsInput < 0 || knutsInput > 1000000000) {
        printf("Invalid amount %d\n", knutsInput);
        printf("Amount must be between 0 and 1000000000, inclusive\n");
        return 0;
    }

    printf("Input: %d\n", knutsInput);

    /* No floating point numbers are allowed according to requirements in the assignment */

    int galleons, sickles, knuts;

    convert(knutsInput, &galleons, &sickles, &knuts);

    //Print the results
    printf("Galleons: %d\n", galleons);
    printf("Sickles: %d\n", sickles);
    printf("Knuts: %d\n", knuts);

    return 0;

}

void convert(int total_knuts, int *galleons, int *sickles, int *knuts) {

    //Convert knuts to galleons
    *galleons = (total_knuts / GALLEON_KNUTS_VALUE);

    //Set total_knuts to the remainder of the previous calculation for the next one
    total_knuts %= GALLEON_KNUTS_VALUE;

    //Convert the remaining knuts to sickles
    *sickles = (total_knuts / SICKLE_KNUTS_VALUE);

    //Set the remaining knuts to the remainder of previous calculation
    *knuts = (total_knuts % SICKLE_KNUTS_VALUE);

}