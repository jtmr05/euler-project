#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* String;
#define MutString(v) char v[]


void swap(String v, int i, int j){
    char temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void perm(String v, String *a, int* N, int len){
    
    const int l = strlen(v);

    if(l==1){
        a[*N] = malloc(sizeof *a[*N] * (len+1));
        strcpy(a[*N], v-len+1);
        (*N)++;
    }
    else
        for (int i = 0; i < l; i++){
            swap(v, 0, i);
            perm(v+1, a, N, len);
            swap(v, 0, i);
        }
}

int comparator(const void *ptr1, const void *ptr2){
    const String *s1 = (const String *) ptr1;
    const String *s2 = (const String *) ptr2;
    return strcmp(*s1, *s2);
}

int main(){
    printf("24. What is the millionth lexicographic permutation of \
the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?\n");

    String *a = calloc(3628800, sizeof *a); //10!
    MutString(v) = "0123456789";
    
    int ind = 0;

    perm(v, a, &ind, strlen(v));
    qsort(a, ind, sizeof *a, comparator);

    printf("The millionth lexicographic is %s.\n", a[999999]);
    
    for(int i = 0; i<3628800; i++)
        free(a[i]);
    free(a);
    return 0;
}