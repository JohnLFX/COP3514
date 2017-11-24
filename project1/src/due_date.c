/**
 * COP3514 Project 1
 * This program determines when an assignment should be due based on
 * the initial day of week integer value and the number of days given to complete it.
 * Additionally, it will automatically add extra days in order to make sure that
 * the due date is not on anyone's holy day (Friday, Saturday, or Sunday)
 *
 * @author John Cameron (jcameron2)
 */
#include <stdio.h>

int main(void) {

    //Declare input variables
    int dayForToday;
    int numberOfDays;

    //Read the input
    printf("Enter the day for today (0 for Sunday, 1 for Monday, ect):\n");

    scanf("%d", &dayForToday);

    printf("Enter the number of days to do the work:\n");

    scanf("%d", &numberOfDays);

    /* If the entered day for today is not in the range of 0 to 6,
     *      display an error message and abort the program. */

    //Check to make sure that the entered day is valid
    if (dayForToday < 0 || dayForToday > 6) {
        printf("Invalid input. The day should be in the range of 0 to 6.\n");
        return 0;
    }

    /*
     * Display the corrected value of the number of days and the day of the week the work is due.
     * For example, if today is Thursday, and the number of days D is 8,
     * then the due date falls on Friday, then 3 days will be added to reach the following Monday.
     * So the corrected value of D is 11.
     * */

    /*
     * This algorithm calculates what day of the week it will be given a set number of days.
     * There are two variables that clone the input variables. Only the cloned variables are modified.
     * While there is a day to count up, count up by 1. If the number is over 6 (Saturday),
     * reset it back to 0 to represent Sunday.
     * The loop will end when there are no more days to count up
     */
    int dayOfWeekDue = dayForToday;
    int daysCounter = numberOfDays;

    while (daysCounter > 0) {
        dayOfWeekDue++;

        if (dayOfWeekDue > 6)
            dayOfWeekDue = 0;

        daysCounter--;
    }

    /*
     * Use a switch statement for calculating the number of days based on the week day.
     * If the day of week is not on a holy day, output the name of the represented day of week and number of days.
     * Else, output the due date as Monday and add the proper amount of skipped days.
     * The variable used here represents the day of the week of when it is due.
     * */
    switch (dayOfWeekDue) {

        case 0:
            printf("The work is due on Monday. The number of days until its due is %d.\n", (numberOfDays + 1));
            break;
        case 1:
            printf("The work is due on Monday. The number of days until its due is %d.\n", numberOfDays);
            break;
        case 2:
            printf("The work is due on Tuesday. The number of days until its due is %d.\n", numberOfDays);
            break;
        case 3:
            printf("The work is due on Wednesday. The number of days until its due is %d.\n", numberOfDays);
            break;
        case 4:
            printf("The work is due on Thursday. The number of days until its due is %d.\n", numberOfDays);
            break;
        case 5:
            printf("The work is due on Monday. The number of days until its due is %d.\n", (numberOfDays + 3));
            break;
        case 6:
            printf("The work is due on Monday. The number of days until its due is %d.\n", (numberOfDays + 2));
            break;
    }

    //Successful exit
    return 0;

}