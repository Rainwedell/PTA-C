#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void sort(struct web webs[], int n);

struct web /*  设计表示网址的结构  */
{
    /**********  Begin  **********/
    char name[10];
    char Name[20];
    char URL[100];

    /**********   End   **********/
};
int cmp(const void *a, const void *b)
{
    struct web *s1, *s2;
    s1 = (struct web *)a;
    s2 = (struct web *)b;
    if (strcmp(s1->name, s2->name) > 0)
        return 1;
    else
        return -1;
}
#define N 4 /*  网址表大小  */

int main()
{
    /**********  Begin  **********/
    struct web webs[N];
    for (int i = 0; i < N; i++)
        scanf("%s %s %s", webs[i].name, webs[i].Name, webs[i].URL);

    qsort(webs, N, sizeof(webs[0]), cmp);
    for (int i = 0; i < N; i++)
        printf("%s %s %s\n", webs[i].name, webs[i].Name, webs[i].URL);

    // 优化循环合并
    char search[10];
    int find = 0;
    scanf("%s", search);
    for (int i = 0; i < N; i++)
        if (strcmp(search, webs[i].name) == 0)
        {
            printf("%s\n", webs[i].URL);
            find = 1;
        }
    if (!find)
        printf("未找到搜寻的网址\n");
    /**********   End   **********/
    return 0;
}

// void sort(struct web webs[], int n)
// {
//     /**********  Begin  **********/

//     /**********   End   **********/
// }