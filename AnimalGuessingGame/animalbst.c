/* CS261- Assignment 4 - Extra Credit - animalbst.c*/
/* Name: Corey Hemphill
 * Date: 11/6/2015
 * Solution description: (none)
 */

/*
  File: animalbst.c
  Implementation of the binary search tree data structure.
*/
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "animalbst.h"
#include "animalstruct.h"


struct Node {
    TYPE         val;
    struct Node *left;
    struct Node *right;
};

struct BSTree {
    struct Node *root;
    int          cnt;
};

/*----------------------------------------------------------------------------*/
/*
  Function to initialize the binary search tree.
  param tree
  pre: tree is not null
  post:	tree size is 0
  root is null
*/
void initBSTree(struct BSTree *tree) {
    tree->cnt  = 0;
    tree->root = 0;
}

/*
  Function to create a binary search tree.
  param: none
  pre: none
  post: tree->count = 0
  tree->root = 0;
*/
struct BSTree* newBSTree() {
    struct BSTree *tree = (struct BSTree *)malloc(sizeof(struct BSTree));
    assert(tree != 0);
    initBSTree(tree);
    return tree;
}

/*----------------------------------------------------------------------------*/
/*
  Function to free the nodes of a binary search tree.
  param: node  the root node of the tree to be freed
  pre: none
  post: node and all descendants are deallocated
*/
void _freeBST(struct Node *node) {
    if (node != 0) {
    _freeBST(node->left);
    _freeBST(node->right);
    free(node);
    }
}

/*
  Function to clear the nodes of a binary search tree.
  param: tree    a binary search tree
  pre: tree ! = null
  post: the nodes of the tree are deallocated
  tree->root = 0;
  tree->cnt = 0
*/
void clearBSTree(struct BSTree *tree) {
    _freeBST(tree->root);
    tree->root = 0;
    tree->cnt  = 0;
}

/*
  Function to deallocate a dynamically allocated binary search tree.
  param: tree   the binary search tree
  pre: tree != null;
  post: all nodes and the tree structure itself are deallocated.
*/
void deleteBSTree(struct BSTree *tree) {
    clearBSTree(tree);
    free(tree);
}

/*----------------------------------------------------------------------------*/
/*
  Function to determine if  a binary search tree is empty.
  param: tree    the binary search tree
  pre:  tree is not null
*/
int isEmptyBSTree(struct BSTree *tree) {
    return (tree->cnt == 0);
}

/*
  Function to determine the size of a binary search tree.
  param: tree    the binary search tree
  pre:  tree is not null
*/
int sizeBSTree(struct BSTree *tree) {
    return tree->cnt;
}

/*----------------------------------------------------------------------------*/
/*
  Recursive helper function to add a node to the binary search tree.
  HINT: You have to use the compare() function to compare values.
  param:  cur	the current root node
  val	the value to be added to the binary search tree
  pre:	val is not null
*/
struct Node *_addNode(struct Node *cur, TYPE val) {
    assert(val != NULL);
    if(cur == NULL) {
        cur = malloc(sizeof(struct Node));
        cur->val = val;
        cur->left = NULL;
        cur->right = NULL;
        return cur;
    }
    else {
        if(compare(cur->val, val) == 1) {
            cur->left = _addNode(cur->left, val);
        }
        else if((compare(cur->val, val) == -1) || (compare(cur->val, val) == 0))  {
            cur->right = _addNode(cur->right, val);
        }
    }
    return cur;
}

/*
  Function to add a value to the binary search tree.
  param: tree   the binary search tree
  val		the value to be added to the tree
  pre:	tree is not null
  val is not null
  pose:  tree size increased by 1
  tree now contains the value, val
*/
void addBSTree(struct BSTree *tree, TYPE val) {
    tree->root = _addNode(tree->root, val);
    tree->cnt++;
}

/*
  Function to determine if the binary search tree contains a particular element.
  HINT: You have to use the compare() function to compare values.
  param:	tree	the binary search tree
  val		the value to search for in the tree
  pre:	tree is not null
  val is not null
  post:	none
*/

/*----------------------------------------------------------------------------*/
int containsBSTree(struct BSTree *tree, TYPE val) {
    assert(tree != NULL);
    assert(val != NULL);
    struct Node *current = tree->root;
    struct Node *temp = malloc(sizeof(struct Node));
    temp->val = val;
    while(1 /*TRUE*/) {
        if(compare(current->val, temp->val) == 1) {
            if(current->left != NULL) {
                current = current->left;
            }
            else {
                return 0;
            }
        }
        else if(compare(current->val, temp->val) == -1) {
            if(current->right != NULL) {
                current = current->right;
            }
            else {
                return 0;
            }
        }
        else if(compare(current->val, temp->val) == 0) {
            return 1;
        }
    }
    return 0;
}

