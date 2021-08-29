#include <stdio.h>
#include <stdlib.h>
#include "util.h"

#define LIM 28123 //any number greater than this CAN be written
                  //as the sum of two abudant numbers

int main(){
    printf("23. Find the sum of all the positive integers which cannot \
be written as the sum of two abundant numbers.\n");

    size_t SIZE = 100, N = 0, sumNat = 0, sumAbund = 0;
    uint i, j, *abundNums = malloc(sizeof *abundNums * SIZE),
               *isSumOf = calloc(LIM + 1, sizeof *isSumOf);

    for(i = 0; i <= LIM; sumNat += i, i++){

        if(N==SIZE){
            SIZE *= 2;
            abundNums = realloc(abundNums, sizeof *abundNums * SIZE);
        }

        if(i < (uint) sumPropDivisors(i)){
            abundNums[N++] = i;
            
            for(j=0; j<N; j++){
                uint aux = abundNums[j] + i;
                if(aux <= LIM && !isSumOf[aux]){
                    isSumOf[aux] = 1;
                    sumAbund += aux;
                }
            }
        }
    }

    printf("The sum is %lu.\n", (sumNat - sumAbund));
    free(isSumOf);
    free(abundNums);
    return 0;
}