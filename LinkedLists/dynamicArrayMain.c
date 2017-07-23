/* CS261- Assignment 3 - dynamicArrayMain.c*/
/* Name: Corey Hemphill
 * Date: 10/23/2015
 * Solution description: (none)
 */

#include "dynamicArray.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


/*Function to get number of milliseconds elapsed since program started execution*/
double getMilliseconds() {
    return 1000.0 * clock() / CLOCKS_PER_SEC;
}

int main(/*int argc, char* argv[]*/) {
    DynArr* b;
    int n, i;
    double t1, t2;
    printf("Printing dynamicArrayMain.c...\n");
    for(n = 1000; n < 200000; n = n * 2) { /* outer loop */
        b = createDynArr(n);
        for(i = 0 ; i < n; i++) {
            addDynArr(b, (TYPE)i); /*Add elements*/
        }
        t1 = getMilliseconds(); /*Time before contains()*/
        for(i = 0; i < n; i++) {
//            removeDynArr(b, i);
            containsDynArr(b, i);
        }
        t2 = getMilliseconds(); /*Time after contains()*/
        printf("Time for running contains() on %d elements: %g ms\n", n, t2 - t1);
        deleteDynArr(b); /* delete DynArr */
    }
    return 0;
}
