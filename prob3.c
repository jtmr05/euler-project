#include <stdio.h>
#include "util.h"

int main(){
	printf("3. What is the largest prime factor of the number 600851475143?\n");
	size_t n = 600851475143, div=2, acc;

	for(; n!=1; nextPrime(&div))
		if(!(n%div)){
			n/= div;
			acc=div;
		}
	
	printf("%lu is the largest prime factor of 600851475143.\n", acc);
	return 0;
}