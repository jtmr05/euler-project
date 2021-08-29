#include <stdio.h>

int main(){
	printf("6. Find the difference between the sum of the squares \
of the first 100 naturals and the square of the sum.\n");
	size_t sumsq=0, sqsum=0, answer;

	for(int i=1; i<101; i++){
		sumsq += (i*i);
		sqsum += i;
	}
    
	sqsum = sqsum * sqsum;
	answer = sqsum - sumsq;

	printf("%lu is the sum of the squares and %lu the square of the \
sum.\nThe difference is %lu.\n", sumsq, sqsum, answer);

	return 0;
}