#include<stdio.h>
#include<stdlib.h>
void Sort(int S[],int N,int cnt);
int cmp1( const void *a , const void *b );
int cmp2( const void *a , const void *b );
void Sort(int S[],int N,int cnt)
{
    if (cnt != 0)
    {
        qsort(S,N,sizeof(int),cmp1);//降序排列
        qsort(S,N-cnt,sizeof(int),cmp2);//排除 数字0 后升序排列
        qsort(S+1,N-1,sizeof(int),cmp2);//排除第一个数字后把后续所有数字包括进来升序排列
    }
}
int cmp1( const void *a , const void *b )
{
    return (*(int*)b - *(int*)a); 
}
int cmp2( const void *a , const void *b )
{
    return (*(int*)a - *(int*)b); 
}
int main(void)
{
    int CNT[10],N;
    N = 0;
    for(int i = 0;i<10;i++)
    {
        scanf("%d",&CNT[i]);
        N+=CNT[i];
    }
    int number[N];
    int n = 0;
    for(int i = 0;i<10;i++)                     //0到9每个数
    {
        for (int j = 0; j < CNT[i]; j++)         //每个数的个数
        {
            number[n] = i;                      //把每个数装填进数组
            n++;
        } 
    }
    Sort(number,N,CNT[0]);
    for (int i = 0; i < N; i++)
        printf("%d",number[i]);
    
    printf("\n");
    return 0;
    
}