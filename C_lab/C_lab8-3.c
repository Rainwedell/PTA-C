#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
// 大体分为两个思路，一个是使用移动文件指针直接修改目标文件的值
// 第二个是把整个文件全部读入到一个字符数组中再进行替换
// char *strReplace(char *tempstr, char *before, char *after)
// {
//     int blen = strlen(before);
//     int alen = strlen(after);
//     char *temp;
//     temp = strstr(tempstr, before);
// }
// void replace_string(char *result, char *source, char *s1, char *s2)
// {
//     char *q = NULL;
//     char *p = NULL;

//     p = source;
//     while ((q = strstr(p, s1)) != NULL)
//     {
//         strncpy(result, p, q - p);
//         result[q - p] = '\0'; // very important, must attention!
//         strcat(result, s2);
//         strcat(result, q + strlen(s1));
//         strcpy(p, result);
//     }
//     strcpy(result, p);
// }
char *strrpc(char *str, char *oldstr, char *newstr)
{
    char bstr[strlen(str)]; //转换缓冲区
    memset(bstr, 0, sizeof(bstr));
    for (int i = 0; i < strlen(str); i++)
    {
        if (!strncmp(str + i, oldstr, strlen(oldstr)))
        { //查找目标字符串
            strcat(bstr, newstr);
            i += strlen(oldstr) - 1;
        }
        else
        {
            strncat(bstr, str + i, 1); //保存一字节进缓冲区
        }
    }
    strcpy(str, bstr);
    return str;
}

void Replace1(char *filename, char *before, char *after)
{
    FILE *fp1 = NULL;
    FILE *fp2 = NULL;
    // 存储找到的数据
    char tempstr[1000];
    // int lenB = strlen(before);
    // int lenA = strlen(after);
    // 已更新模式大概原文件
    fp1 = fopen(filename, "r+");
    fp2 = fopen("out.txt", "a");

    // 使用fgets逐行遍历字符串
    while (fgets(tempstr, 200, fp1) != NULL)
    {
        // 替换字符串
        strrpc(tempstr, before, after);
        // 把替换后的字符串存进新文件
        fputs(tempstr, fp2);
    }
    fclose(fp1);
    fclose(fp2);
}

int main(int argc, char *argv[])
{
    // 确定输入参数
    if (argc != 4)
    {
        printf("wrong input");
        exit(0);
    }
    Replace1(argv[1], argv[2], argv[3]);

    return 0;
}
