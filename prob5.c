#include <stdio.h>
//#include <math.h>
//#include "util.h"

int main(){
	printf("5. What is the smallest natural that is evenly divisible by all of \
the numbers from 1 to 20?\n");
	int arr[19], count=1, i, j;

	for(i=0; i<19; i++)
		arr[i] = i+2;
	
    //This guarantees we're only multipling count by prime numbers on each iteration 
	for(i=0; i<19; i++){
		count*=arr[i];
		for(j=i+1; j<19; j++)
			if(!(arr[j] % arr[i]))
				arr[j] /= arr[i];
	}

/*  An alternative is using only prime numbers and checking how many 
    of each "fit" in the number 20
	
    int count=1, n=2, aux;

	while(n<20){
		aux = log(20) / log(n);
		count*=pow(n, aux);
		nextPrime(&n);
	} 
*/

	printf("%d is the smallest natural that is evenly divisible by \
all of the numbers from 1 to 20.\n", count);

	return 0;
}