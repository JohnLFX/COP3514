/**
 * COP3514 Project 7
 * This program reads a list of medicine from a file,
 * sorts the list, and prints out the sorted list in a new file.
 *
 * @author John Cameron (jcameron2)
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_NAME_SIZE 100
#define MEDICINE_NAME_SIZE 100
#define MEDICINES_MAX 100
#define MONTHS_SOLD 6

int read_line(char *str, int n);

struct Medicine {
    char name[MEDICINE_NAME_SIZE];
    int unitsInStock;
    int unitsSold[MONTHS_SOLD];
    int totalUnitsSold;
};

void selection_sort(struct Medicine meds[], int n);

int main(void) {

    printf("Enter the file name: ");

    char inputFileName[FILE_NAME_SIZE];

    read_line(inputFileName, FILE_NAME_SIZE);

    FILE *readFile = fopen(inputFileName, "r");

    if (readFile == NULL) {//Null pointer
        printf("File %s was not opened successfully.\n", inputFileName);
        return 1;
    }

    struct Medicine medicines[MEDICINES_MAX];
    int lineCount = 0;

    //Use fscanf to read the data in the file and stop once it reaches the end
    while (EOF != fscanf(readFile, "%s %d", medicines[lineCount].name, &medicines[lineCount].unitsInStock)) {

        int i;
        for (i = 0; i < MONTHS_SOLD; i++)
            if (EOF == fscanf(readFile, "%d", &medicines[lineCount].unitsSold[i]))
                break;

        //Calculate the total amount sold by adding up what sold in each month
        for (i = 0; i < MONTHS_SOLD; i++)
            medicines[lineCount].totalUnitsSold += medicines[lineCount].unitsSold[i];

        //Bounds checking
        if (++lineCount >= MEDICINES_MAX)
            break;

    }

    fclose(readFile);

    //Increase bounds to allow for appended extension
    char outputFileName[FILE_NAME_SIZE + 4];

    // The output file name should be the same name as the
    // input file but with an added extension of .ang
    strcpy(outputFileName, inputFileName);
    strcat(outputFileName, ".srt");

    FILE *writeFile = fopen(outputFileName, "w");
    if (writeFile == NULL) {
        printf("File %s was not opened successfully.\n", outputFileName);
        return 1;
    }

    //Sort the data
    selection_sort(medicines, lineCount);

    fprintf(writeFile, "#\tName\t\tInStock\tJan\tFeb\tMar\tApr\tMay\tJun\tTotal\n");

    //Print the sorted data
    int i;
    for (i = 0; i < lineCount; i++) {
        fprintf(writeFile, "%d\t%-15s %d\t",
                (i + 1), medicines[i].name, medicines[i].unitsInStock
        );

        int j;
        for (j = 0; j < MONTHS_SOLD; j++)
            fprintf(writeFile, "%d\t", medicines[i].unitsSold[j]);

        fprintf(writeFile, "%d\n", medicines[i].totalUnitsSold);
    }

    fclose(writeFile);

    printf("sorted medicine written to file: %s\n", outputFileName);

    return 0;
}

/**
 * Sorts an array of Medicine structures by the total units sold in ascending order
 * @param meds The array
 * @param n Size of array
 */
void selection_sort(struct Medicine meds[], int n) {

    int i, largest = 0;
    struct Medicine temp;

    if (n == 1)
        return;

    for (i = 1; i < n; i++)
        //Sort by the total amount of units sold
        if (meds[i].totalUnitsSold > meds[largest].totalUnitsSold)
            largest = i;

    if (largest < n - 1) {
        temp = meds[n - 1];
        meds[n - 1] = meds[largest];
        meds[largest] = temp;
    }

    selection_sort(meds, n - 1);
}

/**
 * Reads a line from the console using getchar()
 * @param str The string to store the input in
 * @param n The length of the string
 * @return The number of characters read
 */
int read_line(char *str, int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n') {
        if (i++ < n)
            *str++ = ch;
    }
    *str = '\0';   /* terminates string */
    return i;        /* number of characters stored */
}