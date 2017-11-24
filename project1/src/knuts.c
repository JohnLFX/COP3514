/**
 * COP3514 Project 1
 * This program converts different currencies found in the Harry Potter novels.
 *
 * @author John Cameron (jcameron2)
 */
#include <stdio.h>

//Define the knuts value for each galleon and sickle.
//There are 29 knuts in one sickle and 17 sickles in one galleon.
#define GALLEON_KNUTS_VALUE 493
#define SICKLE_KNUTS_VALUE 29

int main(void) {

    //Prompt and read input for the amount of knuts
    printf("Enter the amount of knuts:\n");

    int knutsInput;
    scanf("%d", &knutsInput);

    /* If the amount entered is less than zero or greater than one billion (1000000000),
     * output an error message and abort the program. */
    if (knutsInput < 0 || knutsInput > 1000000000) {
        printf("Invalid amount %d\n", knutsInput);
        printf("Amount must be between 0 and 1000000000, inclusive\n");
        return 0;
    }

    printf("Input: %d\n", knutsInput);

    /* No floating point numbers are allowed according to requirements in the assignment. */

    //Convert knuts to galleons
    int galleonCount = (knutsInput / GALLEON_KNUTS_VALUE);

    //Subtract the amount of knuts that was converted
    knutsInput -= (galleonCount * GALLEON_KNUTS_VALUE);

    //Convert the remaining knuts to sickles
    int sickleCount = (knutsInput / SICKLE_KNUTS_VALUE);

    //Determine the remaining number of knuts by subtracting the amount that was converted.
    knutsInput -= (sickleCount * SICKLE_KNUTS_VALUE);

    //Print the results
    printf("Galleons: %d\n", galleonCount);
    printf("Sickles: %d\n", sickleCount);
    printf("Knuts: %d\n", knutsInput);

    return 0;

}