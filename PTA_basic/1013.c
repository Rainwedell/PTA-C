#include<stdio.h>
#include<math.h>
int Notprime(int x);
int Notprime(int x)
{
    int state = 0;
    for (int i = 2; i <= sqrt(x); i++)
    {
       
        if(x%i == 0)  state = 1 ;
    }
    return state;
}
int main(void)
{
    int a[10000],M,N;
    a[0] = 2;
    a[1] = 3;
    int x = 5;
    for (int i = 2; i < 10000; x+=2)
    {
        if(!Notprime(x))  
        {
            a[i] = x;
            i++;
        }
    }
    scanf("%d %d",&M,&N);
    for (int i = M-1; i < N; i++)
    {
        static int cnt = 0;
        cnt++;
        //printf("%d",a[i]);
        if(cnt<N-M+1)
        {
            if(cnt%10 != 0)    printf("%d ",a[i]);
            else if(cnt%10 == 0)    printf("%d\n",a[i]);
        }
        else if(cnt == N-M+1) printf("%d",a[i]);


        //else if(cnt%10 != 0)    printf("%d ",a[i]);
        //else if(cnt%10 == 0)    printf("%d\n",a[i]);
    }
    
    
}