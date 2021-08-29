#include <stdio.h>

#define ONE 3
#define TWO 3
#define THREE 5
#define FOUR 4
#define FIVE 4
#define SIX 3
#define SEVEN 5
#define EIGHT 5
#define NINE 4
#define TEN 3
#define ELEVEN 6
#define TWELVE 6
#define THIRTEEN 8
#define FOURTEEN 8
#define FIFTEEN 7
#define SIXTEEN 7
#define SEVENTEEN 9
#define EIGHTEEN 8
#define NINETEEN 8
#define TWENTY 6
#define THIRTY 6
#define FORTY 5
#define FIFTY 5
#define SIXTY 5
#define SEVENTY 7 
#define EIGHTY 6
#define NINETY 6
#define HUNDRED 7
#define THOUSAND 8
#define AND 3

int main(){
    printf("If all the numbers from 1 to 1000 inclusive were written out in words, \
how many letters would be used?\n");
    
    int count = 
            //1000
            ONE + THOUSAND +

            //there are 10 hundreds and in each 10 occurences of each one
            10 * 10 * (TWENTY + THIRTY + FORTY + FIFTY + SIXTY + SEVENTY + EIGHTY + NINETY) +

            //there are 10 hundreds and in each 9 of each one (e.g. 13 doesn't count, 33 does)
            10 * 9 * (ONE + TWO + THREE + FOUR + FIVE + SIX + SEVEN + EIGHT + NINE) +
            
            //100 .. 999
            9 * 100 * HUNDRED + 

            //N hundred
            100 * (ONE + TWO + THREE + FOUR + FIVE + SIX + SEVEN + EIGHT + NINE) +
            
            //100 .. 999, minus X00
            (900 - 9) * AND +

            //there are 10 hundreds and in each 1 occurences of each one
            10 * (TEN + ELEVEN + TWELVE + THIRTEEN + FOURTEEN + FIFTEEN + SIXTEEN + SEVENTEEN +
                  EIGHTEEN + NINETEEN)
    ;

    printf("%d letters would be used.\n", count);
}