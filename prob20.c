#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("20. Find the sum of the digits in the number 100!.\n");

    /* If we consider that between 1 and 100 most numbers have two digits,
     * at most we need ceiling(log_10(99^100)) = 200 digits to represent 100!
    */

    int *arr = calloc(200, sizeof *arr), i, j, ptr = 199, aux;
    arr[199] = 1;

    for(i=2; i<100; i++){
        for(j=199; j >= ptr; j--)
            arr[j] *= i;

        for(j=199; j > 0; j--){
            if(arr[j]){
                ptr = j-1; 
                aux = (arr[j]/10);
                arr[j] -= (aux*10);
                arr[j-1] += aux;
            }
        }
    }

    size_t count = 0;
    for(i=199; i>=0; i--)
        count += arr[i];


    printf("The sum is %lu.\n", count);
    free(arr);
    return 0;
}