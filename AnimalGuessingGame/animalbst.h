/* CS261- Assignment 4 - Extra Credit - bst.h*/
/* Name: Corey Hemphill
 * Date: 11/6/2015
 * Solution description: (none)
 */

/*
  File: bst.h
  Interface definition of the binary search tree data structure.
*/

#ifndef __ANIMALBST_H
#define __ANIMALBST_H

/* Defines the type to be stored in the data structure.  These macros
 * are for convenience to avoid having to search and replace/dup code
 * when you want to build a structure of doubles as opposed to ints
 * for example.
 */

# ifndef TYPE
# define TYPE      void*
# endif

/*Function used to compare two TYPE values to each other, defined in compare.c file*/
int compare(TYPE left, TYPE right);
/*Function used to print TYPE values, defined in compare.c file*/
void print_type(TYPE curval);

/*Declared in the c source file to hide the structure members from the user.*/
struct BSTree;

/*Initialize binary search tree structure.*/
void initBSTree(struct BSTree *tree);

/*Allocate and initialize search tree structure.*/
struct BSTree *newBSTree();

/*Deallocate nodes in BST. */
void clearBSTree(struct BSTree *tree);

/*Deallocate nodes in BST and deallocate the BST structure.*/
void deleteBSTree(struct BSTree *tree);

/*--BST Bag Interface--*/
int isEmptyBSTree(struct BSTree *tree);
int sizeBSTree(struct BSTree *tree);

void addBSTree(struct BSTree *tree, TYPE val);
int containsBSTree(struct BSTree *tree, TYPE val);
void removeBSTree(struct BSTree *tree, TYPE val);
void printTree(struct BSTree *tree);
# endif // ANIMAL
