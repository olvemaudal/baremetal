#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

static bool is_divisible(int numerator, int denominator) {
    return numerator % denominator == 0;
}

static bool isprime(int number)
{
    if (number < 2)
        return false;
    int denominator = 2;
    while (denominator < number) {
        if (is_divisible(number, denominator))
            return false;
        denominator += 1;
    }
    return true;
}

static int count_primes_in_range(int begin, int end)
{
    int count = 0;
    for (int n = begin; n < end; n++) 
        if (isprime(n))
            count++;
    return count;
}

int main(void)
{
    assert(1 + 2 == 3);
    assert(isprime(3) == true);
    assert(isprime(4) == false);
    assert(isprime(5) == true);
    assert(isprime(2) == true);
    assert(isprime(1) == false);
    assert(count_primes_in_range(0,10) == 4);
    assert(count_primes_in_range(0,20) == 8);
    fprintf(stderr, "All tests passed\n");
    return 0;
}