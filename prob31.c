#include <stdio.h>

#define VALUE(I, arr) (coins[I] * arr[I])

static const int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
static const int numOf[] = {200, 100, 40, 20, 10, 4, 2, 1};

int ways(int c){

    int curr[8] = {0};
    int count = 0;

    while(curr[7] != 2){
        int v = VALUE(0, curr) + VALUE(1, curr) + VALUE(2, curr) + VALUE(3, curr) + 
                VALUE(4, curr) + VALUE(5, curr) + VALUE(6, curr) + VALUE(7, curr);

        if(c==v)
            count++;

        if(v>c)
            curr[0] = 201;

        for(int i = 0; i < 8; i++){
            curr[i]++;
            
            if(curr[i] > numOf[i])
                curr[i] = 0;
            else
                break;
        }
    }

    return count;
}

int main(){

    printf("%d\n", ways(4));

    return 0;
}