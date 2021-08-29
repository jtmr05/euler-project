#include <stdio.h>
#include "util.h"

int main(){
	printf("15. How many routes are there to the bottom right corner moving only right \
and down through a 20×20 grid?\n");

	//20x20 grid -> 40 moves needed
	//Hence, 40! different routes
	//We need to factor out different permutations that produce the same route
	//Since we need 20 DOWNS and 20 RIGHTS, we'll divide 40! by 20!×20!
    //This is equivalent to 40×39×38...21 / 20!

	//Prime numbers under 40 -> {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}
	//occurr will contain number of occurrences of corresponding prime

	int occurr[12] = {0};
	int n, i, j;
	size_t p, count=1;

	for(i=21; i<=40; i++){
		n=i; p=2; j=0;

		while(n!=1){
			if(!(n%p)){
				n/=p;
				occurr[j]++;
			}
			else{
				nextPrime(&p);
				j++;
			}
		}
	}

	for(i=2; i<=20; i++){
		n=i; p=2; j=0;

		while(n!=1){
			if(!(n%p)){
				n/=p;
				occurr[j]--;
			}
			else{
				nextPrime(&p);
				j++;
			}
		}
	}

	p=2;
	for(i=0; i<12; i++){
		count *= pow(p, occurr[i]);
		nextPrime(&p);
	}

	printf("There are %lu routes.\n", count);
	return 0;
}
