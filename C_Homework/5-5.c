#include <stdio.h>

void conversion(char str[])
{
    /**********  Begin  **********/
    int cnt, dex;
    dex = 0;
    for (cnt = 0; str[cnt] != '\0' && ((str[cnt] <= 'f' && str[cnt] >= 'a') || (str[cnt] <= 'F' && str[cnt] >= 'A') || (str[cnt] <= '9' && str[cnt] >= '0')); cnt++)
        ;
    for (int i = 0; i < cnt; i++)
    {
        dex *= 16;
        if (str[i] >= 'a' && str[i] <= 'f')
            dex += (str[i] - 'a' + 10);
        else if (str[i] >= 'A' && str[i] <= 'F')
            dex += (str[i] - 'A' + 10);
        else
            dex += (str[i] - '0');
    }
    printf("%d\n", dex);
    /**********  End  **********/
}
int main(void)
{
    char str[101];
    scanf("%s", str);
    conversion(str);
    return 0;
}