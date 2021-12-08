#include <stdio.h>
#include <math.h>

#define N 30

int main()
{
    int i, j, n, m, a[N][N];
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    //行标记
    for (i = 0; i < n; i++)
        for (j = 0; j < m - 2; j++)
            if (abs(a[i][j]) == abs(a[i][j + 1]) && abs(a[i][j + 1]) == abs(a[i][j + 2]))
            {
                if (a[i][j] > 0)
                    a[i][j] *= -1;
                if (a[i][j + 1] > 0)
                    a[i][j + 1] *= -1;
                if (a[i][j + 2] > 0)
                    a[i][j + 2] *= -1;
            }
    //列标记
    for (j = 0; j < m; j++)
        for (i = 0; i < n - 2; i++)
            if (abs(a[i][j]) == abs(a[i + 1][j]) && abs(a[i + 1][j]) == abs(a[i + 2][j]))
            {
                if (a[i][j] > 0)
                    a[i][j] *= -1;
                if (a[i + 1][j] > 0)
                    a[i + 1][j] *= -1;
                if (a[i + 2][j] > 0)
                    a[i + 2][j] *= -1;
            }
    //消除
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (j != 0)
                printf(" ");
            if (a[i][j] < 0)
                printf("0");
            else
                printf("%d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}