/*
  Helper function to find the left most child of a node.
  return the value of the left most child of cur
  param: cur		the current node
  pre:	cur is not null
  post: none
*/

/*----------------------------------------------------------------------------*/
TYPE _leftMost(struct Node *cur) {
    assert(cur != NULL);
    while(1 /*TRUE*/) {
        if(cur->left == NULL) {
            return cur->val;
        }
        else {
            cur = cur->left;
        }
    }
    return cur;
}

/*
  Recursive helper function to remove the left most child of a node.
  HINT: this function returns cur if its left child is NOT NULL. Otherwise,
  it returns the right child of cur and free cur.
  Note:  If you do this iteratively, the above hint does not apply.
  param: cur	the current node
  pre:	cur is not null
  post:	the left most node of cur is not in the tree
*/
/*----------------------------------------------------------------------------*/
struct Node *_removeLeftMost(struct Node *cur) {
    assert(cur != NULL);
    struct Node *rightPtr;
    if(cur->left == NULL) {
        rightPtr = cur->right;
        free(cur);
        return rightPtr;
    }
    else {
        cur->left = _removeLeftMost(cur->left);
    }
    return cur;
}

/*
  Recursive helper function to remove a node from the tree.
  HINT: You have to use the compare() function to compare values.
  param:	cur	the current node
  val	the value to be removed from the tree
  pre:	val is in the tree
  cur is not null
  val is not null
*/
/*----------------------------------------------------------------------------*/
struct Node *_removeNode(struct Node *cur, TYPE val) {
    assert(cur != NULL);
    assert(val != NULL);
    struct Node *temp;
    if(compare(cur->val, val) == 0) {
        if(cur->left == NULL && cur->right == NULL) {
            free(cur);
            return NULL;
        }
        else if(cur->right == NULL) {
            temp = cur->left;
            free(cur);
            return temp;
        }
        else {
            cur->val = _leftMost(cur->right);
            _removeLeftMost(cur->right);
            return cur;
        }
    }
    else if(compare(cur->val, val) == 1) {
        cur->left = _removeNode(cur->left, val);
    }
    else if(compare(cur->val, val) == -1) {
        cur->right = _removeNode(cur->right, val);
    }
    return cur;
}
/*
  Function to remove a value from the binary search tree
  param: tree   the binary search tree
  val		the value to be removed from the tree
  pre:	tree is not null
  val is not null
  val is in the tree
  pose:	tree size is reduced by 1
*/
void removeBSTree(struct BSTree *tree, TYPE val) {
    if (containsBSTree(tree, val)) {
    tree->root = _removeNode(tree->root, val);
    tree->cnt--;
    }
}

/*----------------------------------------------------------------------------*/

/*The following is used only for debugging, set to "#if 0" when used
  in other applications.*/
#if 1
#include <stdio.h>

/*----------------------------------------------------------------------------*/
void printNode(struct Node *cur) {
    if (cur == 0)
    return;
    printf("(");
    printNode(cur->left);
    print_type(cur->val);
    printNode(cur->right);
    printf(")");
}

void printTree(struct BSTree *tree) {
    if (tree == 0)
    return;
    printNode(tree->root);
}
/*----------------------------------------------------------------------------*/

#endif

/*
  Function to build a Binary Search Tree (BST) by adding questions and answers
  in a specific order.
*/
struct BSTree *buildBSTTree() {
    /*
              Q
        Q           Q
     Q     Q     Q     Q
    A A   A A   A A   A A

    */
    struct BSTree *tree	= newBSTree();

    /*Create Questions*/
    struct animal *question1 = (struct animal*) malloc(sizeof(struct animal));
    struct animal *question2 = (struct animal*) malloc(sizeof(struct animal));
    struct animal *question3 = (struct animal*) malloc(sizeof(struct animal));
    struct animal *question4 = (struct animal*) malloc(sizeof(struct animal));
    struct animal *question5 = (struct animal*) malloc(sizeof(struct animal));
    struct animal *question6 = (struct animal*) malloc(sizeof(struct animal));
    struct animal *question7 = (struct animal*) malloc(sizeof(struct animal));

