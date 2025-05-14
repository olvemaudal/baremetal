#include <stdio.h>

int main(void)
{
    for (int n = 0; n < 20; n++) {
        int d = 2;
        while (d < n && n % d != 0)
            ++d;
        if (d == n)
            printf("%d\n", n);
    }
}
