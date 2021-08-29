#include <stdio.h>
#include "util.h"

int main(){
	printf("7. What is the 10001st prime number?\n");
	size_t n=2;

	for(int i=1; i<10001; i++)
		nextPrime(&n);
	
	printf("%lu is the 10001st prime number.\n", n);
	return 0;
}