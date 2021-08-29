#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char* String;

String* parse(String s, size_t SIZE, size_t* nmemb){

    size_t i;
    String* ret = malloc(sizeof *ret * SIZE), aux;

    for(i=0; i<=SIZE && *s; i++){
        if(i==SIZE){
            SIZE *= 2;
            ret = realloc(ret, sizeof *ret * SIZE);
        }
        s++; //skip the first '"'
        if(*s){
            aux = strchr(s, '"');
            if(aux){
                ret[i] = malloc(sizeof *ret[i] * (size_t) (aux-s+1));
                strncpy(ret[i], s, (size_t) (aux-s));
                ret[i][aux-s] = '\0';
                s = aux + 2;
            }
            else 
                break;
        }
    }
    *nmemb = i;
    return ret;
}

int comparator(const void *ptr1, const void *ptr2){
    const String *s1 = (const String *) ptr1;
    const String *s2 = (const String *) ptr2;
    return strcmp(*s1, *s2);
}

size_t alphaToNum(String s){
    size_t sum = 0;
    for(; *s; s++)
        sum += (size_t) (*s - 64);
    return sum;
}

int main(){
    printf("22. What is the total of all the name scores in the file?\n");

    FILE *names = fopen("names.txt", "r");
    if(!names){
        perror("Failed to open file");
        return -1;
    }
    
    String buffer = NULL; size_t temp = 0;
    if(!getline(&buffer, &temp, names)){
        perror("Error reading file");
        fclose(names);
        return -2;
    }

    size_t SIZE = 200;
    String *list = parse(buffer, SIZE, &SIZE); 
    
    qsort(list, SIZE, sizeof *list, comparator);

    size_t count = 0;
    for(uint i=0; i < SIZE; i++){
        count += (i+1) * alphaToNum(list[i]);
        free(list[i]);
    }

    printf("The total of all the name scores in the file is %lu.\n", count);
    free(list);
    free(buffer);
    fclose(names);
    return 0;
}