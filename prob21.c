#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(){
    printf("21. Evaluate the sum of all the amicable numbers under 10000.\n");
    
    int *arr = calloc(10000, sizeof *arr), n = 2, prop_aux, sum = 0;

    for(; n < 10000; n++)
        if(!arr[n]){
            prop_aux = sumPropDivisors(n);
            
            if(prop_aux > 1 && prop_aux != n && sumPropDivisors(prop_aux) == n){
                sum += prop_aux + n; arr[n] = arr[prop_aux] = 1;
            }
            else
                arr[n] = 1;
        } 
    
    printf("The sum is %d.\n", sum);
    free(arr);
    return 0;
}