    /*Create Animal Answers*/
    struct animal *seal = (struct animal*) malloc(sizeof(struct animal));
    struct animal *whale = (struct animal*) malloc(sizeof(struct animal));
    struct animal *seaturtle = (struct animal*) malloc(sizeof(struct animal));
    struct animal *swordfish = (struct animal*) malloc(sizeof(struct animal));
    struct animal *chimpanzee = (struct animal*) malloc(sizeof(struct animal));
    struct animal *leopard = (struct animal*) malloc(sizeof(struct animal));
    struct animal *zergling = (struct animal*) malloc(sizeof(struct animal));
    struct animal *dog = (struct animal*) malloc(sizeof(struct animal));

    /*Initialize Animal Questions*/
    question1->animalString = "Does it live in the water? [Y/N] ";
    question1->number = 8;
    question2->animalString = "Is it a mammal? [Y/N] ";
    question2->number = 4;
    question3->animalString = "Does it climb trees? [Y/N] ";
    question3->number = 12;
    question4->animalString = "Does it have fur? [Y/N] ";
    question4->number = 2;
    question5->animalString = "Does it have a shell? [Y/N] ";
    question5->number = 6;
    question6->animalString = "Can it walk on two legs? [Y/N] ";
    question6->number = 10;
    question7->animalString = "Does it eat space marines? [Y/N] ";
    question7->number = 14;

    /*Initialize Animal Answers*/
    seal->animalString = "Seal";
    seal->number = 1;
    whale->animalString = "Whale";
    whale->number = 3;
    seaturtle->animalString = "Sea Turtle";
    seaturtle->number = 5;
    swordfish->animalString = "Swordfish";
    swordfish->number = 7;
    chimpanzee->animalString = "Chimpanzee";
    chimpanzee->number = 9;
    leopard->animalString = "Leopard";
    leopard->number = 11;
    zergling->animalString = "Zergling";
    zergling->number = 13;
    dog->animalString = "Dog";
    dog->number = 15;

    /*Add the questions to BST*/
    addBSTree(tree, question1);
    addBSTree(tree, question2);
    addBSTree(tree, question3);
    addBSTree(tree, question4);
    addBSTree(tree, question5);
    addBSTree(tree, question6);
    addBSTree(tree, question7);

    addBSTree(tree, seal);
    addBSTree(tree, seaturtle);
    addBSTree(tree, swordfish);
    addBSTree(tree, whale);
    addBSTree(tree, zergling);
    addBSTree(tree, dog);
    addBSTree(tree, chimpanzee);
    addBSTree(tree, leopard);

    return tree;
}

void playGame() {
    printf("\nWelcome to the Animal Guessing Game!\n");
    printf("Programmed by Corey Hemphill.\n\n");
    /*Creat Animal Game Tree*/
    struct BSTree *animalTree = buildBSTTree();
    assert(animalTree != NULL);
    /*Create Iterator for Navigating Game Tree*/
    struct BSTree *nextPtr = malloc(sizeof(struct BSTree));
    assert(nextPtr != NULL);
    /*Create Pointer to Current animal Struct*/
    struct animal *current = malloc(sizeof(struct animal));
    assert(current != NULL);
    /*Create Pointer for a Char to Represent the User's Response to a Question [y/Y or n/N]*/
    char *userResponse = malloc(sizeof(char));
    assert(userResponse != NULL);
    /*Create Pointer for a Int to Represent the User's Response to Play Again*/
    int *playAgain = malloc(sizeof(int));
    *playAgain = 1;
    /*Game Loop*/
    while(*playAgain == 1) {
        current = animalTree->root->val;
        nextPtr->root = animalTree->root;
        /*Ask Questions*/
        int i;
        for(i = 0; i < 3; i++) {
            printf("%s", current->animalString);
            scanf("%s", userResponse);
            /*If yes, move left*/
            if(*userResponse == 'Y' || *userResponse == 'y') {
                nextPtr->root = nextPtr->root->left;
            }
            /*If no, move right*/
            else if(*userResponse == 'N' || *userResponse == 'n') {
                nextPtr->root = nextPtr->root->right;
            }
            current = nextPtr->root->val;
        }
        /*Print Answer*/
        printf("The animal you're thinking of is a %s.\n\n", current->animalString);
        /*Ask to play again*/
        printf("Play again? Press 1 and Enter if 'Yes': ");
        scanf("%d", playAgain);
    }
    /*Farewell*/
    printf("\nThanks for playing! Goodbye...\n\n");
    /*Clean Up*/
    deleteBSTree(animalTree);
    free(nextPtr);
    free(current);
    free(userResponse);
    free(playAgain);
}

int main(void) {
    playGame();
    return 0;
}

