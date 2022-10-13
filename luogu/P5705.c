#include <stdio.h>
#include <string.h>
//尝试直接用除法会不会出问题，有问题就换字符转换
int main(void)
{
    float x = 0;
    scanf("%f", &x);
    x *= 10;
    int y = (int)x;
    int output = 0;
    for (int i = 0; i < 4; i++)
    {
        output *= 10;
        output += y % 10;
        y /= 10;
    }
    x = (float)output / 1000;
    printf("%.3f", x);
    return 0;
}