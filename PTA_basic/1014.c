//3485djDkxh4hhGE
//2984akDfkkkkggEdsb
//s&hgsfdk 
//d&Hyscvnm

//3485djDkxh4hhGE 
//2984akDfkkkkggEdsb 
//s&hgsfdk 
//d&Hyscvnm

#include<stdio.h>
#include<string.h>
void WeekAndHour(const char* s1,const char* s2);
//int Hour(const char* s1,const char* s2);
void Minute(const char* s1,const char* s2);
void WeekAndHour(const char* s1,const char* s2)
{
    int Lenth,week,hour;
    if(strlen(s1)>strlen(s2))   Lenth = strlen(s1);
    else Lenth = strlen(s2);
    for (int i = 0; i <= Lenth; i++)
    {
        if (s1[i]==s2[i]&&s1[i]>='A'&&s1[i]<='G')
        {
            week = i;
            break;
        }
    }
    //hour = week;
    for (int i = week+1; i <=Lenth; i++)
    {
        if (s1[i]==s2[i]&&((s1[i]>='A'&&s1[i]<='N')||(s1[i]>='0'&&s1[i]<='9')))
        {
            hour = i;
            break;
        }
    }
    switch (s1[week]-'A'+1)
    {
    case 1:
        printf("MON");
        break;
    case 2:
        printf("TUE");
        break;
    case 3:
        printf("WED");
        break;
    case 4:
        printf("THU");
        break;
    case 5:
        printf("FRI");
        break;
    case 6:
        printf("SAT");
        break;
    case 7:
        printf("SUN");    
        break;
    default:
        break;
    }
    //s[week]-'A'+1;
    //printf("\nweek=%d,hour=%d,%c\n",week,hour,s1[hour]);
    //
    printf(" ");
    if (s1[hour]>='0'&&s1[hour]<='9')
    {
        printf("0%c",s1[hour]);
    }
    else printf("%02d",s1[hour]-'A'+10);
}
void Minute(const char* s1,const char* s2)
{
      int Lenth,minute;
    if(strlen(s1)>strlen(s2))   Lenth = strlen(s1);
    else Lenth = strlen(s2);
    for (int i = 0; i < Lenth; i++)
    {
        if (s1[i]==s2[i]&&((s1[i]>='A'&&s1[i]<='Z')||(s1[i]>='a'&&s1[i]<='z')))
        {
            minute = i;
            break;
        }
    }
    printf("%02d",minute);
}
int main(void)
{
    char str1[60],str2[60],str3[60],str4[60];
    scanf("%s",str1);
    scanf("%s",str2);
    scanf("%s",str3);
    scanf("%s",str4);
    WeekAndHour(str1,str2);
    printf(":");
    Minute(str3,str4);
    return 0;
}