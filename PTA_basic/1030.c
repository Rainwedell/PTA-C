#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(int*)a - *(int*)b;
}
int main(void)
{
    // printf("%d",sizeof(int));
    // return 0;
    long N,p;
    scanf("%ld %ld",&N,&p);
    long int a[N],Pnum;
    Pnum = 0;
    for (int i = 0; i < N; i++)
        scanf("%ld",&a[i]);
    qsort(a,N,sizeof(long),cmp);
    long min=0;
    for (int i = 0; i < N; i++)
    {
        if(a[i]<=(long long)a[min]*p)
            Pnum++;
        else
        {
            min++;
            if(min==N-1)    break;
        }
        
    } 
    printf("%ld\n",Pnum);
    return 0;
    

}