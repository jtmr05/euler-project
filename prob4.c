#include <stdio.h>

int isPalindrome(int n){
    // The largest number that is the product of two 3-digit numbers has 6 digits (plus '\0')
	char str[7];
	snprintf(str, 7, "%d", n); 

	int i=0;
	for(; i<3 && *(str+i)==*(str+6-i-1); i++);
	
    return (i==3);
}

int main(){
	printf("4. Find the largest palindrome made from the product of two 3-digit numbers.\n");
	int a, b, n, max=0;
	a = 999;
	b = 1000;

     
	do{
		if(b>100)
			b--;
		else{
			a--;
			b = 999;
		}

		n = a*b;
		if(isPalindrome(n))
			max = (n>max) ? n : max;

	} while(a>100);

	printf("%d is the largest palindrome\n", max);
	return 0;
}