#ifndef __HASH
#define __HASH

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

typedef struct node *NODE;

/**
 * Set the SIZE variable.
 */
void setSIZE(size_t s);

/**
 * Create a new empty hash table.
 */
NODE* init();

/**
 * Insert a new key into the hash table h. Returns 1 if key was already present.
 */
int insertHash (const int key, NODE* h);


/**
 * Check if h contains the specified key
 */
int searchHash (const int key, NODE* h);

/**
 * Free the specified hash table with a SIZE of factor f
 */
void freeHash(NODE* h, uint f);

#endif //__HASH
