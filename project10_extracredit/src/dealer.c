/**
 * COP3514 Project 10 Extra Credit
 * This program is a modified version from project 10.
 * In this program, the LinkedList maintains order
 * by considering many other car structure variables.
 *
 * @author John Cameron (jcameron2)
 */
#include <stdio.h>
#include "car.h"

int main(void) {

    char code;

    struct car *car_list = NULL;
    printf("Operation Code: a for appending to the list, d for deleting from the list, "
                   "f for finding a car, p for printing the list; q for quit.\n");
    for (;;) {
        printf("Enter operation code:\n");
        scanf(" %c", &code);
        while (getchar() != '\n');   /* skips to end of line */
        switch (code) {
            case 'a':
                car_list = append_to_list(car_list);
                break;
            case 'd':
                car_list = delete_from_list(car_list);
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

}