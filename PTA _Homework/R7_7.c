#include<stdio.h>
int main(void)
{
    int n;
        static int x[10];
    scanf("%d",&n);
    if (n<1||n>1000)
    {
        printf("Invalid.");
    }

    else
    {
        int b[9] = {0};
        int a[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
        }
        for (int i = 0; i < n; i++)
        {
            switch (a[i])
            {
            case 1:
                b[1]++;
                break;
            case 2:
                b[2]++;
                break;    
            case 3:
                b[3]++;
                break;
            case 4:
                b[4]++;
                break;
            case 5:
                b[5]++;
                break;
            case 6:
                b[6]++;
                break;
            case 7:
                b[7]++;
                break;
            case 8:
                b[8]++;
                break;                    
            default:
                break;
            }
        }
        for (int i = 1; i < 9; i++)
        {
            printf("%4d%4d\n",i,b[i]);
        }
    }   
    
    
    return 0;
    
}