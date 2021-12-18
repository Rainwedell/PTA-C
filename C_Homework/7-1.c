#include <stdio.h>
/**********  Begin  **********/
struct date
{
    int year;
    int month;
    int day;
};
int main()
{
    struct date aday;
    int MONTH[] = {29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d %d %d", &aday.year, &aday.month, &aday.day);
    if (aday.year > 0 && aday.month > 0 && aday.month <= 12 && aday.day > 0 && aday.day <= 31)
    {
        switch (aday.month)
        {
        case 2:
            if (((aday.year % 4 == 0 && aday.year % 100 != 0) || aday.year % 400 == 0))
            {
                if (aday.day > 29)
                {
                    printf("不存在这样的日期\n");
                    return 0;
                }
            }
            else if (aday.day > 28)
            {
                printf("不存在这样的日期\n");
                return 0;
            }
        case 4:
        case 6:
        case 9:
        case 11:
            if (aday.day > 30)
            {
                printf("不存在这样的日期\n");
                return 0;
            }
            break;

        default:
            break;
        }
        int sum = 0;

        for (int i = 1; i < aday.month; i++)
            sum += MONTH[i];
        sum += aday.day;
        if (aday.month > 2 && ((aday.year % 4 == 0 && aday.year % 100 != 0) || aday.year % 400 == 0))
            sum++;
        printf("%d\n", sum);
    }
    else
    {
        printf("不存在这样的日期\n");
        return 0;
    }

    /**********   End   **********/
}