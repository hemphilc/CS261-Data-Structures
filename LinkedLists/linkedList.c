/* CS261- Assignment 3 - linkedList.c*/
/* Name: Corey Hemphill
 * Date: 10/23/2015
 * Solution description: (none)
 */

#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/* Double Link */
struct DLink {
    TYPE value;
    struct DLink *next;
    struct DLink *prev;
};

/* Double Linked List with Head and Tail Sentinels */
struct linkedList {
    int size;
    struct DLink *firstLink;
    struct DLink *lastLink;
};

/*
    initList
    param lst the linkedList
    pre: lst is not null
    post: lst size is 0
*/
void _initList(struct linkedList *lst) {
    /* FIXME: you must write this */
    assert(lst != NULL);
    lst->firstLink = malloc(sizeof(struct DLink));
    assert(lst->firstLink != 0);
    lst->lastLink = malloc(sizeof(struct DLink));
    assert(lst->lastLink != 0);
    lst->firstLink->next = lst->lastLink;
    lst->lastLink->prev = lst->firstLink;
    lst->firstLink->value = 0;
    lst->lastLink->value = 0;
    lst->size = 0;
}

/*
    createList
    param: none
    pre: none
    post: firstLink and lastLink reference sentinels
*/
struct linkedList *createLinkedList() {
    struct linkedList *newList = malloc(sizeof(struct linkedList));
    _initList(newList);
    return(newList);
}

/*
    _addLinkBeforeBefore
    param: lst the linkedList
    param: l the  link to add before
    param: v the value to add
    pre: lst is not null
    pre: l is not null
    post: lst is not empty
*/

/* Adds Before the provided link, l */
void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v) {
    /* FIXME: you must write this */
    assert(lst != NULL);
    assert(l != NULL);
    struct DLink *newLink = malloc(sizeof(struct DLink));
    newLink->value = v;
    newLink->prev = l->prev;
    newLink->next = l;
    l->prev->next = newLink;
    l->prev = newLink;
    lst->size += 1;
}

/*
    _removeLink
    param: lst the linkedList
    param: l the link to be removed
    pre: lst is not null
    pre: l is not null
    post: lst size is reduced by 1
*/
void _removeLink(struct linkedList *lst, struct DLink *l) {
    /* FIXME: you must write this */
    assert(lst != NULL);
    assert(l != NULL);
    assert(isEmptyList(lst) != 1);
    struct DLink *tempLinkFront;
    struct DLink *tempLinkBack;
    tempLinkFront = l->prev;
    tempLinkBack = l->next;
    tempLinkFront->next = tempLinkBack;
    tempLinkBack->prev = tempLinkFront;
    free(l);
    lst->size -= 1;
}

/*
    isEmptyList
    param: lst the linkedList
    pre: lst is not null
    post: none
*/
int isEmptyList(struct linkedList *lst) {
    /* FIXME: you must write this */
    assert(lst != NULL);
    if(lst->size == 0) {
        return 1;
    }
    /* Temporary return value...you may need to change this */
    return 0;
}

/* De-allocate all links of the list

    param: 	lst		pointer to the linked list
    pre:	none
    post:	All links (including the two sentinels) are de-allocated
*/
void freeLinkedList(struct linkedList *lst) {
    while(!isEmptyList(lst)) {
        /* Remove the link right after the first sentinel */
        _removeLink(lst, lst->firstLink->next);
    }
    /* Remove the first and last sentinels */
    free(lst->firstLink);
    free(lst->lastLink);
}

/* 	Deallocate all the links and the linked list itself.

    param: 	lst		pointer to the linked list
    pre:	lst is not null
    post:	the memory used by lst is freed
*/
void deleteLinkedList(struct linkedList *lst) {
    assert(lst != 0);
    freeLinkedList(lst);
    free(lst);
}

/*  Function to print list
    Pre: lst is not null
*/
void _printList(struct linkedList* lst) {
    /* FIXME: you must write this */
    assert(lst != NULL);
    struct DLink *tempLink;
    tempLink = lst->firstLink;
    assert(tempLink->next != NULL);
    int i;
    for(i = 0; i < lst->size; i++) {
        tempLink = tempLink->next;
        printf("%d ", tempLink->value);
    }
    printf("\n");
}

/* ************************************************************************
    Deque Interface Functions
************************************************************************ */

