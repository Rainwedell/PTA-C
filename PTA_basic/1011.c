#include<stdio.h>
#define MAX 2147483647
void output(int t,int cnt);
void output(int t,int cnt)
{
    if(t)   printf("Case #%d: true",cnt);
    else printf("Case #%d: false",cnt);
}
int main(void)
{
    int X;
    long int A,B,C;
    int cnt = 1;
    scanf("%d",&X);
    int CNT[X+1];
    while (cnt<=X)
    {
        scanf("%ld %ld %ld",&A,&B,&C);
        if (A>0&&B>0)
        {
            if (C>0)
            {
                CNT[cnt]=(A-MAX+B>C-MAX);
                //output(A-MAX+B>C-MAX,cnt);
            }
            else CNT[cnt]=0;
        }
        else if(A<0&&B<0)
        {
            if(C<0)
            {
                CNT[cnt]=(A+B+MAX>C-MAX);
            }
            else CNT[cnt]=1;
        }
        else CNT[cnt]=(A+B>C);
        cnt ++;
    }
    for (int i = 1; i <X; i++)
    {
        output(CNT[i],i);
        printf("\n");
    }
    output(CNT[X],X);
    return 0;
    
}