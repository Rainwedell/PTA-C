#include <stdio.h>

int main(void)
{
    unsigned int A, B, C, Total;
    scanf("%d %d %d", &A, &B, &C);
    Total = 0.2 * A + 0.3 * B + 0.5 * C;
    printf("%d", Total);
    return 0;
}