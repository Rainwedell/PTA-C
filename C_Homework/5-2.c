// 数组循环右移的问题简化，经典算法，三次逆序，也可以用另一个方法，复杂度一样的，详见pta1008题解
#include <stdio.h>

void move(int arr[], int n, int k)
{
    /**********  Begin  **********/
    for (int i = 0; i < k / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[k - 1 - i];
        arr[k - 1 - i] = temp;
    }
    for (int i = 0; i < (n - k) / 2; i++)
    {
        int temp = arr[i + k];
        arr[i + k] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
    for (int i = 0; i < n / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    /**********  End  **********/
}
int main(void)
{
    int a[7] = {1, 2, 3, 4, 5, 6, 7};
    move(a, 7, 3);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
