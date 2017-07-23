/* CS261- Assignment 3 - testLinkedList.c*/
/* Name: Corey Hemphill
 * Date: 10/23/2015
 * Solution description: (none)
 */

#include "linkedList.h"
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
    struct linkedList *lst = createLinkedList();
    assert(lst != NULL);
    printf("\nList is not NULL...\n");

    /* Test addFrontList */
    printf("\nTesting addFrontList...\n");
    addFrontList(lst, 1);
    addFrontList(lst, 2);
    addFrontList(lst, 3);
    addFrontList(lst, 4);
    addFrontList(lst, 5);
    printf("The list's content: [5,4,3,2,1]\n");
    assertTrue(containsList(lst, 1), "Test contains 1");
    assertTrue(containsList(lst, 2), "Test contains 2");
    assertTrue(containsList(lst, 3), "Test contains 3");
    assertTrue(containsList(lst, 4), "Test contains 4");
    assertTrue(containsList(lst, 5), "Test contains 5");
    _printList(lst);

    /* Test addBackList */
    printf("\nTesting addBackList...\n");
    addBackList(lst, 6);
    addBackList(lst, 7);
    addBackList(lst, 8);
    addBackList(lst, 9);
    addBackList(lst, 10);
    printf("The list's content: [5,4,3,2,1,6,7,8,9,10]\n");
    assertTrue(containsList(lst, 6), "Test contains 6");
    assertTrue(containsList(lst, 7), "Test contains 7");
    assertTrue(containsList(lst, 8), "Test contains 8");
    assertTrue(containsList(lst, 9), "Test contains 9");
    assertTrue(containsList(lst, 10), "Test contains 10");
    _printList(lst);

    /* Test removeFrontList & removeBackList */
    printf("\nTesting removeFrontList & removeBackList...\n");
    removeFrontList(lst);
    removeFrontList(lst);
    removeBackList(lst);
    removeBackList(lst);
    printf("The list's content: [3,2,1,6,7,8]\n");
    assertTrue(containsList(lst, 5) == 0, "Test does not contain 5");
    assertTrue(containsList(lst, 4) == 0, "Test does not contain 4");
    assertTrue(containsList(lst, 9) == 0, "Test does not contain 9");
    assertTrue(containsList(lst, 10) == 0, "Test does not contain 10");
    _printList(lst);

    /* Test addList */
    printf("\nTesting addList...\n");
    addList(lst, 20);
    addList(lst, 21);
    addList(lst, 22);
    addList(lst, 23);
    printf("The list's content: [23,22,21,20,3,2,1,6,7,8]\n");
    assertTrue(containsList(lst, 20) == 1, "Test contains 20");
    assertTrue(containsList(lst, 21) == 1, "Test contains 21");
    assertTrue(containsList(lst, 22) == 1, "Test contains 22");
    assertTrue(containsList(lst, 23) == 1, "Test contains 23");
    _printList(lst);

    /* Test removeList */
    printf("\nTesting removeList...\n");
    removeList(lst, 20);
    removeList(lst, 3);
    removeList(lst, 2);
    removeList(lst, 1);
    printf("The list's content: [23,22,21,6,7,8]\n");
    assertTrue(containsList(lst, 20) == 0, "Test does not contain 20");
    assertTrue(containsList(lst, 1) == 0, "Test does not contain 1");
    assertTrue(containsList(lst, 2) == 0, "Test does not contain 2");
    assertTrue(containsList(lst, 3) == 0, "Test does not contain 3");
    _printList(lst);

    /* Test removeList */
    printf("\nTesting frontList & backList...\n");
    printf("The list's content: [23,22,21,6,7,8]\n");
    assertTrue(frontList(lst) == 23, "Test shows front as 23");
    assertTrue(backList(lst) == 8, "Test shows back as 8");
    _printList(lst);


    /* Test deleteLinkedList */
    printf("\nDeleting linked list...\n");
    deleteLinkedList(lst);
    assertTrue(isEmptyList(lst) == 0, "Linked list deleted successfully");
    printf("\n");

    return 0;
}
