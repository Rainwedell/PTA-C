#include <stdio.h>
//冒泡升序排序 ，程序的输入为 int类型数组 和数组长度
//请在此处编辑您的代码
/**********  Begin  **********/
void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (*(arr + j) > *(arr + j + 1))
            {
                int temp = *(arr + j + 1);
                *(arr + j + 1) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}
/**********  End  **********/
int main(void)
{
    int arr[10] = {4, 91, 51, 2, 32, 58, 7, 172, 88, 14};
    for (int i = 0; i < 10; i++)
    {
        printf("%5d", arr[i]);
    }
    printf("\n");
    bubble_sort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%5d ", arr[i]);
    }
    return 0;
}
