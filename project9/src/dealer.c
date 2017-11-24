/**
 * COP3514 Project 9
 * This program is exactly like the one in project 8
 * but split into multiple files and linked together as necessary.
 * This file contains the main method for the dealer program.
 *
 * @author John Cameron (jcameron2)
 */
#include <stdio.h>
#include "car.h"

int main(void) {

    char code;

    struct car *car_list = NULL;
    printf("Operation Code: a for appending to the list, f for finding a car"
                   ", p for printing the list; q for quit.\n");
    for (;;) {
        printf("Enter operation code:\n");
        scanf(" %c", &code);
        while (getchar() != '\n');   /* skips to end of line */
        switch (code) {
            case 'a':
                car_list = append_to_list(car_list);
                break;
            case 'f':
                find_car(car_list);
                break;
            case 'p':
                printList(car_list);
                break;
            case 'q':
                clearList(car_list);
                return 0;
            default:
                printf("Illegal code\n");
        }
        printf("\n");
    }

    return 0;

}