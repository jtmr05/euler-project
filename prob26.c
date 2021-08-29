#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int recurrC(int d, int *occurr){

    int div = 10, count = 0;

    while(!(d % 2)) d /= 2;
    while(!(d % 5)) d /= 5;

    while(d > div) div *= 10;

    while(div && !occurr[div]){
        occurr[div] = 1;
        div = div % d;
        div *= 10;
        count++;
    }

    count = div ? count : 0;

    return count;
}

int main(){
    printf("26. Find the value of d < 1000 for which 1/d contains the longest \
recurring cycle in its decimal fraction part.\n");

    int curr, max = -1, ans, d, *occurr = malloc(sizeof *occurr * 10000);

    for(d = 1; d < 1000; d++){
        memset(occurr, 0, sizeof *occurr * 10000);
        curr = recurrC(d, occurr);
        ans = (curr > max) ? d : ans;
        max = (curr > max) ? curr : max;
    }

    printf("For d = %d, 1/d has a %d-digit recurring cycle.\n", ans, max);
    free(occurr);
    return 0;
}