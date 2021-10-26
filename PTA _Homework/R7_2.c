#include<stdio.h>
int main(void)
{
    int n;
    scanf("%d",&n);
    if (n<1||n>46)
    {
        printf("Invalid.");
    }
    else
    {
        long a[n];
        a[0]=1,a[1]=1;
        for (int i = 2; i < n; i++)
        {
            a[i] = a[i-1] + a[i-2];
        }
        for (int i = 0; i < n; i++)
        {
            printf("%11ld",a[i]);
            if ((i+1)%5 == 0)
            {
                printf("\n");
            }
            
        }
    }
    return 0;
}