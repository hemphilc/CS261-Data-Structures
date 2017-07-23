/* CS261- Assignment 4 - compare1.c*/
/* Name: Corey Hemphill
 * Date: 11/6/2015
 * Solution description: (none)
 */

#include <stdio.h>
#include <assert.h>
#include "bst.h"
#include "structs.h"

/*----------------------------------------------------------------------------
 Very similar to the compareTo method in Java or the strcmp function in C. It
 returns an integer to tell you if the left value is greater than, less than, or
 equal to the right value. You are comparing the number variable, letter is not
 used in the comparison.

 if left < right return -1
 if left > right return 1
 if left = right return 0
 */

/*Define this function, type casting the value of void* to the desired type.
  The current definition of TYPE in bst.h is void*, which means that left and
  right are void pointers. To compare left and right, you should first cast
  left and right to the corresponding pointer type (struct data*), and then
  compare the values pointed by the casted pointers.

  DO NOT compare the addresses pointed by left and right, i.e. "if (left < right)",
  which is really wrong.
 */
int compare(TYPE left, TYPE right) {
    /*FIXME: write this*/
    assert(left != NULL && right != NULL);
    struct data *leftPtr = left;
    struct data *rightPtr = right;
    if(leftPtr->number < rightPtr->number) {
        return -1;
    }
    else if(leftPtr->number > rightPtr->number) {
        return 1;
    }
    return 0;
}

/*Define this function, type casting the value of void * to the desired type*/
void print_type(TYPE curval) {
    /*FIXME: write this*/
    assert(curval != NULL);
    struct data *currentValue = curval;
    printf("%d\n", currentValue->number);
}
