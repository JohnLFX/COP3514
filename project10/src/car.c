/**
 * COP3514 Project 10
 * This program is a modified version from project 9.
 * In this program, the LinkedList maintains order
 * and includes an option to delete entries from it.
 *
 * @author John Cameron (jcameron2)
 */
#include "car.h"
#include "readline.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Appends an element to the end of a LinkedList
 * @param list The LinkedList to append the element to
 * @return A pointer to the LinkedList
 */
struct car *append_to_list(struct car *list) {
    struct car *cur, *new_node, *prev;

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
    for (cur = list, prev = NULL; cur != NULL; prev = cur, cur = cur->next)
        if (strcmp(cur->make, new_node->make) == 0 && strcmp(cur->model, new_node->model) == 0
            && strcmp(cur->color, new_node->color) == 0 && cur->year == new_node->year) {
            printf("car already exists.\n");
            // Not adding anything to the list
            // Therefore, free the memory that was just allocated
            free(new_node);
            return list;
        }

    if (cur == NULL && prev != NULL) {
        //The list is not empty

        // Loop through the LinkedList and find the first node in it that
        // is positioned higher alphabetically than the node being currently added.
        for (cur = list, prev = NULL; cur != NULL; prev = cur, cur = cur->next) {

            // Compare each car structure to determine if the
            // new node should be inserted at this position
            if (car_cmp(new_node, cur) > 0) {

                if (prev != NULL) {

                    // There is a previous node of where the new_node is being inserted to.
                    // Make sure that the previous node is pointing to the new node and that
                    // the new node is pointing to the original value pointed by the previous node
                    prev->next = new_node;
                    new_node->next = cur;
                    return list;

                } else {

                    // There is not a previous node of where the new node is being inserted to.
                    // Therefore, the new node is going to be the first node of the LinkedList.
                    new_node->next = cur;
                    return new_node;

                }

            }

        }

        // Found nothing that is alphabetically higher than the node being inserted
        // Append the new node to the end of the LinkedList
        prev->next = new_node;
        return list;

    } else {

        // If the list is empty, the function should
        // return the pointer to the newly created car
        return new_node;

    }

}

struct car *delete_from_list(struct car *list) {

    char make[LEN + 1];
    char model[LEN + 1];
    char color[LEN + 1];
    int year;

    printf("Enter make:\n");
    read_line(make, LEN);

    printf("Enter model:\n");
    read_line(model, LEN);

    printf("Enter color:\n");
    read_line(color, LEN);

    printf("Enter year:\n");
    scanf("%d", &year);

    struct car *cur, *prev;

    // Find a car structure in the LinkedList that
    // matches the input supplied by the user
    for (cur = list, prev = NULL;
         cur != NULL
         && (strcmp(cur->make, make) != 0 || strcmp(cur->model, model) != 0
             || strcmp(cur->color, color) || cur->year != year);
         prev = cur, cur = cur->next);

    if (cur == NULL) {
        printf("car does not exist\n");
        return list;
    }

    if (prev == NULL)
        // If there isn't a previous node for the current one,
        // then the element to be removed must be the first entry.
        // Simply set the initial element to the next one in the list.
        list = list->next;
    else
        // The cur node is the one that needs to be deleted.
        // Set the next node of the previous node to the next node
        // of the current node (since the current node is being deleted)
        prev->next = cur->next;

    printf("Deleted car make: %s, model: %s, color: %s, year: %d\n", cur->make, cur->model, cur->color, cur->year);

    //Free memory occupied by the node being deleted
    free(cur);
    return list;
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
 * Compares two car structures
 * @param a First car structure
 * @param b Second car structure
 * @return -1 if a is less than b, 1 if a is greater than b, 0 if a is equal to b
 */
int car_cmp(struct car *a, struct car *b) {

    // Compare the make of the two car structures first
    int makeCompare = strcmp(a->make, b->make);

    if (makeCompare > 0) {
        return -1;
    } else {

        // Then compare the model of the two car structures
        return strcmp(b->model, a->model);

    }

}