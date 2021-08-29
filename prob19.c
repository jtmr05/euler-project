#include <stdio.h>

int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
    printf("19. How many Sundays fell on the first of the month during the twentieth century \
(1 Jan 1901 to 31 Dec 2000)?\n");

    int day = 37, month, year, count = 0; //last Sunday of 1900 (30/12) plus 7 days

    for(year = 1901; year < 2001; year++){
        
        months[2] = (!(year % 4)) ? 29 : 28;
        for(month = 1; month < 13; month++){

            day -= (month == 1) ? months[12] : months[month - 1];

            for(; day < months[month] + 1; day +=7)
                count = (day==1) ? count + 1 : count;
        }
    }
    printf("There were %d Sundays that fell on the first of the month.\n", count);
    return 0;
}