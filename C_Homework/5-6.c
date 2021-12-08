#include <stdio.h>
#include <string.h>

#define SIZE 100

int isPalindrome(char arr[], int len);

int main()
{
    /**** 输入字符串,调用函数isPalindrome判断是否为回文串，然后输出结果 *******/
    /**********  Begin ***********/
    char arr[SIZE];
    scanf("%s", arr);
    isPalindrome(arr, strlen(arr)) ? printf("YES\n") : printf("NO\n");
    /**********  End  **********/
    return 0;
}

/**** 在下面编写满足任务要求的递归函数isPalindrome，是回文返回1，不是返回0 *******/
/**********  Begin ***********/
int isPalindrome(char arr[], int len)
{

    if (len == 1)
        return 1;
    else if (arr[0] != arr[len - 1])
        return 0;
    else
        return isPalindrome(arr + 1, len - 2);
}

/**********  End  **********/