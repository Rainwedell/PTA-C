#include <stdio.h>
int main()
{
    int x, y, flag; //flag是用来判断是否是第一项，即是否需要输出前导空格(因为题目要求最后一个数字后面没有空格)
    flag = 0;
    while(~scanf("%d%d", &x, &y))
    {
         //注意特判输出的结束，因为scanf未读入数据是返回-1，而~(-1) == 0，所以只要是正常读入该式子就不为0，即循环继续
        if(y == 0) //指数y等于0说明已经到了常数项，循环即可停止了
            break;
        printf("%s%d %d", flag ? " " : "" , x * y, y - 1); //因为读入的是非零项，所以系数x不为0，根据幂函数求导法则知求导后系数为原系数 * 指数，指数-1
        flag++; //每输出一次flag + 1
    }
    if(!flag) //!flag等价于flag == 0，若此式成立，则前面一次都没输出，即输入的是“零多项式”，根据题目要求指数和系数都为0
        printf("0 0");
    return 0;
}


/*
#include<stdio.h>
int main(void)
{
    int a[1010] = {0};
    int end = 0;
    for (int i = 0; i < 1010; i++)
    {
        scanf("%d",&a[i]);
        if (a[i] == 0)
        {
            end = i;
            break;
        }
        
    }
    if(a[0] == 0)   printf("0 0\n");
    else
    {
        for (int i = 0; i <= end-1 ; i+=2)
        {
            a[i] = a[i]*a[i+1];
            a[i+1] -= 1;
            if (a[i+1] == 0)
            {
                end = i+1;
                break;
            }
            
        }
        for (int i = 0; i < end; i++)
        {
            printf("%d ",a[i]);
        }
        printf("%d",a[end]);
    }
    return 0;
}
*/