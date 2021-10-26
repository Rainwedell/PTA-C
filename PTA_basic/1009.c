#include<stdio.h>
#define STLEN 80

int main(void)
{
    char c[STLEN];
    fgets(c,STLEN,stdin);
    char b[STLEN];
    int cnt = 0;
    for (int i = STLEN-1; i >= 0; i--)
    {
        
        cnt++;
        if (c[i] = ' ')
        {
            int j;
            for (int j =0 ; j < cnt-1; j++)
            {
                b[j] = c[i+1+j];
            }
            cnt = 0;
        }
        
    }
    
}