#include <stdio.h>
#include "math.h"

int main(void)
{
    unsigned long m, n, x;
    scanf("%ld %ld", &n, &m);
    if (m == 1)
        x = n;
    else
    {
        for (x = 1; pow(x, m) <= n; x++)
            ;
        x--;
    }
    printf("%lu", x);
    return 0;
}
