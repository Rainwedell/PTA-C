
#include <stdio.h>
#include<string.h>
int main(void)
{
    char A[1000];
    char N[20000];
    scanf("%s",A);
    int END;
    END = strlen(A);
    int position;
    int endNumber;
    for ( int i = 4; i != '\0'; i++)
    {
        if (A[i]=='E')
        {
            endNumber=i-1;
            break;
        }
        
    }
    int exp=0;
    int val=(endNumber-3)+1;
    for (int i = endNumber+3; i <= END-1; i++)
    {
        exp*=10;
        exp+=A[i]-'0';
    }
    printf("\nexp = %d\n",exp);
    position=0;
    N[0]=A[0];
    position=1;
    
    if (A[endNumber+2]=='-'&&exp!=0)
    {
        
        N[1]='0';
        N[2]='.';
        position=3;
        for (int i = 0; i < exp-1; i++)
        {
            N[i+3]='0';
            position++;
        }
        N[position]=A[1];
        position++;
        for (int i = 0; i < val; i++)
        {
            N[position]=A[i+3];
            position++;
        }
        N[position]='\0'; 
    }
    else 
    {
        N[1]=A[1];
        position++;
        if (exp>=val)
        {
            for (int i = 0; i < val; i++)
            {
                N[position]=A[i+3];
                position++;
            }
            for (int i = 0; i < exp-val; i++)
            {
                N[position]='0';
                position++;
            }
        }
        else
        {
            int i;
            for ( i = 0; i < exp; i++)
            {
                N[position]=A[i+3];
                position++;
            }
            N[position]='.';
            position++;
            for (; i < val; i++)
            {
                 N[position]=A[i+3];
                position++;
            }
        }
        N[position]='\0';
    }
    if(N[0]=='+')   printf("%s\n",N+1);
    else    printf("%s\n",N); 
    return 0;
    

}