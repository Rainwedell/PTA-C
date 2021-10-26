#include<stdio.h>
int main(void)
{
    char a[1001];
    int cnt[10] = {0};
    int x;
    scanf("%s",a);
    for (int i = 0; a[i] !='\0'; i++)
    { 
        //x = a[i]-'0';
        switch (a[i]-'0')
        {
        case 0:
            cnt[0]++;
            break;
        case 1:
            cnt[1]++;
            break;
        case 2:
            cnt[2]++;
            break;
        case 3:
            cnt[3]++;
            break;
        case 4:
            cnt[4]++;
            break;
        case 5:
            cnt[5]++;
            break;
        case 6:
            cnt[6]++;
            break; 
        case 7:
            cnt[7]++;
            break;
        case 8:
            cnt[8]++;
            break;
        case 9:
            cnt[9]++;
            break;                  
        default:
            break;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (cnt[i]!=0)
        {
            printf("%d:%d\n",i,cnt[i]);
        }
        
    }
    return 0;
}