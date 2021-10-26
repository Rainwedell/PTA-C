#include <stdio.h>
void IsN(int x);
void Is2N(int x ,int y);
void Is_N(double x,int y);
void IsN(int x)
{
    if(x == 0 ) printf("N");
    else printf("%d",x);
}
void Is_N(double x,int y)
{
    if(x == 0 ) printf("N");
    else printf("%.1f",x/y);
}
void Is2N(int x ,int y)
{
    if(y == 0 ) printf("N");
    else printf("%d",x);
}
int main(void)
{
    int N;
    int A1=0,A2=0,A3=0,A5=0;
    float A4 = 0;
    int count = 0;
    int CNT = 0;
    scanf("%d",&N);
    int a[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&a[i]);
    }
    A1 = 0;
    for (int i = 0; i < N; i++)
    {
        if (a[i]%5==0 && a[i]%2==0)
        {
            A1+=a[i];
        }
        else if (a[i]%5==1)
        {
            CNT++;
            //static int cnt = 1;
            if (CNT%2==0)   A2-=a[i];
            else A2+=a[i];
            //CNT++;
        }
        else if (a[i]%5==2)
        {
            A3++;
        }
        else if (a[i]%5==3)
        {
            A4+=a[i];
            count++;
        }
        else if (a[i]%5==4)
        {
            if (a[i]>A5)
            {
                A5 = a[i];
            }
            
        }

    }
    //A4=count;
    IsN(A1);
    printf(" ");
    Is2N(A2,CNT);
    printf(" ");
    IsN(A3);
    printf(" ");
    Is_N(A4,count);
    printf(" ");
    IsN(A5);
}