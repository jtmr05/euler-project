#include <stdio.h>

int main(){
	printf("2. Find the sum of the even-valued terms (under 4.000.000) \
of the Fibonacci sequence.\n");

	int u1, u2, u3, count=0;
	u1=u2=1;

	do{
		u3 = u1+u2;
		u1 = u2;
		u2 = u3;
		if(!(u3 % 2))
			count+=u3;
	} while(u3<4000000);

	printf("Sum = %d\n", count);
	return 0;
}