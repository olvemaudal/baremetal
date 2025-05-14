#include "primelib.h"

#include <assert.h>
#include <stdio.h>

int main()
{
    assert(isprime(0) == false);
    assert(isprime(1) == false);
    assert(isprime(2) == true);
    assert(isprime(3) == true);
    assert(isprime(4) == false);
    assert(isprime(5) == true);
    assert(count_primes_in_range(0,10) == 4);
    assert(count_primes_in_range(2,10) == 4);
    assert(count_primes_in_range(10,20) == 4);
    assert(count_primes_in_range(11,19) == 3);
    assert(count_primes_in_range(1,20) == 8);
    assert(count_primes_in_range(1000,2000) == 135);

    fprintf(stderr, "All tests passed\n");
    return 0;
}
