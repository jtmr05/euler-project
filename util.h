#ifndef UTIL_H
#define UTIL_H

#include <math.h>

/**
 * Check if an unsigned long n is a prime number
 */
int isPrime(const unsigned long n);

/**
 * Check if an int n is a prime number
 */
int isPrimeInt(const int n);

/**
 * Updates the value pointed by ptr to the next prime
 */
void nextPrime(unsigned long* ptr);

/**
 * Calculates the number of divisors of n
 */
int numDivisors(const unsigned long n);

/**
 * Caculates the sum of the proper divisors of n
 */
int sumPropDivisors(const int n);

#endif //UTIL_H