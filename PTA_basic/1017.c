//大数除法
#include<stdio.h>
#include<string.h>
int main(void)
{
    char A[1001];
    int B,Q[1000],R;
    scanf("%s %d",A,&B);
    int t,temp,Len;
    t=temp=0;
    Len = strlen(A);
    if(Len==1)
    {
        printf("%d %d\n",(A[0]-'0')/B,(A[0]-'0')%B);
    }
    else
    {
         for(int i=0;i<Len;i++)
         {
             t=(A[i]-'0')+10*temp;
             temp = t%B;
             t/=B;
             Q[i]=t;
             
         }
    
        R = temp;
        if((A[0]-'0')/B == 0)
        {
            for(int i=1;i<Len;i++)
            {
                printf("%d",Q[i]);
            }
        }
        else
        {
            for(int i=0;i<Len;i++)
            {
                printf("%d",Q[i]);
            }
        }
            printf(" ");
            printf("%d\n",R);
    }
        return 0;
}