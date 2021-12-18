#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
// 1.STL快排
// 升序
int cmp1(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
// 降序
int cmp2(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}
// 2.自己写的快排
int *quickSort(int *arr, int N)
{
}

// 这里用选择排序
int insertSort(int *a, int N, int upORdown)
{
    int *min, *max;
    for (int i = 0; i < N - 1; i++)
    {
        min = a + i;
        max = a + i;
        for (int j = i + 1; j < N; j++)
        {
            if (upORdown)
            {
                if (*min > *(a + j))
                {
                    int temp = *(a + j);
                    *(a + j) = *(a + i);
                    *(a + i) = temp;
                }
            }
            else
            {
                if (*max < *(a + j))
                {
                    int temp = *(a + j);
                    *(a + j) = *(a + i);
                    *(a + i) = temp;
                }
            }
        }
    }
}

int transferStrToNum(char str[])
{
    int len = strlen(str);
    int num = 0;
    for (int i = 0; i < len; i++)
    {
        num *= 10;
        num += str[i] - '0';
    }
    return num;
}
// 改进 希尔排序

// 冒泡

// 冒泡改进

// 归并
int main(int argc, char *argv[])
{
    int N = transferStrToNum(argv[1]);
    // int upORdown = 1;
    int *arr = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        scanf("%d", (arr + i));

    if (argc == 3 && strcmp(argv[2], "-d") == 0)
        qsort(arr, N, sizeof(int), cmp2);
    else
        qsort(arr, N, sizeof(int), cmp1);
    // if (argc == 3 && strcmp(argv[2], "-d") == 0)
    // {
    //     upORdown = 0;
    //     insertSort(arr, N, upORdown);
    // }
    // else
    //     insertSort(arr, N, upORdown);
    for (int i = 0; i < N; i++)
    {
        printf("%d", *(arr + i));
        if (i != N - 1)
            printf(" ");
    }
    printf("\n");
    // for (int i = 0; i < argc; i++)
    // {
    //     printf("argc=%d:%s\nN=%d", i, argv[i],N);
    // }
    free(arr);

        return 0;
}
