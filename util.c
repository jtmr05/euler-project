#include "util.h"

int isPrime(const unsigned long n){
    
    for(unsigned long i=2; i<=n/2; i++)
        if(!(n%i))
            return 0;
            
    return 1;
}

int isPrimeInt(const int n){

    if(n<=0)
        return 0;
    
    for(int i=2; i<=n/2; i++)
        if(!(n%i))
            return 0;
            
    return 1;
}

void nextPrime(unsigned long* n){

    if((*n)==2) 
        (*n)++;

    else{
        
        do{
            (*n)+=2;
        } while(!isPrime(*n));
    }
}


int numDivisors(const unsigned long n){
    int count;

    if(n!=1){
        count = 0;
        double end = sqrt(n);
        for(unsigned long i=1; i<end; i++)
            if(!(n%i))
                count+=2;
                
        int end_ = (int) end;

        if(end_*end_ == n)
            count++;
    }
    else
        count = 1;

    return count;
}

int sumPropDivisors(const int n){
    int sum = 0;

    if(n!=1){
        double end = sqrt(n);
        for(int i=1; i<end; i++)
            if(!(n%i))
                sum += i + (n/i);
                
        int end_ = (int) end;

        if(end_*end_ == n)
            sum += end_;
        sum -= n;
    }
    
    return sum;
}
