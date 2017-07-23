/* CS261- Assignment 5 - main.c*/
/* Name: Corey Hemphill
 * Date: 11/15/2015
 * Solution description: (none)
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main(int argc, const char * argv[]) {
    char cmd = ' ';
    DynArr* mainList = createDynArr(10);
    FILE *filePtr;
    char *temp;
    int priority;
    char desc[TASK_DESC_SIZE];
    TaskP firstTemp;
    /* Assuming fileName <= 100 characters. */
    char fileName[100];
    /* Start */
    printf("\n\n** TO-DO LIST APPLICATION **\n\n");
    do {
        printf("Press:\n"
               "'l' to load to-do list from a file\n"
               "'s' to save to-do list to a file\n"
               "'a' to add a new task\n"
               "'g' to get the first task\n"
               "'r' to remove the first task\n"
               "'p' to print the list\n"
               "'e' to exit the program\n"
               );
        /* Get Input Command (from the keyboard) */
        cmd = getchar();
        /* Clear the Trailing Newline Character */
        while(getchar() != '\n');

        //* Load *//
        if(cmd == 'l') {
            printf("\nEnter the file name: ");
            if(fgets(fileName, sizeof(fileName), stdin) != NULL) {
                temp = strchr(fileName, '\n');
                if(temp) {
                    *temp = '\0';
                }
            }
            filePtr = fopen(fileName, "r");
            if(filePtr == NULL) {
                fprintf(stderr, "\nThe specified file, '%s', could not be opened.\n\n", fileName);
            }
            else {
                loadList(mainList, filePtr);
                fclose(filePtr);
                printf("\nThe specified list was successfully loaded from the file '%s'.\n\n", fileName);
            }
        }

        //* Save *//
        else if(cmd == 's') {
            if(!isEmptyDynArr(mainList)) {
                printf("\nEnter the file name: ");
                if(fgets(fileName, sizeof(fileName), stdin) != NULL) {
                    temp = strchr(fileName, '\n');
                    if(temp) {
                        *temp = '\0';
                    }
                }
                filePtr = fopen(fileName, "w");
                if(filePtr == NULL) {
                    fprintf(stderr, "\nThe specified file, '%s', could not be opened.\n\n", fileName);
                }
                else {
                    saveList(mainList, filePtr);
                    fclose(filePtr);
                    printf("\nYour to-do list was successfully saved to the file '%s'.\n\n", fileName);
                }
            }
            else {
                fprintf(stderr, "\nYour to-do list is currently empty.\n\n");
            }
        }

        //* Add *//
        else if(cmd == 'a') {
            printf("\nEnter the task description: ");
            if(fgets(desc, sizeof(desc), stdin) != NULL) {
                temp = strchr(desc, '\n');
                if(temp) {
                    *temp = '\0';
                }
            }
            do {
                printf("\nEnter the task priority (0 - 999): ");
                scanf("%d", &priority);
                if(priority < 0 || priority > 999) {
                    fprintf(stderr, "\nThe specified priority is out of range. Please choose between 0 - 999.\n");
                }
            }
            while(priority < 0 || priority > 999);
            while(getchar() != '\n');
            TaskP newTask = createTask(priority, desc);
            addHeap(mainList, newTask, compare);
            printf("\nThe task, '%s', was successfully added to your to-do list.\n\n", desc);
        }

        //* Get *//
        else if(cmd == 'g') {
            if(!isEmptyDynArr(mainList)) {
                firstTemp = getMinHeap(mainList);
                printf("\nThe first task on the to-do list is '%s'.\n\n", firstTemp->description);
            }
            else {
                fprintf(stderr, "\nYour to-do list is currently empty.\n\n");
            }
        }

        //* Remove *//
        else if(cmd == 'r') {
            if(!isEmptyDynArr(mainList)) {
                firstTemp = getMinHeap(mainList);
                removeMinHeap(mainList, compare);
                printf("\nThe task, '%s', has successfully been removed from your to-do list.\n\n", firstTemp->description);
                free(firstTemp);
            }
            else {
                fprintf(stderr, "\nYour to-do list is currently empty.\n\n");
            }
        }

        //* Print *//
        else if(cmd == 'p') {
            if(!isEmptyDynArr(mainList)) {
                printList(mainList);
            }
            else {
                fprintf(stderr, "\nYour to-do list is currently empty.\n\n");
            }
        }

        //* End *//
        else if(cmd == 'e') {
            printf("\nGoodbye!\n\n");
        }
        else {
            fprintf(stderr, "\nCommand not recognized. Please try again...\n\n");
        }
    }
    while(cmd != 'e');

    //* Delete the List *//
    deleteDynArr(mainList);
    return 0;
}
