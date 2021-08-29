#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("14. Which starting number, under 1.000.000, produces the longest Collatz sequence?\n");

	size_t i, n, count=1, max=0, ptr;
	int *arr = calloc(1000000, sizeof *arr);

	for(i=999999; i>1; i--){
		count=1;
		n=i;

		if(!arr[n]){  //if we already visited this number, we skip it
			while(n!=1){
				if (n<1000000)
					arr[n] = 1;

				if(!(n%2))
					n/=2;
				else
					n=(n*3)+1;

				count++;
			}

			if (count>max){
				max=count;
				ptr=i;
			}
		}
	}

	printf("%lu produces a sequence with %lu terms.\n", ptr, max);
	free(arr);
	return 0;
}