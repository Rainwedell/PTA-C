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
        int a[n],min,I;
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
        }
        min = a[0];I = 0;
        for (int i = 1; i < n; i++)
        {
           if (min> a[i]) 
           {
               min = a[i];
               I = i;
           }
           
        }
        a[I] = a[0];a[0] = min;
        for (int i = 0; i < n; i++)
        {
            printf("%d ",a[i]);
        }
    }
    
    return 0;
    
}