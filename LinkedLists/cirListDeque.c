/* CS261- Assignment 3 - cirListDeque.c*/
/* Name: Corey Hemphill
 * Date: 10/23/2015
 * Solution description: (none)
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include "cirListDeque.h"

#define TYPE_SENTINEL_VALUE DBL_MAX

/* ************************************************************************
 Deque ADT based on Circularly-Doubly-Linked List WITH Sentinel
 ************************************************************************ */

/* Double Link Structure */
struct DLink {
    TYPE value;/* value of the link */
    struct DLink *next; /* Pointer to the next link */
    struct DLink *prev; /* Pointer to the previous link */
};

/* Deque Structure */
struct cirListDeque {
    int size; /* Number of links in the deque */
    struct DLink *Sentinel;	/* Pointer to the sentinel */
};

/* Internal function prototypes */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);

/* ************************************************************************
    Deque Functions
************************************************************************ */

/* Initialize deque
    param: 	q		pointer to the deque
    pre:	q is not null
    post:	q->Sentinel is allocated and q->size equals zero
*/
void _initCirListDeque (struct cirListDeque *q) {
    /* FIXME: you must write this */
    assert(q != NULL);
    struct DLink *newSentinel = malloc(sizeof(struct DLink));
    assert(newSentinel != NULL);
    q->Sentinel = newSentinel;
    q->Sentinel->next = q->Sentinel->prev = q->Sentinel;
    q->size = 0;
}

/* Create a new circular list deque */
struct cirListDeque *createCirListDeque() {
    struct cirListDeque *newCL = malloc(sizeof(struct cirListDeque));
    _initCirListDeque(newCL);
    return(newCL);
}

/* Create a link for a value.
    param: 	val		the value to create a link for
    pre:	none
    post:	a link to store the value
*/
struct DLink * _createLink (TYPE val) {
    /* FIXME: you must write this */
    struct DLink *newLink = malloc(sizeof(struct DLink));
    assert(newLink != NULL);
    newLink->value = val;
    /* Temporary return value...you may need to change it */
    return newLink;

}

/* Adds a link after another link
    param: 	q		pointer to the deque
    param: 	lnk		pointer to the existing link in the deque
    param: 	v		value of the new link to be added after the existing link
    pre:	q is not null
    pre: 	lnk is not null
    pre:	lnk is in the deque
    post:	the new link is added into the deque after the existing link
*/
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v) {
    /* FIXME: you must write this */
    assert(q != NULL);
    assert(lnk != NULL);
    struct DLink *newLink = _createLink(v);
    assert(newLink != NULL);
    newLink->next = lnk->next;
    newLink->prev = lnk;
    lnk->next->prev = newLink;
    lnk->next = newLink;
    q->size += 1;
}

/* Adds a link to the back of the deque
    param: 	q		pointer to the deque
    param: 	val		value for the link to be added
    pre:	q is not null
    post:	a link storing val is added to the back of the deque
*/
void addBackCirListDeque (struct cirListDeque *q, TYPE val) {
    /* FIXME: you must write this */
    assert(q != NULL);
    struct DLink *newLink = _createLink(val);
    assert(newLink != NULL);
    _addLinkAfter(q, q->Sentinel->prev, val);
}

/* Adds a link to the front of the deque
    param: 	q		pointer to the deque
    param: 	val		value for the link to be added
    pre:	q is not null
    post:	a link storing val is added to the front of the deque
*/
void addFrontCirListDeque(struct cirListDeque *q, TYPE val) {
    /* FIXME: you must write this */
    assert(q != NULL);
    struct DLink *newLink = _createLink(val);
    assert(newLink != NULL);
    _addLinkAfter(q, q->Sentinel, val);
}

/* Get the value of the front of the deque
    param: 	q		pointer to the deque
    pre:	q is not null and q is not empty
    post:	none
    ret: 	value of the front of the deque
*/
TYPE frontCirListDeque(struct cirListDeque *q) {
    /* FIXME: you must write this */
    assert(q != NULL);
    assert(isEmptyCirListDeque(q) != 1);
    /* Temporary return value...you may need to change it*/
    return q->Sentinel->next->value;
}

