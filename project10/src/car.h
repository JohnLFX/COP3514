/**
 * COP3514 Project 10
 * This program is a modified version from project 9.
 * In this program, the LinkedList maintains order
 * and includes an option to delete entries from it.
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
 * Deletes an element from the LinkedList.
 * The user is prompted to enter information
 * on what car to delete from the list.
 * @param list The list to modify
 * @return A pointer to the modified LinkedList
 */
struct car *delete_from_list(struct car *list);

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

/**
 * Compares two car structures
 * @param a First car structure
 * @param b Second car structure
 * @return -1 if a is less than b, 1 if a is greater than b, 0 if a is equal to b
 */
int car_cmp(struct car *a, struct car *b);

#endif //CAR_H