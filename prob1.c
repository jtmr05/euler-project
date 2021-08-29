#include <stdio.h>

int main(){
	printf("1. Find the sum of all the multiples of 3 or 5 below 1000.\n");

	int i=3, count=0;

	for(; i<1000; i++)
		if(!(i%5 && i%3))
			count+=i;

	printf("Sum = %d\n", count);
	return 0;
}