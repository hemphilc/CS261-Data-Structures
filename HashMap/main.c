/* CS261- Assignment 6 - main.c*/
/* Name: Corey Hemphill
 * Date: 11/25/2015
 * Solution description: (none)
 */

#include <assert.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "hashMap.h"


void keyPrint(KeyType k) {
  char *key = (char *)k;
  printf("%s", key);
}


void valPrint(ValueType v) {
  int *val = (int *)v;
  printf("%d", *val);
}

/*
 The getWord function takes a FILE pointer and returns you a string which was
 the next word in the in the file. Words are defined (by this function) to be
 characters or numbers seperated by periods, spaces, or newlines.

 When there are no more words in the input file this function will return NULL.

 This function will malloc some memory for the char* it returns. It is your job
 to free this memory when you no longer need it.
 */
char* getWord(FILE *file);

int main (int argc, const char * argv[]) {
	const char* filename;
	struct hashMap *hashTable;
    int tableSize = 15;
	clock_t timer;
	FILE *fileptr;
//    FILE *fOutPtr = fopen("outputHash2.txt", "w");
    /*
     This part is using command line arguments, you can use them if you wish
     but it is not required. DO NOT remove this code though.

     If you wish not to use command line arguments manually type in your
     filename and path in the else case.
     */
    if(argc == 2) {
        filename = argv[1];
    }
    else {
        filename = "input2.txt"; /* Specify your input text file here */
    }
    printf("opening file: %s\n", filename);
//    fprintf(fOutPtr, "opening file: %s\n", filename);
	timer = clock();
	hashTable = createMap(tableSize);

    /*... Concordance code goes here ...*/
    fileptr = fopen(filename, "r+");
    char *theWord = "word";
    while(theWord != 0) {
        theWord = getWord(fileptr);
        if(theWord != 0) {
            if(containsKey(hashTable, theWord) == 0) {
                ValueType newVal = malloc(sizeof(ValueType));
                *(int*)newVal = 1;
                insertMap(hashTable, theWord, newVal);
                free(newVal);
            }
            else {
                ValueType updateVal = malloc(sizeof(ValueType));
                *(int*)updateVal = *(int*)atMap(hashTable, theWord) + 1;
                insertMap(hashTable, theWord, updateVal);
                free(updateVal);
            }
        }
    }
    free(theWord);
    /*... Concordance code ends here ...*/

    timer = clock() - timer;
    printf("\nconcordance ran in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    printf("Table emptyBuckets = %d\n", emptyBuckets(hashTable));
    printf("Table count = %d\n", size(hashTable));
    printf("Table capacity = %d\n", capacity(hashTable));
    printf("Table load = %f\n", tableLoad(hashTable));
    printf("Deleting keys\n");  
    printf("Removing keys for 'and,' 'me,' and 'the.'\n");
    removeKey(hashTable, "and");
    removeKey(hashTable, "me");
    removeKey(hashTable, "the");

    printMap(hashTable, keyPrint, valPrint);  /* Prints structure of hash table */
    printf("\n\n");
    printKeyValues(hashTable, keyPrint, valPrint); /* Prints all key-value pairs, one pair per line */

    /* Print to file output.txt (for debugging) */
//    fprintf(fOutPtr, "\nconcordance ran in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
//    fprintf(fOutPtr, "Table emptyBuckets = %d\n", emptyBuckets(hashTable));
//    fprintf(fOutPtr, "Table count = %d\n", size(hashTable));
//    fprintf(fOutPtr, "Table capacity = %d\n", capacity(hashTable));
//    fprintf(fOutPtr, "Table load = %f\n", tableLoad(hashTable));
//    fprintf(fOutPtr, "Deleting keys\n");
//    fprintf(fOutPtr, "Removing keys for 'and,' 'me,' and 'the.'\n");

//    printOutputMap(hashTable, fOutPtr);
//    printOutputKeyValues(hashTable, fOutPtr);

/* Test out the iterator */
#ifdef ITERATOR_IN
    struct mapItr *myItr;
    myItr = createMapIterator(hashTable);
    KeyType  key;

    /* Free up our keys and values using our iterator!!  Also printing them as we go along */
    while(hasNextMap(myItr)) {
        key = nextMap(myItr);
        int *value = atMap(hashTable,key);
        printf("Freeing ...Key = %s, value = %d \n", key, *value);
        free(value);  /* To match the malloc above*/
        free(key);
    }
#endif

    deleteMap(hashTable);
	printf("\nDeleted the table\n");
//    fclose(fOutPtr);
	return 0;
}

char* getWord(FILE *file) {
    int length = 0;
    int maxLength = 16;
    char character;
    char* word = malloc(sizeof(char) * maxLength);
    assert(word != NULL);
    while( (character = fgetc(file)) != EOF) {
        character = tolower(character);  /* In should be the same as in ..so force all to lowercase */
        if((length+1) > maxLength) {
            maxLength *= 2;
            word = (char*)realloc(word, maxLength);
        }
        if((character >= '0' && character <= '9') ||   /* Is it a number */
           (character >= 'A' && character <= 'Z') ||   /* Or an uppercase letter */
           (character >= 'a' && character <= 'z') ||   /* Or a lowercase letter */
            character == 39) {                         /* Or an apostrophy */
            word[length] = character;
            length++;
        }
        else if(length > 0) {
            break;
        }
    }
    if(length == 0) {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}
