/* CS261- Assignment 6 - hashMap.h*/
/* Name: Corey Hemphill
 * Date: 11/25/2015
 * Solution description: (none)
 */

# ifndef HashMap
# define HashMap

# define KeyType char*
# define ValueType void*

typedef void (*keyPrinter)(KeyType key);
typedef void (*valPrinter)(ValueType val);

/*
 This is useful for you in answering the questions. If your write your code such
 that you call stringHash1 when (HASHING_FUNCTION == 1) and stringHash2 when
 (HASHING_FUNCTION == 2), then you only need to change this value in order to switch
 hashing functions that your code uses. You are not required to use this value
 though.
 */
# define HASHING_FUNCTION 1

/* Load factor threshold for resizing the hash table */
# define LOAD_FACTOR_THRESHOLD 0.75

int stringHash1(char *str);
int stringHash2(char *str);
struct hashMap *createMap(int tableSize);
void deleteMap(struct hashMap *ht);
void insertMap(struct hashMap * ht, KeyType k, ValueType v);
ValueType atMap(struct hashMap * ht, KeyType k);
int containsKey(struct hashMap * ht, KeyType k);
void removeKey(struct hashMap * ht, KeyType k);
int size(struct hashMap *ht);
int capacity(struct hashMap *ht);
int emptyBuckets(struct hashMap *ht);
float tableLoad(struct hashMap *ht);
void printMap(struct hashMap * ht, keyPrinter kp, valPrinter vp);
void printKeyValues(struct hashMap *ht, keyPrinter kp, valPrinter vp);

/* For printing to output.txt (for debugging) */
//void printOutputMap(struct hashMap * ht, FILE *ptr);
//void printOutputKeyValues(struct hashMap *ht, FILE *ptr);

/* Iterator Interface */
struct mapItr *createMapIterator(struct hashMap *ht);
void initMapIterator(struct hashMap *ht, struct mapItr *itr);
int hasNextMap(struct mapItr *itr);
KeyType nextMap(struct mapItr *itr);

# endif
