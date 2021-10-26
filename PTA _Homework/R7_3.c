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
        long x,a[n];
        scanf("%ld",&x);
        for (int i = 0; i < n; i++)
        {
            scanf("%ld",&a[i]);
        }
        int state = 0;
        for (int i = 0; i < n; i++)
        {
            if (x==a[i])
            {
                printf("%d\n",i);
                state = 1;
            }
        }
        if(state == 0)  printf("Not Found");
        
    }
    
    return 0;
    
}