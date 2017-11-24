/**
 * COP3514 Project 9
 * This program is exactly like the one in project 8
 * but split into multiple files and linked together as necessary.
 * This file contains the headers for the car functions.
 *
 * @author John Cameron (jcameron2)
 */
#ifndef CAR_H
#define CAR_H
#define LEN 30

//Car structure
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

/**
 * Appends an element to the end of a LinkedList
 * @param list The LinkedList to append the element to
 * @return A pointer to the LinkedList
 */
struct car *append_to_list(struct car *list);

/**
 * Prints each element in the list which matches a certain make and model
 * This function will prompt the user to enter the make and model
 * @param list The LinkedList to search in
 */
void find_car(struct car *list);

/**
 * Prints each element in the list
 * @param list The LinkedList
 */
void printList(struct car *list);

/**
 * Clears the LinkedList by freeing the memory allocated
 * @param list The LinkedList to clear
 */
void clearList(struct car *list);

#endif //CAR_H