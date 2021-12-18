#include <stdio.h>
#include <string.h>
int n;
// 本例可以还直接用快排的轮子
// #include <stdlib.h>
typedef struct AStudent
{
    char name[80];
    int score;
    // int Len;
} Student;
void Swap(Student *a, Student *b)
{
    Student t = *a;
    *a = *b;
    *b = t;
}
// 基础版二分查找，循环实现
int BinarySearch(Student arr[], int low, int high, int Score)
{
    int isFound = 0;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid].score == Score)
        {
            isFound = 1;
            int tempLeft, tempRight;
            tempLeft = mid - 1;
            tempRight = mid + 1;
            while (arr[tempLeft].score == arr[mid].score && tempLeft >= low)
            {
                printf("%s %d\n", arr[tempLeft].name, arr[tempLeft].score);
                tempLeft--;
            }
            printf("%s %d\n", arr[mid].name, arr[mid].score);
            while (arr[tempRight].score == arr[mid].score && tempRight <= high)
            {
                printf("%s %d\n", arr[tempRight].name, arr[tempRight].score);
                tempRight++;
            }
            return 1;
        }
        else if (arr[mid].score < Score)
            high = mid - 1;
        else if (arr[mid].score > Score)
            low = mid + 1;
    }

    if (isFound == 0)
    {
        printf("not found\n");
    }
    return isFound;
}
// 递归实现
// int BinarySearch(Student arr[], int low, int high, int Score)
// {
//     if (low > high)
//     {
//         printf("not found");
//         return -1;
//     }
//     // int isFound = 0;
//     // int low = 0, high = n - 1;
//     int mid = (low + high) / 2;
//     if (arr[mid].score > Score)
//         return BinarySearch(arr, mid + 1, high, Score);
//     else if (arr[mid].score < Score)
//         return BinarySearch(arr, low, mid - 1, Score);
//     else
//     {

// int tempLeft, tempRight;
// tempLeft = mid - 1;
// tempRight = mid + 1;
// printf("%s %d\n", arr[mid].name, arr[mid].score);
// while (arr[tempLeft].score == arr[mid].score && tempLeft >= low)
// {
//     printf("%s %d\n", arr[tempLeft].name, arr[tempLeft].score);
//     tempLeft--;
// }
// while (arr[tempRight].score == arr[mid].score && tempRight <= high)
// {
//     printf("%s %d\n", arr[tempRight].name, arr[tempRight].score);
//     tempRight++;
// }
// return 1;
// }
// }
void menu(void)
{
}
int Input(Student arr[], int n)
{
    scanf("%d", &n);
    // Student arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", arr[i].name, &arr[i].score);
    }
    return n;
}
void Sort(Student arr[], int n)
{
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < n - 1 - j; i++)
        {

            if (arr[i].score < arr[i + 1].score)
            {
                Swap(arr + i, arr + i + 1);
            }
            else if (arr[i].score == arr[i + 1].score)
            {
                if (strcmp(arr[i].name, arr[i + 1].name) > 0)
                {
                    Swap(arr + i, arr + i + 1);
                }
            }
        }
    }
}
void Output(Student arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", arr[i].name, arr[i].score);
    }
    // return arr;
}
void Out(void)
{
}
int main(void)
{
    int FUN, n;
    n = -1;

    Student arr[1000];
    while ((scanf("%d", &FUN) != EOF))
    {

        // if(FUN!=1)  printf("先输入\n")
        // Student NotArr[1] = {"wrong", -1};
        // // for (int i = 0; i < n; i++)
        // // {
        // //     scanf("%s %d", arr[i].name, &arr[i].score);
        // // }
        switch (FUN)
        {
        case 0:
            return 0;
            break;
        case 1:
            n = Input(arr, n);
            break;
        case 2:
            if (n >= 0)
                Sort(arr, n);
            break;
        case 3:
            if (n >= 0)
                Output(arr, n);
            break;
        case 4:
            if (n >= 0)
            {
                int Score;
                scanf("%d", &Score);
                BinarySearch(arr, 0, n - 1, Score);
            }
            break;

        default:
            break;
        }
    }
    return 0;
}