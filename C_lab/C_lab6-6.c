#include <stdio.h>
int main(void)
{
    int N;
    scanf("%d", &N);
    char *p = (char *)&N; // 1字节为单位
    // int *q = &N;
    char high[4], low[4];
    // int cnt;
    printf("%x\n", N);
    for (int i = 0; i < 4; i++) //遍历int的 4个字节
    {
        low[i] = (*p) & 0x0f; //取一个字节的低位
        if (low[i] < 10)
            low[i] |= '0'; // low+='0'
        else
            low[i] = (low[i] - 10) + 'a'; //(low-10)+'A'

        high[i] = (*p >> 4) & 0x0f; //取一个字节的高位
        if (high[i] < 10)
            high[i] |= '0'; // high+='0'
        else
            high[i] = (high[i] - 10) + 'a'; //(high-10)+'A'

        p++; //下一个字节
        // printf("high:%c low:%c\n", high[i], low[i]);
    }
    for (int i = 3; i >= 0; i--)
    {
        printf("%c %c ", high[i], low[i]);
    }

    // printf("N的地址:  %p\nN+1的地址: %p\np的地址:  %p\np+1的地址: %p\n", &N, q + 1, p, p + 1);
    // for (int i = 0; i < 8; i++)
    // {
    //     low = (*p) & 0x0f;
    //     printf("*p=%x", *p);
    //     printf("%x ", low);
    //     p++;
    // }

    return 0;
}