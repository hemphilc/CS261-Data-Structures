/* CS261- Assignment 6 - hashMap.c*/
/* Name: Corey Hemphill
 * Date: 11/25/2015
 * Solution description: (none)
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "hashMap.h"

struct hashLink {
   KeyType key;             /* The key is what you use to look up a hashLink */
   ValueType value;         /* The value stored with the hashLink, a pointer to int in the case of concordance */
   struct hashLink *next;   /* Notice how these are like linked list nodes */
};

typedef struct hashLink hashLink;

struct hashMap {
    hashLink ** table;      /* Array of pointers to hashLinks */
    int tableSize;          /* Number of buckets in the table */
    int count;              /* Number of hashLinks in the table */
};

typedef struct hashMap hashMap;

/* The first hashing function you can use */
int stringHash1(char *str) {
    int r = (int)(str[2]) + (int)(str[strlen(str) - 1]);
	return r;
}

/* The second hashing function you can use */
int stringHash2(char *str) {
	int i;
	int r = 0;
    for (i = 0; str[i] != '\0'; i++) {
        r += (i + 1) * str[i]; /* The difference between stringHash1 and stringHash2 is on this line */
    }
	return r;
}

/* Initialize the supplied hashMap struct */
void _initMap(struct hashMap * ht, int tableSize) {
	int index;
	if(ht == NULL)
		return;
	ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
	ht->tableSize = tableSize;
	ht->count = 0;
	for(index = 0; index < tableSize; index++)
		ht->table[index] = NULL;
}

/* Allocate memory and initialize a hash map */
hashMap *createMap(int tableSize) {
	assert(tableSize > 0);
	hashMap *ht;
	ht = malloc(sizeof(hashMap));
	assert(ht != 0);
	_initMap(ht, tableSize);
	return ht;
}

/* Free all memory used by the buckets */
void _freeLinks(struct hashLink **table, int tableSize) {
    /* Write This */
    assert(table != 0);
    hashLink *tempLink;
    int i;
    for(i = 0; i < tableSize; i++) {
        while(table[i] != 0) {
            tempLink = table[i];
            table[i] = table[i]->next;
            free(tempLink);
        }
    }
}

/* Deallocate buckets, table, and hashTable structure itself */
void deleteMap(hashMap *ht) {
    assert(ht != 0);
	/* Free all memory used by the buckets */
	_freeLinks(ht->table, ht->tableSize);
    /* Free the array of buckets */
    free(ht->table);
    /* Free the hashMap struct */
	free(ht);
}

/* Resizes the hash table to be the size newTableSize */
void _setTableSize(struct hashMap * ht, int newTableSize) {
    /* Write This */
    assert(ht != 0);
    hashLink **newTable = malloc(sizeof(hashLink *) * newTableSize);
    hashLink *newTempLink;
    hashLink *oldTempLink;
    int countTemp = ht->count;
    int i, index;
    for(i = 0; i < ht->tableSize; i++) {
       oldTempLink = ht->table[i];
       while(oldTempLink != 0) {
           if(HASHING_FUNCTION == 1) {
               index = stringHash1(oldTempLink->key) % newTableSize;
           }
           else {
               index = stringHash2(oldTempLink->key) % newTableSize;
           }
           newTempLink = malloc(sizeof(hashLink *));
           newTempLink->key = oldTempLink->key;
           newTempLink->value = oldTempLink->value;
           newTempLink->next = newTable[index];
           newTable[index] = newTempLink;
           oldTempLink = oldTempLink->next;
       }
    }
    _freeLinks(ht->table, ht->tableSize);
    ht->table = newTable;
    ht->tableSize = newTableSize;
    ht->count = countTemp;
}

