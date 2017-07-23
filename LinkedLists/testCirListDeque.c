/* CS261- Assignment 3 - testCirListDeque.c*/
/* Name: Corey Hemphill
 * Date: 10/23/2015
 * Solution description: (none)
 */

#include "cirListDeque.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void assertTrue(int predicate, char *message) {
    printf("%s: ", message);
    if (predicate)
        printf("PASSED\n");
    else
        printf("FAILED\n");
}

int main(/*int argc, char* argv[]*/) {
    printf("\nHello from test code!\n");
    /* Test your linked list in here! */
    struct cirListDeque *lst = createCirListDeque();
    assert(lst != NULL);
    printf("\nList is not NULL...\n");

    /* Test addFrontCirListDeque & addBackCirListDeque */
    printf("\nTesting addFrontCirListDeque & addBackCirListDeque...\n");
    addFrontCirListDeque(lst, 1);
    addBackCirListDeque(lst, 2);
    printf("The list's content: [1,2]\n");
    assertTrue(frontCirListDeque(lst) == 1, "Test contains 1");
    assertTrue(backCirListDeque(lst) == 2, "Test contains 2");
    printCirListDeque(lst);
    addFrontCirListDeque(lst, 3);
    addBackCirListDeque(lst, 4);
    printf("The list's content: [3,1,2,4]\n");
    assertTrue(frontCirListDeque(lst) == 3, "Test contains 3");
    assertTrue(backCirListDeque(lst) == 4, "Test contains 4");
    printCirListDeque(lst);

    /* Test addFrontCirListDeque & addBackCirListDeque */
    printf("\nTesting removeFrontCirListDeque & removeBackCirListDeque...\n");
    removeFrontCirListDeque(lst);
    removeBackCirListDeque(lst);
    printf("The list's content: [1,2]\n");
    assertTrue(frontCirListDeque(lst) == 1, "Test no longer contains 3");
    assertTrue(backCirListDeque(lst) == 2, "Test no longer contains 4");
    printCirListDeque(lst);

    /* Test isEmptyCirListDeque */
    printf("\nTesting isEmptyCirListDeque...\n");
    printf("Popping the remaining elements of the deque...\n");
    removeFrontCirListDeque(lst);
    removeFrontCirListDeque(lst);
    printf("The list's content: []\n");
    assertTrue(isEmptyCirListDeque(lst) == 1, "Deque is empty");

    /* Test reverseCirListDeque */
    printf("\nTesting reverseCirListDeque...\n");
    addBackCirListDeque(lst, 1);
    addBackCirListDeque(lst, 2);
    addBackCirListDeque(lst, 3);
    addBackCirListDeque(lst, 4);
    addBackCirListDeque(lst, 5);
    printf("PRE-REVERSE:\n");
    printf("The list's content: [1,2,3,4,5]\n");
    assertTrue(frontCirListDeque(lst) == 1, "Front is 1");
    assertTrue(backCirListDeque(lst) == 5, "Back is 5");
    printCirListDeque(lst);
    reverseCirListDeque(lst);
    printf("\nPOST-REVERSE\n");
    printf("The list's content: [5,4,3,2,1]\n");
    assertTrue(frontCirListDeque(lst) == 5, "Front is 5");
    assertTrue(backCirListDeque(lst) == 1, "Back is 1");
    printCirListDeque(lst);
    printf("\nPopping front and back...\n\n");
    removeFrontCirListDeque(lst);
    removeBackCirListDeque(lst);
    printf("The list's content: [4,3,2]\n");
    assertTrue(frontCirListDeque(lst) == 4, "Front is 4");
    assertTrue(backCirListDeque(lst) == 2, "Back is 2");
    printCirListDeque(lst);
    printf("\nREVERSE SUCCESS!\n\n");

    /* Test deleteCirListDeque */
    printf("Deleting deque...\n");
    deleteCirListDeque(lst);
    assertTrue(isEmptyCirListDeque(lst) == 1, "Deque deleted successfully");
    printf("\n");

    return 0;
}
