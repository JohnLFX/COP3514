/**
 * COP3514 Project 5
 * This program accepts command-line arguments of 10 numbers,
 * which are assumed to be integers, and finds the median or the average of them.
 *
 * @author John Cameron (jcameron2)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN_NUM_COUNT 10

void read_numbers(int *numbers, char *argv[], int argc, int offset);

int sum_array(int *numbers, int size);

void selection_sort(int a[], int n);

int main(int argc, char *argv[]) {

    if (argc != (2 + IN_NUM_COUNT)) {
        printf("Error: Invalid number of arguments.\n");
        printf("Usage: ./a.out –option (a or m) followed by %d integers\n", IN_NUM_COUNT);
        return 1;
    }

    //Use the strcmp function to process the first command line argument
    if (strcmp(argv[1], "-a") == 0) {

        int input[IN_NUM_COUNT];
        //Skip the first two arguments for the offset parameter (program name and mode)
        read_numbers(input, argv, argc, 2);

        //Calculate the average
        double average = (sum_array(input, IN_NUM_COUNT) / ((double) IN_NUM_COUNT));

        printf("Average: %f\n", average);

    } else if (strcmp(argv[1], "-m") == 0) {

        int input[IN_NUM_COUNT];
        read_numbers(input, argv, argc, 2);

        //Use the selection_sort function provided to sort the array
        selection_sort(input, IN_NUM_COUNT);

        //The median is the number that is halfway into the array: a[n/2],
        // where n is the number of the elements in array a.
        int median = input[IN_NUM_COUNT / 2];

        printf("Median: %d\n", median);

    } else {
        printf("Error: Invalid mode \"%s\"\n", argv[1]);
        printf("Usage: ./a.out –option (a or m) followed by %d integers\n", IN_NUM_COUNT);
        return 1;
    }

    return 0;
}

/**
 * Converts each string in the char array to an int
 * @param numbers The array of numbers to store the result in
 * @param argv The input character array
 * @param offset The starting position of the numbers in the array
 */
void read_numbers(int *numbers, char *argv[], int argc, int offset) {
    char **p;

    for (p = (argv += offset); p < argv + (argc - offset); p++)
        //Use atoi function in <stdlib.h> to convert a string to integer form.
        *numbers++ = atoi(*p);
}

/**
 * Returns a sum of all of the numbers in an array
 * @param numbers The array of numbers
 * @param size Size of the array
 * @return The sum of the array
 */
int sum_array(int *numbers, int size) {
    int sum = 0;
    int *p;

    for (p = numbers; p < numbers + size; p++)
        sum += *p;

    return sum;
}

/**
 * Sorts an integer array in ascending order
 * @param a The array
 * @param n Size of array
 */
void selection_sort(int a[], int n) {
    int i, largest = 0, temp;
    if (n == 1)
        return;
    for (i = 1; i < n; i++)
        if (a[i] > a[largest])
            largest = i;
    if (largest < n - 1) {
        temp = a[n - 1];
        a[n - 1] = a[largest];
        a[largest] = temp;
    }
    selection_sort(a, n - 1);
}