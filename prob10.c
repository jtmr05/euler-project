#include <stdio.h>
#include <stdlib.h>

/*
int main(){
	printf("10. Find the sum of all the primes below two million.\n");
	int arr[1000000], i, n, j;
	size_t count=0;

	*arr = 2;
	*(arr+1) = 3;

	for (i = 2; i < 1000000; ++i)
		*(arr+i) = *(arr+i-1) + 2;
	
	n = *(arr+1);
	for(i=1; n <= 1415; i++){
		n = *(arr+i);
		
		if(n){
			for(j=i+1; j<1000000; ++j)
				if (!(arr[j]%n))
					arr[j] = 0;
		}
	}

	for(i=0; i < 1000000; ++i)
		count += *(arr+i);

	printf("The sum is %lu.\n", count); 
	return 0;
} */

//optimized
int main(){
	printf("10. Find the sum of all the primes below two million.\n");
	int *arr, i, j;
	size_t count=0;

    arr = malloc(sizeof *arr * 2000000);
    if(!arr){
        perror("Failed to alloc memory");
        return -1;
    }

	//index matches element
	for (i = 2; i < 2000000; ++i)
		arr[i] = i;
    i=2;

    //primes are calculated using the Sieve of Eratosthenes
    //while eliminating non-primes each iteration, count is also accumulating the partial answer
	//ceiling (sqrt(2000000)) = 1415
	do{
		if(arr[i])
			for(j=i*i; j<2000000; j+=i)
					arr[j] = 0;

        count += arr[i];
		i = (i==2) ? 3 : i+2;

	} while(arr[i] < 1415);

    //sum the rest of the primes
	for(i=1417; i < 2000000; i+=2)
		count += arr[i];

	printf("The sum is %lu.\n", count);

    free(arr);
	return 0;
}