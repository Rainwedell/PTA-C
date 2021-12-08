#include <stdio.h>
//函数的输入为 int类型数组 和数组长度
void reverseOrder(int a[], int n)
{
    //请在此处编辑您的代码
    /**********  Begin  **********/
    for (int i = 0; i < n / 2; i++)
    {
        int temp = *(a + i);
        *(a + i) = *(a + n - 1 - i);
        *(a + n - 1 - i) = temp;
    }
    /**********  End  **********/
}
int main(void)
{
    int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    reverseOrder(a, 9);
    for (int i = 0; i < 9; i++)
    {
        printf("%d  ", a[i]);
    }
    return 0;
}