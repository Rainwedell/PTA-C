#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define SIZE 1000
int Lenth;
// 这里因为是递归，每调用一次就删除一次再对新串进行遍历，
// 如果出现 串 abcaabb 删除 子串为 ab
// 正确答案为cab 但在递归调用下会变成 c;
// 解决办法 ：尝试在每次递归调用时仅对每一新子串标记，最后根据标记一起删除
int delSubstr(char *str, char *substr)
{

    int Len = (int)strlen(str);
    int sublen = (int)strlen(substr);
    // 子串长度不能大于主串
    if (Lenth < sublen)
        return 0;
    // 找到第一个子串
    char *firstSub = strstr(str, substr);
    // 找不到第一个子串时
    if (firstSub == NULL)
    {
        if (strlen(str) == Lenth) //未作删除
            return 0;
        else
            return 1;
    }
    else
    {
        // 执行删除操作  这里用strcpy函数实现其实更简洁
        // strcpy(firstSub,(firstSub+sublen));
        int i;
        for (i = 0; *(firstSub + i + sublen) != '\0'; i++)
        {
            *(firstSub + i) = *(firstSub + i + sublen);
        }
        // '\0'字符串结束标志也拿过去
        *(firstSub + i) = *(firstSub + i + sublen);
        // return (delSubstr(str, substr));
        return (delSubstr(firstSub, substr));
    }
}

// int delSubstr2(char *str, char *substr)
// {

//     int Len = (int)strlen(str);
//     int sublen = (int)strlen(substr);
//     // 标记主串除'\0'外的每一个字符
//     // int pos[Len] = {0};
//     // 子串长度不能大于主串
//     if (Lenth < sublen)
//         return 0;
//     // 找到第一个子串
//     char *firstSub = strstr(str, substr);
//     if (firstSub ==NULL)    return 0;
//     // 找不到第一个子串时
//     do
//     {
//         // 删除找到的子串
//         int i;
//         for (i = 0; *(firstSub + i + sublen) != '\0'; i++)
//         {
//             *(firstSub + i) = *(firstSub + i + sublen);
//         }
//         // '\0'字符串结束标志也拿过去
//         *(firstSub + i) = *(firstSub + i + sublen);
//         pos++;
//         firstSub = strstr(firstSub,substr);
//     } while (firstSub!=NULL);

int main(void)
{
    char str[SIZE], substr[SIZE];
    // fgets(str, 1000, stdin);
    gets(str);
    // fgets(substr, 1000, stdin);
    gets(substr);
    Lenth = strlen(str);
    int state = delSubstr(str, substr);
    printf("%s\n%d", str, state);
    return 0;
}
