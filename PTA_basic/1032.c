#include<stdio.h>
int main(void)
{
    int N;
    scanf("%d",&N);
    int SUM[N];
    for (int i = 0; i < N; i++)
    {
        SUM[i]=0;
    }
    
    //SUM[N]={0};           qing思考这个为什么不行
    //第三次git提交测试改动注释
    int school,score,maxNumber,maxschool;
    maxschool = 1,maxNumber=1;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d",&school,&score);
        if(maxschool<school)    maxschool=school;
        SUM[school]+=score;
    }
    for (int i = 1; i <= maxschool; i++)
    {
        if(SUM[0]<SUM[i])
        {
            SUM[0]=SUM[i];
            maxNumber = i;
        }
    }
    printf("%d %d\n",maxNumber,SUM[0]);
    return 0;
}