#include <stdio.h>
#include <string.h>
int main(void)
{
    // 声明一个这样类型的函数指针p 函数的返回值为 char*
    char *(*p[3])(char *a, const char *b) = {
        strcpy,
        strcat,
        strtok,
    };
    char a[80], b[80], *result;
    int choice;
    while (1)
    {
        do
        {
            scanf("%d", &choice);
        } while (choice < 1 || choice > 4);
        if (choice == 4)
            goto down;
        getchar();
        gets(a);
        gets(b);
        result = p[choice - 1](a, b);
        printf("%s\n", result);
    }
down:
    return 0;
}