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
void rotatefPrint(int *arr, int n, int m, char *filename)
{
    FILE *fpOut = fopen(filename, "w");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x = (j + 1) * m - (i + 1);
            // printf("%d", *(arr + x));
            fprintf(fpOut, "%d", *(arr + x));
            if (j != n - 1)
            {
                // printf(" ");
                fprintf(fpOut, " ");
            }
        }
        fprintf(fpOut, "\n");
        // printf("\n");
    }
    // printf("\n%d\n", arr[4]);
}
int main(void)
{
    int n, m;
    char filename[80];
    scanf("%s", filename);
    FILE *fp = NULL;
    // FILE *fpOut = NULL;
    fp = fopen(filename, "r");
    // fpOut = fopen("matrix.out", "w");
    fscanf(fp, "%d", &n);
    fscanf(fp, "%d", &m);
    int *arr = (int *)malloc(sizeof(int) * n * m);
    for (int i = 0; i < n * m; i++)
    {
        fscanf(fp, "%d", arr + i);
    }
    rotatefPrint(arr, n, m, "matrix.out");
    free(arr);
    fclose(fp);
    return 0;
}

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