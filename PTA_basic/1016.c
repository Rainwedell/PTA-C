#include<stdio.h>
int main(void)
{
    int Da,Db,A[9],B[9];
    long a,b;
    long sum1,sum2;
    sum1 = sum2 = 0;
    scanf("%ld %d %ld %d",&a,&Da,&b,&Db);
    int i1 = 0;
    int i2 = 0;
    int cnt1,cnt2;
    cnt1 = cnt2 = 0;
    while (a!=0)
    {
        A[i1] = a%10;
        a/=10;
        i1++;
    }
    while (b!=0)
    {
        B[i2] = b%10;
        b/=10;
        i2++;
    }
    for (int j = 0; j < i1; j++)
    {
        if (Da == A[j])
        {
            cnt1++;
        }
        
    }
    //printf("cnt1 = %d\n",cnt1);
    for (int j = 0; j < i2; j++)
    {
        if (Db == B[j])
        {
            cnt2++;
        }
    }
    for (int i = 0; i < cnt1; i++)
    {
        sum1 += Da;
        Da*=10;
    }
    for (int i = 0; i < cnt2; i++)
    {
        sum2 += Db;
        Db*=10;
    }
    printf("%ld\n",sum1+sum2);
    return 0;
}