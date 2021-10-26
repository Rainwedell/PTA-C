#include<stdio.h>
#include<stdlib.h>
int* kaprekar(int S[]);
int decreaseSort(int S[]);
int increaseSort(int S[]);
int cmp1(const void *a, const void *b);
int cmp2(const void *a, const void *b);
int* kaprekar(int S[])
{
    int N = S[0]*1000+S[1]*100+S[2]*10+S[3];
    //int increase,decrease;
    if (N != 6174)
    {
        printf("%04d - %04d = %04d\n",decreaseSort(S),increaseSort(S),decreaseSort(S)-increaseSort(S));
        N = decreaseSort(S)-increaseSort(S);
        for (int i = 3; i >=0; i--)
        {
            S[i] = N%10;
            N/=10;
        }
        
        return kaprekar(S);
    }
    else return S;
}

int decreaseSort(int S[])
{
    qsort(S,4,sizeof(int),cmp1);
    return (S[0]*1000+S[1]*100+S[2]*10+S[3]);
}
int increaseSort(int S[])
{
    qsort(S,4,sizeof(int),cmp2);
    return (S[0]*1000+S[1]*100+S[2]*10+S[3]);
}
int cmp1(const void *a, const void *b)
{
    return(*(int*)b - *(int*)a);
}
int cmp2(const void *a, const void *b)
{
    return(*(int*)a - *(int*)b);
}


int main(void)
{
    int N;
    int S[4];
    scanf("%d",&N);
    int t = N;
    for (int i = 3; i >=0; i--)
        {
            S[i] = t%10;
            t/=10;
        }
    if (S[0]==S[1]&&S[2]==S[3]&&S[1]==S[2])
    {
        printf("%04d - %04d = 0000",N,N);
    }
    else if (N == 6174)
    {
        printf("7641 - 1467 = 6174\n");
    }
    else
    {
        //for (int i = 0; i < 4; i++)
        //{
       //     S[i] = N[i]-'0';
       // }
        kaprekar(S);
    }
    return 0;

    

}