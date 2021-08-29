#include <stdio.h>
#include "util.h"

int main(){
    // -1000 < a < 1000 and -1000 <= b <= 1000

    printf("27. Find the product of the coefficients, a and b, for the quadratic \
expression that produces the maximum number of primes for consecutive values of n, \
starting with 0.\n");

    int a = -999, b = -1000, ansA = 0, ansB = 0, n, max = 0;

    for(; a < 1000; b++){
        if(b > 1000){
            a++;
            b = -1000;
        }

        for(n = 0; isPrimeInt(n*n + a*n + b); n++);
        ansA = (n > max) ? a : ansA;
        ansB = (n > max) ? b : ansB;
        max =  (n > max) ? n : max;
    }
    printf("For a = %d and b = %d, the longest sequence of consecutive primes is produced. \
%d is their prodcut.\n", ansA, ansB, ansA * ansB);

    return 0;
}