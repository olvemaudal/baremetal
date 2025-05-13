#include "primelib.h"

#include <stdio.h>

int main(void)
{
    int lower_bound = 4000;
    int upper_bound = 5000;

    printf("Number of primes in range [%d, %d) is ", lower_bound, upper_bound);
    fflush(stdout);

    int number_of_primes = count_primes(lower_bound, upper_bound);

    printf("%d\n", number_of_primes);

    return 0;
}
