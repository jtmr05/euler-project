#include <stdio.h>

#define SPIRAL_SIZE 1001

/**
 * i describes the size of the current spiral
 * it's easy to observe that on the same spiral, the difference between corner numbers
 * is equal to i-1
 */

int main(){
    printf("28. What is the sum of the numbers on the diagonals in a 1001 by 1001 \
spiral formed in the same way?\n");

    long sum = 1;
    int next = 3;

    for(int i = 3; i <= SPIRAL_SIZE; i += 2){
        sum += 4*next + (i-1) * (1+2+3);
        next += (i-1) * 3 + (i-1) + 2;
    }

    printf("The sum of the diagonals is %ld.\n", sum);
}