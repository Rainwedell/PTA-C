#include<stdio.h>
int main(void)
{
    int n;
    scanf("%d",&n);
    if (n<1||n>10)
    {
        printf("Invalid.");
    }
    else
    {
        int a[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
        }
        double avg,sum;
        sum=0;
        for (int i = 0; i < n; i++)
        {
            sum+=a[i];
        }
        avg = sum/n;
        printf("%.2f\n",avg);
        int state = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i]>(double)avg)
            {
                printf("%d ",a[i]);
                state = 1;
            }
        }
        if (state == 0)
        {
            printf("\n");
        }
        
    }
    
    return 0;
    
}