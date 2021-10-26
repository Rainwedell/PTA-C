#include<stdio.h>
#include<stdlib.h>
typedef struct APeople
{
    char name[6];
    unsigned int year;
    unsigned int month;
    unsigned int day;
}People;
int cmp(const void*a, const void* b)
{
    People* s1,* s2;
    s1=(People*)a;
    s2=(People*)b;
    long A = (s1->day)+100*(s1->month)+10000*(s1->year);
    long B = (s2->day)+100*(s2->month)+10000*(s2->year);
    return A>B? 1:-1;
     //return *(People*)a->day + *(People*)a->year * 10000 + *(People*)a->month * 100 - *(People*)b->day + *(People*)b->year *10000 + *(People*)b->month *100;
}
int main(void)
{
    int N;
    char tempName[6];
    char tempDate[11];
    long tempYear,tempMonth,tempDay;
    tempYear=tempMonth=tempDay=0;
    scanf("%d",&N);
    People S[N];
    int cnt=0;
    for (int i = 0; i < N; i++)
    {
        tempYear=tempMonth=tempDay=0;
        scanf("%s",tempName);
        scanf("%s",tempDate);
        for (int i = 0; i < 4; i++)
        {
            tempYear*=10;
            tempYear+=tempDate[i]-'0'; 
        }
        tempMonth=(tempDate[5]-'0')*10+tempDate[6]-'0';
        tempDay=(tempDate[8]-'0')*10+tempDate[9]-'0';
        if (tempYear*10000+100*tempMonth+tempDay<=20140906 && tempYear*10000+100*tempMonth+tempDay>=18140906)
        {
            S[cnt].year=tempYear;
            S[cnt].month=tempMonth;
            S[cnt].day=tempDay;
            for (int j = 0; j < 6; j++)
                S[cnt].name[j]=tempName[j];
            cnt++;
        }   
    }
    if (cnt>0)
    {
        qsort(S,cnt,sizeof(People),cmp);
        printf("%d %s %s\n",cnt,S[0].name,S[cnt-1].name);
    }
    else printf("0\n");
    
    return 0;
}