/*
 Insert the following values into a hashLink, you must create this hashLink but
 only after you confirm that this key does not already exist in the table. For example, you
 cannot have two hashLinks for the word "taco".

 If a hashLink already exists in the table for the key provided you should
 replace the value for that key.  As the developer, you DO NOT FREE UP THE MEMORY FOR THE VALUE.
 We have to leave that up to the user of the hashMap to take care of since they may or may not
 have allocated the space with malloc.

 Also, you must monitor the load factor and resize when the load factor is greater than
 or equal LOAD_FACTOR_THRESHOLD (defined in hashMap.h).
 */
void insertMap(struct hashMap * ht, KeyType k, ValueType v) {
    /* Write This */
    assert(ht != 0);
    int index;
    if(HASHING_FUNCTION == 1) {
        index = stringHash1(k) % ht->tableSize;
    }
    else {
        index = stringHash2(k) % ht->tableSize;
    }
    hashLink *tempLink = ht->table[index];
    if(containsKey(ht, k) == 1) {
        while(strcmp(tempLink->key, k) != 0 && tempLink->next != NULL) {
            tempLink = tempLink->next;
        }
        tempLink->value = v;
    }
    else {
        hashLink *newLink = malloc(sizeof(hashLink *));
        newLink->key = k;
        newLink->value = v;
        newLink->next = NULL;
        if(ht->table[index] == NULL) {
            ht->table[index] = newLink;
        }
        else {
            while(tempLink->next != NULL) {
                tempLink = tempLink->next;
            }
            tempLink->next = newLink;
        }
        ht->count++;
        //if(tableLoad(ht) >= LOAD_FACTOR_THRESHOLD) {
        //    _setTableSize(ht, (ht->tableSize * 2));
        //}
    }
}

/*
 This returns the value (which is void*) stored in a hashLink specified by the key k.

 If the user supplies the key "taco" you should find taco in the hashTable, then
 return the value member of the hashLink that represents taco.

 If the supplied key is not in the hashtable, return NULL.
 */
ValueType atMap(struct hashMap * ht, KeyType k) {
    /* Write This */
    assert(ht != 0);
    int index;
    if(HASHING_FUNCTION == 1) {
        index = stringHash1(k) % ht->tableSize;
    }
    else {
        index = stringHash2(k) % ht->tableSize;
    }
    hashLink *tempLink = ht->table[index];
    while(tempLink != 0) {
        if(strcmp(tempLink->key, k) == 0) {
            return tempLink->value;
        }
        tempLink = tempLink->next;
    }
    return 0;
}

/*
 A simple yes/no if the key is in the hashtable.
 0 is no, all other values are yes.
 */
int containsKey(struct hashMap * ht, KeyType k) {
    /* Write This */
    assert(ht != 0);
    int index;
    if(HASHING_FUNCTION == 1) {
        index = stringHash1(k) % ht->tableSize;
    }
    else {
        index = stringHash2(k) % ht->tableSize;
    }
    hashLink *tempLink = ht->table[index];
    while(tempLink != 0) {
        if(strcmp(tempLink->key, k) == 0) {
            return 1;
        }
        tempLink = tempLink->next;
    }
	return 0;
}

/*
 Find the hashlink for the supplied key and remove it, also freeing the memory
 for that hashlink. It is not an error to be unable to find the hashlink, if it
 cannot be found do nothing (or print a message) but do not use an assert which
 will end your program.
 */
void removeKey(struct hashMap * ht, KeyType k) {
    /* Write This */
    assert(ht != 0);
    int index;
    if(HASHING_FUNCTION == 1) {
        index = stringHash1(k) % ht->tableSize;
    }
    else {
        index = stringHash2(k) % ht->tableSize;
    }
    hashLink *tempLink = ht->table[index];
    hashLink *tempRemoveLink;
    if(containsKey(ht, k) == 1) {
        if(strcmp(ht->table[index]->key, k) == 0) {
            tempRemoveLink = ht->table[index];
            ht->table[index] = ht->table[index]->next;
            free(tempRemoveLink->key);
            free(tempRemoveLink->value);
            free(tempRemoveLink);
            ht->count--;
            return;
        }
        else {
            while(tempLink->next != NULL) {
                if(strcmp(tempLink->next->key, k) == 0) {
                    tempRemoveLink = tempLink->next;
                    tempLink->next = tempLink->next->next;
                    free(tempRemoveLink->key);
                    free(tempRemoveLink->value);
                    free(tempRemoveLink);
                    ht->count--;
                    return;
                }
                tempLink = tempLink->next;
            }
        }
    }
    else {
        printf("The specified key is not in the table.\n");
    }
}