/*
    addFrontList
    param: lst the linkedList
    param: e the element to be added
    pre: lst is not null
    post: lst is not empty, increased size by 1
*/
void addFrontList(struct linkedList *lst, TYPE e) {
    /* FIXME: you must write this */
    assert(lst != NULL);
    _addLinkBefore(lst, lst->firstLink->next, e);
    assert(isEmptyList(lst) != 1);
}

/*
    addBackList
    param: lst the linkedList
    param: e the element to be added
    pre: lst is not null
    post: lst is not empty, increased size by 1
*/
void addBackList(struct linkedList *lst, TYPE e) {
    /* FIXME: you must write this */
    assert(lst != NULL);
    _addLinkBefore(lst, lst->lastLink, e);
    assert(isEmptyList(lst) != 1);
}

/*
    frontList
    param: lst the linkedList
    pre: lst is not null
    pre: lst is not empty
    post: none
*/
TYPE frontList(struct linkedList *lst) {
    /* FIXME: you must write this */
    assert(lst != NULL);
    assert(isEmptyList(lst) != 1);
    /* Temporary return value...you may need to change this */
    return lst->firstLink->next->value;
}

/*
    backList
    param: lst the linkedList
    pre: lst is not null
    pre: lst is not empty
    post: lst is not empty
*/
TYPE backList(struct linkedList *lst) {
    /* FIXME: you must write this */
    assert(lst != NULL);
    assert(isEmptyList(lst) != 1);
    /* Temporary return value...you may need to change this */
    return lst->lastLink->prev->value;
}

/*
    removeFrontList
    param: lst the linkedList
    pre:lst is not null
    pre: lst is not empty
    post: size is reduced by 1
*/
void removeFrontList(struct linkedList *lst) {
    /* FIXME: you must write this */
    assert(lst != NULL);
    assert(isEmptyList(lst) != 1);
    _removeLink(lst, lst->firstLink->next);
}

/*
    removeBackList
    param: lst the linkedList
    pre: lst is not null
    pre:lst is not empty
    post: size reduced by 1
*/
void removeBackList(struct linkedList *lst) {
    /* FIXME: you must write this */
    assert(lst != NULL);
    assert(isEmptyList(lst) != 1);
    _removeLink(lst, lst->lastLink->prev);
}


/* ************************************************************************
    Stack Interface Functions
************************************************************************ */

/*
    Add an item to the bag
    param: 	lst		pointer to the bag
    param: 	v		value to be added
    pre:	lst is not null
    post:	a link storing val is added to the bag
 */
void addList(struct linkedList *lst, TYPE v) {
    /* FIXME: you must write this */
    assert(lst != NULL);
    addFrontList(lst, v);
}

/*	Returns boolean (encoded as an int) demonstrating whether or not
    the specified value is in the collection
    true = 1
    false = 0

    param:	lst		pointer to the bag
    param:	e		the value to look for in the bag
    pre:	lst is not null
    pre:	lst is not empty
    post:	no changes to the bag
*/
int containsList (struct linkedList *lst, TYPE e) {
    /* FIXME: you must write this */
    assert(lst != NULL);
    assert(isEmptyList(lst) != 1);
    struct DLink *tempLink;
    tempLink = lst->firstLink;
    int i;
    for(i = 0; i < lst->size; i++) {
        assert(tempLink->next != NULL);
        tempLink = tempLink->next;
        if(tempLink->value == e)
            return 1;
    }
    /*Temporary return value...you may need to change this */
    return 0;
}

/*	Removes the first occurrence of the specified value from the collection
    if it occurs

    param:	lst		pointer to the bag
    param:	e		the value to be removed from the bag
    pre:	lst is not null
    pre:	lst is not empty
    post:	e has been removed
    post:	size of the bag is reduced by 1
*/
void removeList(struct linkedList *lst, TYPE e) {
    /* FIXME: you must write this */
    assert(lst != NULL);
    assert(isEmptyList(lst) != 1);
    if(containsList(lst, e) == 1) {
        struct DLink *tempLink;
        tempLink = lst->firstLink;
        int i;
        for(i = 0; i < lst->size; i++) {
            assert(tempLink->next != NULL);
            tempLink = tempLink->next;
            if(tempLink->value == e)
                _removeLink(lst, tempLink);
        }
    }
}
