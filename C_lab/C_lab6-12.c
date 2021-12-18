#include <stdio.h>
#include <string.h>
void task0(void)
{
    printf("task0 is called!\n");
}
void task1(void)
{
    printf("task1 is called!\n");
}
void task2(void)
{
    printf("task2 is called!\n");
}
void task3(void)
{
    printf("task3 is called!\n");
}
void task4(void)
{
    printf("task4 is called!\n");
}
void task5(void)
{
    printf("task5 is called!\n");
}
void task6(void)
{
    printf("task6 is called!\n");
}
void task7(void)
{
    printf("task7 is called!\n");
}
void task8(void)
{
    printf("task8 is called!\n");
}
// void execute(void (*ptr[])(void), int N)
void execute(void (**ptr)(void), int N)
{
    for (int i = 0; i < N; i++)
    {
        // ptr[i]();
        (*(ptr+i))();
    }
}
void scheduler(char *c)
{
    int cnt = strlen(c);
    void (*ptr[cnt])(void);
    for (int i = 0; i < cnt; i++)
    {
        // switch (c[i])
        // {
        // case '0':
        //     ptr[i] = task0;
        //     break;
        // case '1':
        //     ptr[i] = task1;
        //     break;
        // case '2':
        //     ptr[i] = task2;
        //     break;
        // case '3':
        //     ptr[i] = task3;
        //     break;
        // case '4':
        //     ptr[i] = task4;
        //     break;
        // case '5':
        //     ptr[i] = task5;
        //     break;
        // case '6':
        //     ptr[i] = task6;
        //     break;
        // case '7':
        //     ptr[i] = task7;
        //     break;
        // default:
        //     break;
        // }
        switch (*(c+i))
        {
        case '0':
            *(ptr+i) = task0;
            break;
        case '1':
            *(ptr+i) = task1;
            break;
        case '2':
            *(ptr+i) = task2;
            break;
        case '3':
            *(ptr+i) = task3;
            break;
        case '4':
            *(ptr+i) = task4;
            break;
        case '5':
            *(ptr+i) = task5;
            break;
        case '6':
            *(ptr+i) = task6;
            break;
        case '7':
            *(ptr+i) = task7;
            break;
        default:
            break;
        }
    }

    execute(ptr, cnt);
}

int main(void)
{
    char num[1000];
    gets(num);
    scheduler(num);
    return 0;
}