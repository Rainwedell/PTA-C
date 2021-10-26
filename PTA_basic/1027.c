#include<stdio.h>
void Print(int a,char c);
void cPrint(int x,char c)
{
    for (int i = 0; i < x; i++)
    {
        printf("%c",c);
    }
    printf("\n");
}
void spacePrint(int x)
{
    for(int i = 0;i<x;i++)
        printf(" ");
}
void Print(int a,char c)
{
    
    for (int i = 0; i <= a; i++)
    {
        spacePrint(i);
        cPrint(2*a+1-2*i,c);
    }
    for (int i = 0; i < a ; i++)
    {
        spacePrint(a-i-1);
        cPrint((i+1)*2+1,c);
    }
}

int main(void)
{
    int S[1000];
    S[0]=1;
    int i;
    for ( i = 1; S[i] <= 1000; i++)
    {
        S[i]=(i+1)*(i+1)*2-1;
    }
    int N;
    char c;
    scanf("%d %c",&N,&c);
    for ( i = 0; S[i] < N; i++)
    {
        ;
    }
    //printf("i = %d\n",i);
    if (N==1)
    {
        printf("%c\n",c);
    }else Print(i-1,c);
    printf("%d\n",N-S[i-1]);
    return 0;
}