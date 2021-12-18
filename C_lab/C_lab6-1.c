/*实验 6-1程序改错与跟踪题源程序*/
#include <stdio.h>
char *strcopy(char *, const char *);
#define SIZE 1000
int main(void)
{
    // 字符指针指定的字符串只能读不能写，需要数组
    // 如果在声明时赋值，则这段字符串数据是被存储在静态数据中的
    // 其余字符指针的赋值数据无法真正创建一个变量进行赋值，只能把指针
    // 指向这个静态的字符串
    // char *s1, *s2, *s3;
    char s1[SIZE], s2[SIZE], *s3;
    // 错误
    // printf("Input a string:\n", s2);
    printf("Input a string:\n");
    scanf("%s", s2);
    // printf("%s\n", s2);
    strcopy(s1, s2);
    printf("%s\n", s1);
    printf("Input a string again:\n", s2);
    scanf("%s", s2);
    s3 = strcopy(s1, s2);
    printf("%s\n", s3);
    return 0;
}
char *strcopy(char *t, const char *s)
{
    // 逻辑上修改了t和s的值 s为 const不能修改 t最后需要返回也不能修改
    // while (*t++ = *s++)
    //     ;
    int i;
    while (*(t + i) = *(s + i))
        i++;
    return (t);
}
