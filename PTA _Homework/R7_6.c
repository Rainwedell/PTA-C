#include<stdio.h>
void sort(int a[],int n);
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

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n-i-1; j++)
            {
                if(a[j]<a[j+1])
                {
                    int t;
                    t = a[j],a[j] = a[j+1];a[j+1] = t;
                }
            }
            
        }
        for(int i = 0; i < n-1; i++)
        {
            printf("%d ",a[i]);
        }
        printf("%d",a[n-1]);
    }
    
    return 0;
    
}