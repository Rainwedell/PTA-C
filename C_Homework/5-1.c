#include <stdio.h>
#define SIZE 100
/*****请在下面补充函数 inArray、selectSort 和 outArray 的定义 *****/
void outArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
void selectSort(int arr[], int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                int t = arr[min];
                arr[min] = arr[j];
                arr[j] = t;
            }
        }
    }
}
void inArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}
int main(void)
{
    int arr[SIZE];
    inArray(arr, 5);
    selectSort(arr, 5);
    outArray(arr, 5);
    return 0;
}