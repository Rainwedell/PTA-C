#include<stdio.h>
typedef struct ONCE
    {
        char x;
        char y;
    }once;
typedef struct TYPE
{
    char a;
    int cnt;
}CNT;
CNT max(CNT A,CNT B,CNT C);
CNT max(CNT A,CNT B,CNT C)
{
    CNT M;
    M.cnt = (A.cnt>=B.cnt ? A.cnt:B.cnt)>=C.cnt ? A.cnt>=B.cnt ? A.cnt:B.cnt : C.cnt;
    if (M.cnt == A.cnt) M = A;
    else if(M.cnt == B.cnt) M = B;
    else M = C;
    return M;
    
}    
int main(void)
{
    int N;
    scanf("%d",&N);
    getchar();
    once S[N];
    int win,tie,lose;
    win = tie = lose = 0;
    once* p=S;
    CNT Xb,Xc,Xj,Yb,Yc,Yj;
    Xb.cnt = Xc.cnt =Xj.cnt = Yb.cnt =Yc.cnt = Yj.cnt = 0;
    Xb.a = Yb.a ='B';
    Xc.a = Yc.a ='C';
    Xj.a = Yj.a ='J';
    for (int i = 0; i < N; i++)
    {
        //scanf("%c %c",&(S[i].x),&(S[i].y));
        scanf("%c",&(S[i].x));
        getchar();
        scanf("%c",&(S[i].y));
        getchar();
    }
    for (int i = 0; i < N; i++)
    {
        if((p+i)->x == 'C')
        {
            if((p+i)->y == 'C') tie++;
            else if((p+i)->y == 'J')
            {
                win++;
                Xc.cnt++;
            }
            else if((p+i)->y == 'B')
            {
                lose++;
                Yb.cnt++;
            }
        }
        else if ((p+i)->x == 'B')
        {
            if((p+i)->y == 'B') tie++;
            else if((p+i)->y == 'C')
            {
                win++;
                Xb.cnt++;
            }
            else if((p+i)->y == 'J')
            {
                lose++;
                Yj.cnt++;
            }
        }
        else if ((p+i)->x == 'J')
        {
            if((p+i)->y == 'J') tie++;
            else if((p+i)->y == 'B')
            {
                win++;
                Xj.cnt++;
            }
            else if((p+i)->y == 'C')
            {
                lose++;
                Yc.cnt++;
            }
        }
    }
    printf("%d %d %d\n%d %d %d\n%c %c\n",win,tie,lose,lose,tie,win,(max(Xb,Xc,Xj).a),(max(Yb,Yc,Yj).a));
    return 0;

}