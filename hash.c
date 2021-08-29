#include "hash.h"

#define HASHFUNC(K) (K % SIZE)

static size_t SIZE = 20;

struct node{
    int key;
    struct node *next;
};

void setSIZE(size_t s){
    SIZE = s;
}

NODE* init(){
    NODE* new = malloc(sizeof *new * SIZE);
    if(!new){
        perror("Failed to alloc memory");
        exit (-1);
    }

    for(uint i=0; i<SIZE; i++)
        new[i] = NULL;

    return new;
}

/* NODE* rehash(NODE* hash){
    SIZE *= 2;
    
    uint i;
    NODE* new = init(), temp;

    for(i=0; i < SIZE/2; i++){
        temp = hash[i];
        while(temp){
            insertHash(temp->key, new);
            temp = temp->next;
        }
    }
    freeHash(hash, 2);
    return new;
} */

int insertHash (const int key, NODE* h){
    int ind = HASHFUNC(key), flag = 0;

    NODE new = malloc(sizeof *new);
    if(!new){
        printf("Failed to alloc memory\n");
        exit(-1);
    }
    new->key = key;
    new->next = NULL; 

    //empty or collision
    if(!h[ind])
        h[ind] = new;
    else{
        NODE temp = h[ind];
        
        for(; (flag = (temp->key - key)) && temp->next; temp = temp->next);

        //if flag is not 0 at the end of the while-loop, no matching key was found
        if(flag)
            temp->next = new;
        else
            free(new);

        flag = flag == 0;
    }
    return flag;
}

int searchHash (const int key, NODE* h){
    int ind = HASHFUNC(key), flag = 0;
    NODE temp = h[ind];

    for(; temp && !flag; temp = temp->next)
        flag = key == temp->key;
    
    return flag;
}

static void freeNode(NODE n){
    if(!n) return;
    freeNode(n->next);
    free(n);
}

void freeHash(NODE* h, uint factor){    
    uint i;
    NODE temp;
    
    for(i=0; i < SIZE/factor; i++){
        temp = h[i];
        freeNode(temp);
    }
    free(h);
}
