#include <stdio.h>
#include <string.h>
int main(void)
{
    // 声明一个这样类型的函数指针p 函数的返回值为 char*
    char *(*p)(char *a, const char *b);
    char a[80], b[80], *result;
    int choice;
    while (1)
    {
        do
        {
            printf("\t\t1 copy string.\n");
            printf("\t\t2 copy string.\n");
            printf("\t\t3 copy string.\n");
            printf("\t\t4 copy string.\n");
            printf("\t\tinput a number (1-4) please!\n");
            scanf("%d", &choice);
        } while (choice < 1 || choice > 4);
        switch (choice)
        {
        case 1:
            p = strcpy;
            break;
        case 2:
            p = strcat;
            break;
        case 3:
            p = strtok;
            break;
        case 4:
            goto down;
            break;
        }
        getchar();
        printf("input the first string please!\n");
        // fgets(a, 80, stdin);
        gets(a);
        printf("input the second string please!\n");
        // fgets(b, 80, stdin);
        gets(b);
        result = p(a, b);
        printf("the result is %s\n", result);
        printf("%s\n", result);
    }
down:
    return 0;
}