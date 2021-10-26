#include<stdio.h>
#include"math.h"
int IsPrime(int N)
{
    int state = 1;
    
    if((N==1||N%2==0) && N!=2) state = 0;
    else
    {
        for (int i = 3; i <= sqrt(N); i+=2)
        {
            if(N%i==0)  
            {
                state = 0;
                break;
            }
        }
    }
    return state;
}
int main(void)
{
    int n;
    scanf("%d",&n);
    int cnt = 0;
    int CNT = 0;
    for (int i = 1; i <= n; i++)
    {
        if(IsPrime(i))  cnt++;
    }
    int Prime[cnt];
    for (int i = 1; i <= n; i++)
    {
        static int x = 0;
        if(IsPrime(i))
        {
           Prime[x++] = i; 
        }
    }
    for (int i = 1; i < cnt; i++)
    {
        if(Prime[i]-Prime[i-1]==2) CNT++;
    }
    printf("%d",CNT);
    return 0;
}