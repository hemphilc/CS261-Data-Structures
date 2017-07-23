/* CS261- Assignment 4 - Extra Credit - compare.c*/
/* Name: Corey Hemphill
 * Date: 11/6/2015
 * Solution description: (none)
 */

#include <stdio.h>
#include <assert.h>
#include "animalbst.h"
#include "animalstruct.h"

/*----------------------------------------------------------------------------
 Very similar to the compareTo method in Java or the strcmp function in C. It
 returns an integer to tell you if the left value is greater than, less than, or
 equal to the right value. You are comparing the number variable, letter is not
 used in the comparison.

 if left < right return -1
 if left > right return 1
 if left = right return 0
 */

int compare(TYPE left, TYPE right) {
    assert(left != NULL && right != NULL);
    struct animal *leftPtr = left;
    struct animal *rightPtr = right;
    if(leftPtr->number < rightPtr->number) {
        return -1;
    }
    else if(leftPtr->number > rightPtr->number) {
        return 1;
    }
    return 0;
}

void print_type(TYPE curval) {
    assert(curval != NULL);
    struct animal *currentValue = curval;
    printf("%s\n", currentValue->animalString);
}