/* Get the value of the back of the deque
    param: 	q		pointer to the deque
    pre:	q is not null and q is not empty
    post:	none
    ret: 	value of the back of the deque
*/
TYPE backCirListDeque(struct cirListDeque *q) {
    /* FIXME: you must write this */
    assert(q != NULL);
    assert(isEmptyCirListDeque(q) != 1);
    /* Temporary return value...you may need to change it*/
    return q->Sentinel->prev->value;
}

/* Remove a link from the deque
    param: 	q		pointer to the deque
    param: 	lnk		pointer to the link to be removed
    pre:	q is not null and q is not empty
    post:	the link is removed from the deque
*/
void _removeLink(struct cirListDeque *q, struct DLink *lnk) {
    /* FIXME: you must write this */
    assert(q != NULL);
    assert(isEmptyCirListDeque(q) != 1);
    lnk->prev->next = lnk->next;
    lnk->next->prev = lnk->prev;
    free(lnk);
    q->size -= 1;
}

/* Remove the front of the deque
    param: 	q		pointer to the deque
    pre:	q is not null and q is not empty
    post:	the front is removed from the deque
*/
void removeFrontCirListDeque (struct cirListDeque *q) {
    /* FIXME: you must write this */
    assert(q != NULL);
    assert(isEmptyCirListDeque(q) != 1);
    _removeLink(q, q->Sentinel->next);
}


/* Remove the back of the deque
    param: 	q		pointer to the deque
    pre:	q is not null and q is not empty
    post:	the back is removed from the deque
*/
void removeBackCirListDeque(struct cirListDeque *q) {
    /* FIXME: you must write this */
    assert(q != NULL);
    assert(isEmptyCirListDeque(q) != 1);
    _removeLink(q, q->Sentinel->prev);
}

/* De-allocate all links of the deque
    param: 	q		pointer to the deque
    pre:	none
    post:	All links (including Sentinel) are de-allocated
*/
void freeCirListDeque(struct cirListDeque *q) {
    /* FIXME: you must write this */
    while(q->size > 0) {
        removeFrontCirListDeque(q);
    }
    free(q->Sentinel);
}

/* 	Deallocate all the links and the deque itself
    param: 	q		pointer to the deque
    pre:	q is not null
    post:	the memory used by q is freed
*/
void deleteCirListDeque(struct cirListDeque *q) {
    assert(q != 0);
    freeCirListDeque(q);
    free(q);
    q->size = 0;
}

/* Check whether the deque is empty
    param: 	q		pointer to the deque
    pre:	q is not null
    ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyCirListDeque(struct cirListDeque *q) {
    /* FIXME: you must write this */
    assert(q != NULL);
    if(q->size == 0) {
        return 1;
    }
    /* Temporary return value...you may need to change it*/
    return 0;
}

/* Print the links in the deque from front to back
    param: 	q		pointer to the deque
    pre:	q is not null and q is not empty
    post: 	the links in the deque are printed from front to back
*/
void printCirListDeque(struct cirListDeque *q) {
    /* FIXME: you must write this */
    assert(q != NULL);
    struct DLink *tempLink;
    tempLink = q->Sentinel;
    assert(tempLink->next != NULL);
    int i;
    for(i = 0; i < q->size; i++) {
        tempLink = tempLink->next;
        printf("%.1f ", tempLink->value);
    }
    printf("\n");
}

/* Reverse the deque
    param: 	q		pointer to the deque
    pre:	q is not null and q is not empty
    post: 	the deque is reversed
*/
void reverseCirListDeque(struct cirListDeque *q) {
    /* FIXME: you must write this */
    assert(q != NULL);
    assert(isEmptyCirListDeque(q) != 1);
    struct DLink *temp = q->Sentinel;
    do {
        struct DLink *tempNext = temp->next;
        struct DLink *tempPrev = temp->prev;
        temp->next = tempPrev;
        temp->prev = tempNext;
        temp = tempNext;
    }
    while(temp != q->Sentinel);
}
