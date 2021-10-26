#include<stdio.h>
int main(void)
{
    int n;
    int b = 0;
    int c = 0;
    int d = 0;
    scanf("%d",&n);
    b = n/100;
    c = n/10;c%=10;
    d = n-100*b-10*c;
    while (b>0)
    {
        printf("B");
        b--;
    }
    while (c>0)
    {
        printf("S");
        c--;
    }
     while (d>0)
    {
        static int cnt = 0;
        cnt++;
        printf("%d",cnt);
        d--;
    }
    return 0;
}