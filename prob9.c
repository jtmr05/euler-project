#include <stdio.h>
#include <math.h>

int main(){
	printf("9. There exists exactly one Pythagorean triplet for which a + b + c = 1000. \
Find the product abc.\n");
	int a, b, c, answer;
	a=1, b=1;

	while((a + b + sqrt(a*a + b*b)) != 1000)
		if(b>1000){
			a++;
			b=a+1;
		}
		else
			b++;
	
	c = sqrt(a*a + b*b);
	answer = c*b*a;
	printf("%d is the product of %d, %d and %d.\n", answer, a, b, c);
	return 0;
}