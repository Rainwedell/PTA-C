/******************************************************************
 在下面编写带参 main0 函数，实现字符串的连接，字符串由命令行给出；
 连接之后的新串无冗余地存储到用`malloc`动态分配的空间，并将该空间首地址赋值给外部指针`p`。

 将本地调试通过的 main 改为 main0，可能需要按题目要求作适当修改，
 比如，这里的 main0 只完成连接操作，不需要输出数据。
 ******************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *p; // 外部指针的引用性声明，p指向连接后的串

void Strcat(char str[])
{
    for (int i = 0; i < strlen(str); i++)
    {
        static int pos = 0;
        *(p + pos) = *(str + i);
        pos++;
    }
}
int main(int argc, char *argv[])
{
    /**********  Begin  **********/
    int size = 0;
    for (int i = 1; i < argc; i++)
    {
        size += (int)strlen(argv[i]);
    }
    printf("size = %d\n", size);
    p = (char *)malloc(size + 1);
    for (int i = 1; i < argc; i++)
    {
        printf("%d:%s\n", i, argv[i]);
        Strcat(argv[i]);
    }
    *(p + size) = '\0';
    printf("%s", p);
    free(p);

    return 0;
    /**********  End  **********/
}
// int main(void)
// {
//     char str1[] = "abcd";
//     char str2[] = "abc";
//     char str3[] = "ab";
//     char str4[] = "a";
//     int size = (int)strlen(str1) + strlen(str2) + strlen(str3) + strlen(str4);
//     p = (char *)malloc(size);
//     Strcat(str1);
//     Strcat(str2);
//     Strcat(str3);
//     Strcat(str4);
//     *(p + size ) = '\0';
//     printf("%s\n", p);
//     free(p);
//     return 0;
// }