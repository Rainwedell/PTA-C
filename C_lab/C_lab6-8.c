#include <stdio.h>
#include <stdlib.h>
// m列 n行
// now:
//     arr   ,arr+1,   ...  arr+m-1
//     arr+m ,arr+m+1  ...  arr+2m-1
//     .
//     .
//     .
//     arr+(n-1)*m, arr+(n-1)*m+1 ...arr+(n-1)*m+m-1=   arr+n*m-1

// after: n 列 m行
//     arr+m-1   , arr+2m-1  ...  arr+n*m-1
//     arr+m-2   , arr+2m-2  ...  arr+n*m-2
//     .
//     .
//     .
//     arr       , arr+m     ...  arr+(n-1)*m
void rotatePrint(int *arr, int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x = (j + 1) * m - (i + 1);
            printf("%d", *(arr + x));
            if (j != n - 1)
                printf(" ");
        }
        printf("\n");
    }
    // printf("\n%d\n", arr[4]);
}
int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    // int arr[n][m];
    int *arr = (int *)malloc(sizeof(int) * n * m);
    for (int i = 0; i < n * m; i++)
    {
        scanf("%d", arr + i);
    }
    rotatePrint(arr, n, m);
    free(arr);
    return 0;
}