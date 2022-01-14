#include <stdio.h>
#include <malloc.h>
#include <string.h>
// 本题在设计上最好的做法是把平均值加入数据结构。但题目没有明确要求,
typedef struct grades
{
    char Number[11];
    char Name[80];
    int English;
    int Math;
    int Physics;
    int C;
    struct grades *next;
} Student;
// 交换结点域
Student *swap(Student *p, Student *loc_head)
{
    Student *tail = loc_head;
    if (tail != p)
    {
        while (tail->next != p)
        {
            tail = tail->next;
        }
        Student *temp = p->next;
        tail->next = p->next;
        p->next = temp->next;
        temp->next = p;
    }
    else
    {
        Student *temp = tail->next;
        tail->next = tail->next->next;
        temp->next = tail;
        loc_head = temp;
    }
    return loc_head;
}
// 按平均成绩升序排序算法 冒泡
Student *avgSort(Student *loc_head, int cnt)
{
    Student *tail = loc_head;
    for (int i = 0; i < cnt - 1; i++)
    {
        tail = loc_head;
        for (int j = 0; j < cnt - i - 1; j++)
        {
            double p = (tail->English + tail->Math + tail->Physics + tail->C) / 4.0;
            double q = (tail->next->English + tail->next->Math + tail->next->Physics + tail->next->C) / 4.0;
            if (p > q)
                loc_head = swap(tail, loc_head);
            else
                tail = tail->next;
        }
    }
    return loc_head;
}
// 输入数据项内容
Student *InputData(Student *loc_head)
{
    int cnt;
    scanf("%d", &cnt);
    if (cnt <= 0)
        printf("Wrong Number Input");

    else
    {
        Student *tail;
        if (loc_head == NULL)
        {
            // 建立头指针 但未赋值
            loc_head = (Student *)malloc(sizeof(Student));
            tail = loc_head;
        }
        else
        {
            // 找到最后一个指针，并在后面先新建一个指针
            tail = loc_head;
            while (tail->next != NULL)
            {
                tail = tail->next;
            }
            tail->next = (Student *)malloc(sizeof(Student));
            tail = tail->next;
        }

        for (int i = 0; i < cnt; i++)
        {
            scanf("%s", tail->Number);
            scanf("%s", tail->Name);
            scanf("%d", &tail->English);
            scanf("%d", &tail->Math);
            scanf("%d", &tail->Physics);
            scanf("%d", &tail->C);
            if (i < cnt - 1)
            {
                tail->next = (Student *)malloc(sizeof(Student));
                tail = tail->next;
            }
            else
                tail->next = NULL;
        }
    }
    // 直接按照平均值进行升序排序
    loc_head = avgSort(loc_head, cnt);
    return loc_head;
}

// 输出 数据项内
void OutputData(Student *loc_head)
{
    Student *tail = loc_head;
    while (tail != NULL)
    {
        printf("%s %s %d %d %d %d\n", tail->Number, tail->Name, tail->English, tail->Math, tail->Physics, tail->C);
        tail = tail->next;
    }
}
// 查找指定学号
Student *Search(Student *loc_head, char *number)
{
    Student *tail = loc_head;
    while (tail != NULL)
    {
        if (strcmp(tail->Number, number) == 0)
            return tail;
        tail = tail->next;
    }
    return NULL;
}
// 修改指定学号学生成绩
Student *ChangeGrades(Student *loc_head)
{
    // 目标学号
    char number[11];
    scanf("%s", number);
    Student *aim_stduent = Search(loc_head, number);
    if (aim_stduent == NULL)
    {
        printf("Cant Find The Number\n");
        return loc_head;
    }
    // 修改成绩序号
    int option, grade;
    scanf("%d %d", &option, &grade);
    switch (option)
    {
    case 1:
        aim_stduent->English = grade;
        break;
    case 2:
        aim_stduent->Math = grade;
        break;
    case 3:
        aim_stduent->Physics = grade;
        break;
    case 4:
        aim_stduent->C = grade;
        break;

    default:
        break;
    }
    return loc_head;
}
// 计算平均成绩
double *AvgGrades(Student *loc_head)
{
    int cnt = 0;
    Student *tail = loc_head;
    while (tail != NULL)
    {
        cnt++;
        tail = tail->next;
    }
    tail = loc_head;
    double *avg = (double *)malloc(sizeof(double) * cnt);
    for (int i = 0; i < cnt; i++)
    {
        *(avg + i) = (tail->English + tail->Math + tail->Physics + tail->C) / 4.0;
        printf("%s %s %.2f\n", tail->Number, tail->Name, *(avg + i));
        tail = tail->next;
    }
    return avg;
}
// 输出总成绩和平均成绩
void OutGrades(Student *loc_head)
{
    Student *tail = loc_head;
    int cnt = 0;
    while (tail != NULL)
    {
        printf("%s %s %d %.2f\n", tail->Number, tail->Name, tail->English + tail->Math + tail->Physics + tail->C, (tail->English + tail->Math + tail->Physics + tail->C) / 4.0);
        tail = tail->next;
        cnt++;
    }
}
int main(void)
{
    int input = -1;
    double *Avg;
    Student *head = NULL;
    while (input != 0)
    {
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            head = InputData(head);
            break;
        case 2:
            OutputData(head);
            break;
        case 3:
            ChangeGrades(head);
            break;
        case 4:
            Avg = AvgGrades(head);
            break;
        case 5:
            OutGrades(head);
            break;
        case 0:
            return 0;
            break;

        default:
            break;
        }
    }
    return 0;
}