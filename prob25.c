#include <stdio.h>

int main(){
    printf("What is the index of the first term in the \
Fibonacci sequence to contain 1000 digits?\n");

    int i, j, aux, ptr = 999, f1[1000] = {0}, fN[1000] = {0};

    f1[999] = fN[999] = 1;

    for(i=2; fN[0] == 0; i++){
        for(j=999; j >= ptr; j--){
            fN[j] += f1[j];
            f1[j] = fN[j] - f1[j];
        }

        for(j=999; j > 0; j--){
            if(fN[j]){              /* The sums may "overflow" 9 on each index */
                ptr = j-1;
                aux = (fN[j]/10);
                fN[j] -= (aux*10);
                fN[j-1] += aux;
            }
        }
    } 
    printf("The index is %d.\n", i);
    return 0;
}