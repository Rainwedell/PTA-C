// 一题多解
// 法一 遍历数组，当前数如果与前一个数相同，则删去当前数，同时修改长度。
// 法二 新建一个标记数组b[n]，默认值为0,遍历数组,如果不是第一次出现把值修改为1，，遍历b[n]，输出标记为0的数，并返回0的个数作为长度
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000
int RemoveSame(int *a, int n)
{
    if (n == 1)
        return 1;
    else
    {
        for (int i = 1; i < n; i++)
        {
            if (*(a + i - 1) == *(a + i)) //当前数字与前一个数相同
            {
                for (int j = i; j < n - 1; j++) //删去当前数，后面的数左移一位
                    *(a + j) = *(a + j + 1);
                i--; //再次比较当前位置
                n--; //修改长度
            }
        }
    }
    return n;
}
// 法二
int RemoveSame2(int *a, int n)
{
    int len = 0;
    if (n == 1)
        len = 1;
    else
    {
        int b[SIZE] = {0};
        for (int i = 1; i < n; i++)
        {
            if (*(a + i - 1) == *(a + i)) //当前数字与前一个数相同
                *(b + i) = 1;
        }
        for (int i = 0; i < n; i++)
        {
            if (*(b + i) == 0)
            {
                *(a + len) = *(a + i);
                len++;
            }
        }
    }
    return len;
}

int main(void)
{
    int N;
    scanf("%d", &N);
    int *a = (int *)malloc(N);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
    int len = RemoveSame2(a, N);
    for (int i = 0; i < len; i++)
    {
        printf("%d", *(a + i));
        if (i != len - 1)
            printf(" ");
    }

    printf("\n%d\n", len);
    return 0;
}