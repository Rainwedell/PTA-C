#include<stdio.h>
#include<stdlib.h>
typedef struct Amooncake
{
    double s;
    double total;
}mooncake;
void Sort(mooncake x[],int N);
int cmp( const void *a , const void *b );
int cmp( const void *a , const void *b )
{
    mooncake* c =(mooncake*) a;
    mooncake* d =(mooncake*) b;
    if((c->total/c->s)<(d->total/d->s)) return 1;
    else return -1;
}
void Sort(mooncake x[],int N)
{
    qsort(x,N,sizeof(mooncake),cmp);
}
int main(void)
{
    int D,N,supply;
    double Income = 0;
    supply = 0;
    scanf("%d %d",&N,&D);
    mooncake S[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%lf",(&S[i].s));
        //scanf("%lf",(&S[i].total));
    }
    for (int i = 0; i < N; i++)
    {
        //scanf("%lf",(&S[i].s));
        scanf("%lf",(&S[i].total));
    }
    Sort(S,N);
    for (int i = 0; i < N; i++)
    {
        if (supply+S[i].s <= D)
        {
            supply+=S[i].s;
            Income+=S[i].total;
        }
        else
        {
            Income+=(D-supply)*(S[i].total/S[i].s);
            break;
        }
        
    }
    printf("%.2f\n",Income);
    return 0;

}