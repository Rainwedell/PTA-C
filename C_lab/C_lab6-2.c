#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define N 4
/* 对指针数组s指向的size个字符串进行升序排序 */
void strsort(char *s[], int size)
{
    char *temp;
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            // 如果前一个字符串大于后一个字符串
            if (strcmp(s[j], s[j + 1]) > 0)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    int i;
    // int N;
    // scanf("%d", &N);
    // getchar();
    char *s[N], t[50];
    for (int i = 0; i < N; i++)
    {
        gets(t);
        s[i] = (char *)malloc(strlen(t) + 1);
        strcpy(s[i], t);
    }
    strsort(s, N);
    for (i = 0; i < N; i++)
        puts(s[i]);
    return 0;
}