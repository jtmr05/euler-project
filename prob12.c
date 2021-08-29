#include <stdio.h>
#include "util.h"


int main(){
	printf("12. What is the value of the first triangle number to have over \
five hundred divisors?\n");
	size_t n=0, i=1;

	do{
		n+=i;
		i++;
	} while(numDivisors(n)<501);

	printf("The value is %lu.\n", n);
	return 0;
}