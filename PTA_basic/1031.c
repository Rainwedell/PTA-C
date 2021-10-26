#include<stdio.h>
typedef struct Number
{
    char A[18];
    int state;
}num;
void NotRight(num* x,int lenth)
{
    int a[17];
    for (int j = 0; j < lenth; j++)
    {
        for (int i = 0; i < 17; i++)
        {
            if(((x+j)->A[i])>='0'&& ((x+j)->A[i])<='9')
            {
                a[i]=(x+j)->A[i]-'0';
            }
            else 
            {
                (x+j)->state=1;
                break;
            }   
        }
        if((x+j)->state==0)
        {
            int z;
            z=(7*a[0]+9*a[1]+10*a[2]+5*a[3]+8*a[4]+4*a[5]+2*a[6]+a[7]+6*a[8]+3*a[9]+7*a[10]+9*a[11]+10*a[12]+5*a[13]+8*a[14]+4*a[15]+2*a[16])%11;
            switch (z)
            {
            case 0:
                if((x+j)->A[17]  !='1')    (x+j)->state = 1;
                break;
            case 1:
                if((x+j)->A[17]  !='0')    (x+j)->state = 1;
                break;    
            case 2:
                if((x+j)->A[17]  !='X')    (x+j)->state = 1;
                break;
            case 3:
                if((x+j)->A[17]  !='9')    (x+j)->state = 1;
                break;
            case 4:
                if((x+j)->A[17]  !='8')    (x+j)->state = 1;
                break;
            case 5:
                if((x+j)->A[17]  !='7')    (x+j)->state = 1;
                break;
            case 6:
                if((x+j)->A[17]  !='6')    (x+j)->state = 1;
                break;
            case 7:
                if((x+j)->A[17]  !='5')    (x+j)->state = 1;
                break;
            case 8:
                if((x+j)->A[17]  !='4')    (x+j)->state = 1;
                break;
            case 9:
                if((x+j)->A[17]  !='3')    (x+j)->state = 1;
                break;
            case 10:
                if((x+j)->A[17]  !='2')    (x+j)->state = 1;
                break;
                                                
            default:
                break;
            }
        }
    }
}  
int main(void)
{
    int N,cnt;
    cnt = 0;
    scanf("%d",&N);
    num X[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%s",X[i].A);
        X[i].state = 0;
    }
    NotRight(X,N);
    for (int i = 0; i < N; i++)
    {
        if(X[i].state == 1) 
        {
            printf("%s\n",X[i].A);
            cnt++;
        }
    }
    if(cnt==0)  printf("All passed\n");
    return 0;
}