/* Returns the number of hashLinks in the table */
int size(struct hashMap *ht) {
    /* Write This */
    assert(ht != 0);
    return ht->count;
}

/* Returns the number of buckets in the table */
int capacity(struct hashMap *ht) {
    /* Write This */
    assert(ht != 0);
    return ht->tableSize;
}

/*
 Returns the number of empty buckets in the table, these are buckets which have
 no hashlinks hanging off of them.
 */
int emptyBuckets(struct hashMap *ht) {
    /* Write This */
    assert(ht != 0);
    int emptyCount = 0;
    int i;
    for(i = 0; i < ht->tableSize; i++) {
        if(ht->table[i] == 0) {
            emptyCount++;
        }
    }
    return emptyCount;
}

/*
 Returns the ratio of: (number of hashlinks) / (number of buckets)

 This value can range anywhere from zero (an empty table) to more then 1, which
 would mean that there are more hashlinks then buckets (but remember hashlinks
 are like linked list nodes so they can hang from each other).
 */
float tableLoad(struct hashMap *ht) {
    /* Write This */
    assert(ht != 0);
    float theLoad = (float)ht->count/ht->tableSize;
    return theLoad;
}

/* Print the hashMap */
void printMap(struct hashMap * ht, keyPrinter kp, valPrinter vp) {
	int i;
	struct hashLink *temp;
    for(i = 0; i < capacity(ht); i++) {
		temp = ht->table[i];
        if(temp != 0) {
            printf("\nBucket Index %d -> ", i);
        }
        while(temp != 0){
            printf("Key: ");
            (*kp)(temp->key);
            printf(" | Value: ");
            (*vp)(temp->value);
            printf(" -> ");
            temp = temp->next;
        }
    }
}

/* Print the keys/values ..in linear form, no buckets */
void printKeyValues(struct hashMap * ht, keyPrinter kp, valPrinter vp) {
    int i;
    struct hashLink *temp;
    for(i = 0; i < capacity(ht); i++) {
        temp = ht->table[i];
        while(temp != 0) {
            (*kp)(temp->key);
            printf(":");
            (*vp)(temp->value);
            printf("\n");
            temp = temp->next;
        }
    }
}

/////////////////// Print to File Functions ///////////////////

///* Print to file output.txt (for debugging) */
//void printOutputMap(struct hashMap * ht, FILE *ptr) {
//    int i;
//    struct hashLink *temp;
//    for(i = 0; i < capacity(ht); i++) {
//        temp = ht->table[i];
//        if(temp != 0) {
//            fprintf(ptr, "\nBucket Index %d -> ", i);
//        }
//        while(temp != 0){
//            fprintf(ptr, "Key: %s ", (temp->key));
//            fprintf(ptr, "| Value: %d", *(int*)(temp->value));
//            fprintf(ptr, " -> ");
//            temp = temp->next;
//        }
//    }
//    fprintf(ptr, "\n\n");
//}

///* Print to file output.txt (for debugging) */
//void printOutputKeyValues(struct hashMap *ht, FILE *ptr) {
//    int i;
//    struct hashLink *temp;
//    for(i = 0; i < capacity(ht); i++) {
//        temp = ht->table[i];
//        while(temp != 0) {
//            fprintf(ptr, "%s : ", (temp->key));
//            fprintf(ptr, "%d\n", *(int*)(temp->value));
//            temp = temp->next;
//        }
//    }
//}
