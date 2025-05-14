#include "primelib.h"

static bool superslow_isprime(int number)
{
    if (number < 2)
        return false;
    int divisor = 2;
    while (divisor < number) {
        if (number % divisor == 0)
            return false;
        divisor += 1;
    }
    return true;
}

bool isprime(int number)
{
    return superslow_isprime(number);
}
    
int count_primes_in_range(int begin, int end)
{
    int count = 0;
    for (int n = begin; n < end; n++)
        if (isprime(n))
            ++count;
    return count;
}
