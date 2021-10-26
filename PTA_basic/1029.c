#include<stdio.h>
#include<stdlib.h>
void RemoveReptition(char a[],int strlen)//这里sterlen不包括'\0'
{
    for (int i = 0; i <= strlen; i++)   //从a[i]开始
    {
        for (int j = i+1; j <= strlen; j++)//把a[i+1]到最后一个字符
        {
            if(a[i]==a[j])//都和a[i]比较，如果一样
            {
                for (int k = j; k <= strlen; k++)//删除那个字符，即把后面字符全部左移一位
                {
                    a[k]=a[k+1];//即把后面字符全部左移一位
                }
                strlen--;//此时字符串长度-1
                j--;//这里的j--和循环外的j++一起保证删除后的比较起点不变，每个数都能比较到，因为后面左移了一位，此时a[j]代指的是原来a[j+1]
            }
        }
        
    }
    a[strlen+1]='\0';
}
int main(void)
{
    char ShouldInput[81],RealInput[81],LackInput[81];
    int cnt = 0;
    scanf("%s",ShouldInput);
    scanf("%s",RealInput);
    // for (int i = 0; RealInput[i] !=   '\0'; )
    // {
    //     static int j = 0;
        
    //     if (RealInput[i]!=ShouldInput[j])
    //     {
    //         LackInput[cnt]=ShouldInput[j];
    //         cnt++;
    //         LackInput[cnt]='\0';
    //     }
    //     else    i++;
    //     j++;
    // }
    //这两个的边界判断区别
    for (int  i = 0; ShouldInput[i] != '\0'; i++)
    {
        static int j = 0;
        if (RealInput[j]!=ShouldInput[i])
        {
            LackInput[cnt]=ShouldInput[i];
            cnt++;
            LackInput[cnt]='\0';
        }
        else    j++;
    }
    
    for (int i = 0; i < cnt; i++)
    {
        if(LackInput[i]>=97&&LackInput[i]<=122)
            LackInput[i]-=32;
    }
    RemoveReptition(LackInput,cnt);
    printf("%s\n",LackInput);

    // for (int i = 0; LackInput[i+1] != '\0'; i++)
    // {
    //     if(LackInput[i+1]!=LackInput[i])
    //         printf("%c",LackInput[i]);
    // }
    //printf("%c\n",LackInput[cnt-1]);

    return 0;
}