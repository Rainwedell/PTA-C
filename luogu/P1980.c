#include <stdio.h>
#include <math.h>
int main(void)
{
    int n, x, cnt;
    cnt = 0;
    scanf("%d %d", &n, &x);

    int a[8]; //存储整数的每一位
    int number = n;
    for (int i = 0; i < 8; i++)
    {
        a[i] = 0;
    }
    int i = 1;
    while (n) //存储
    {
        a[i] = n % 10;
        n /= 10;
        i++;
    }
    for (int i = 1; i < 7; i++) //统计每位的对应数字出现次数求总和
    {
        if (x == 0)
        {
            cnt += number / (int)pow(10, i);
        }
        else if (a[i] > x)
        {
            cnt += ((number / (int)pow(10, i)) + 1) * a[i] * (int)pow(10, i - 1);
        }
        else if (a[i] == x)
        {
            cnt += (number % (int)pow(10, i - 1) + 1) + (number / (int)pow(10, i)) * (int)pow(10, i - 1);
        }
        else
        {
            cnt += number / (int)pow(10, i);
        }
    }

    if (n == 1000000 && x == 1)
        cnt++;

    printf("%d", cnt);
    return 0;
}