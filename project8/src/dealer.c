/**
 * COP3514 Project 8
 * This program manages a car database by using a LinkedList
 *
 * @author John Cameron (jcameron2)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN 30

struct car {
    char make[LEN + 1];
    char model[LEN + 1];
    char color[LEN + 1];
    int year;
    int city_mpg;
    int highway_mpg;
    int quantity;
    struct car *next;
};

struct car *append_to_list(struct car *list);

void find_car(struct car *list);

void printList(struct car *list);

void clearList(struct car *list);

int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
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
}

/**
 * Appends an element to the end of a LinkedList
 * @param list The LinkedList to append the element to
 * @return A pointer to the LinkedList
 */
struct car *append_to_list(struct car *list) {
    struct car *cur, *new_node, *prev = NULL;

    new_node = malloc(sizeof(struct car));
    if (new_node == NULL) {
        printf("Database is full; can't add more cars.\n");
        return list;
    }

    printf("Enter make:\n");
    read_line(new_node->make, LEN);

    printf("Enter model:\n");
    read_line(new_node->model, LEN);

    printf("Enter color:\n");
    read_line(new_node->color, LEN);

    printf("Enter year:\n");
    scanf("%d", &new_node->year);

    printf("Enter city mpg:\n");
    scanf("%d", &new_node->city_mpg);

    printf("Enter highway mpg:\n");
    scanf("%d", &new_node->highway_mpg);

    printf("Enter quantity:\n");
    scanf("%d", &new_node->quantity);

    /*
     * Check whether the car has already existed by
     * make, model, color, and manufacture year.
     * If so, print an error message and exit
     */
    for (cur = list; cur != NULL; prev = cur, cur = cur->next)
        if (strcmp(cur->make, new_node->make) == 0 && strcmp(cur->model, new_node->model) == 0
            && strcmp(cur->color, new_node->color) == 0 && cur->year == new_node->year) {
            printf("car already exists.\n");
            // Not adding any element to the list
            // Therefore, free the allocated memory
            free(new_node);
            return list;
        }

    if (cur == NULL && prev != NULL) {

        // The list is not empty.
        // Append the next node to the LinkedList by
        // setting the next car pointer of the last element
        // to the car structure being created now
        prev->next = new_node;

        //Return the pointer to the LinkedList
        return list;

    } else {

        // If the list is empty, the function should
        // return the pointer to the newly created car
        return new_node;

    }

}

/**
 * Prints each element in the list which matches a certain make and model
 * This function will prompt the user to enter the make and model
 * @param list The LinkedList to search in
 */
void find_car(struct car *list) {

    char make[LEN + 1];
    char model[LEN + 1];

    printf("Enter make:\n");
    read_line(make, LEN);

    printf("Enter model:\n");
    read_line(model, LEN);

    struct car *p;
    int foundModel = 0;

    for (p = list; p != NULL; p = p->next)
        if (strcmp(p->make, make) == 0 && strcmp(p->model, model) == 0) {
            printf("color: %s, year: %d, city mpg: %d, highway mpg: %d, quantity: %d\n",
                   p->color, p->year, p->city_mpg, p->highway_mpg, p->quantity);
            foundModel = 1;
        }

    if (!foundModel)
        printf("no cars were found with that make and model.\n");

}

/**
 * Prints each element in the list
 * @param list The LinkedList
 */
void printList(struct car *list) {
    struct car *p;

    printf("Make\tModel\t\tYear\tColor\tCity MPG\tHighway MPG\tQuantity\n");

    for (p = list; p != NULL; p = p->next)
        printf("%s\t%-10s\t%d\t%s\t%d\t\t%d\t\t%d\n",
               p->make, p->model, p->year, p->color, p->city_mpg, p->highway_mpg, p->quantity);
}

/**
 * Clears the LinkedList by freeing the memory allocated
 * @param list The LinkedList to clear
 */
void clearList(struct car *list) {
    struct car *p;
    while (list != NULL) {
        p = list;
        list = list->next;
        if (p != NULL)
            free(p);
    }
}

/**
 * Reads a line from the console using getchar() while ignoring any whitespace in the beginning
 * @param str The string to store the input in
 * @param n The length of the string
 * @return The number of characters read
 */
int read_line(char str[], int n) {
    int ch, i = 0;

    while (isspace(ch = getchar()));
    str[i++] = ch;
    while ((ch = getchar()) != '\n') {
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}