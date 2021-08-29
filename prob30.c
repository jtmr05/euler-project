#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	printf("30. Find the sum of all the numbers that can be written as \
the sum of fifth powers of their digits.\n");

	/** for a number with 7 digits
	 *  the maximum sum of fifth powers of such numbers' digits is 413343
	 *  that is, for n = 9.999.999 -> 9^5 * 7 = 413343
	 *  so, the limit for curr is 6 digit numbers
	 */

	char str[7];
	uint curr = 10, sum = 0, partSum, count = 0;

	for(; curr < 1000000; curr++){

		//failed attempt at suppressing compiler warnings
		snprintf(str, sizeof str, "%0*u", 6, (unsigned)curr%1000000u);

		partSum = pow(str[0] - '0', 5) + pow(str[1] - '0', 5) +
		          pow(str[2] - '0', 5) + pow(str[3] - '0', 5) +
		          pow(str[4] - '0', 5) + pow(str[5] - '0', 5);

		if(partSum==curr){
			sum += curr;
			count++;
		}
	}

	printf("There are %u such numbers. The sum is %u.\n", count, sum);
	return 0;
}