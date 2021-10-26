#include<stdio.h>
int main(void)
{
    int A,B,D,i;
    int x[32];
    scanf("%d %d %d",&A,&B,&D);
    int S = A+B;
    if( S != 0)
    {
        for(i = 0;S!=0;i++)
        {
            x[i] = S % D;
            S /= D;
           // printf(" %d:%d %d\n",i,x[i],S);
        }
        for(int j=i-1;j>=0;j--)
        {
            printf("%d", x[j]);
        }
    }
    else printf("0");
    printf("\n");
    return 0;
}