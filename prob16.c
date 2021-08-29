#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("16. Find the sum of the digits of the number 2^1000\n");
    
    //ceiling log_10(2^1000) = 302 => number of digits needed to represent 2^1000
    int *arr = calloc(302, sizeof *arr);
    arr[301] = 1;

    int aux, i, j, ptr = 301;
    
    for(i = 0; i < 1000; i++){

        for(j = 301; j >= ptr; j--)
            arr[j] *= 2;
        
        for(j = 301; j > 0; j--)
            if(arr[j]){
                ptr = j-1; 
                aux = (arr[j]/10);
                arr[j] -= (aux*10);
                arr[j-1] += aux;
            }
    }

    size_t count = 0;
    for(i=0; i<302; i++)
        count += arr[i];

    printf("The sum is %lu.\n", count);
    free(arr);
    return 0;
}