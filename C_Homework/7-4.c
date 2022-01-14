// 本关任务：编程实现
// （1）用一个单向链表接收一个长字符串，且每个节点接收一个字符，遍历输出链表中的所有字符，
// 并将字符串无冗余地存放到一个动态存储分配的的字符数组中，并且输出该字符串。
// （本题暂不考虑空字符串情况）(结尾以回车结束)
// （2）再输入一个字符，如果该字符已在链表中，则删除该结点，
// 否则在输入字符和结点的数据域字符差值最小的结点后面插入包含该字符的结点，输出最后的字符串。

// 题目缺陷，未明确2中多个结点满足时是否插入多个结点，还是插入第一个||最后一个满足要求的结点

// 要求：采用模块化设计方法，将创建链表、遍历链表、删除结点、插入结点等功能用函数实现。

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
typedef struct node
{
    char data;
    struct node *next;
} Node;

Node *CreateList(Node *head, char c)
{
    Node *p;               // 指向当前创建的结点
    static Node *q = NULL; //指向上一个结点
    p = (Node *)malloc(sizeof(Node));
    p->data = c;
    p->next = NULL;
    if (head == NULL)
        head = p;
    else
        q->next = p;
    q = p;

    return head;
}
// 遍历并储存给数组
char *TraverseList(Node *head, int print)
{
    Node *p = head;
    char *arryList;
    int cnt = 0;
    if (p == NULL)
        return NULL;
    // 统计字符数
    while (p != NULL)
    {
        // 标准用例也做得是个锤子
        // if (print)
        // {
        //     printf("%c", p->data);
        //     if (p->next != NULL)
        //         printf(" ");
        // }
        if (print)
        {
            printf("%c ", p->data);
        }
        p = p->next;
        cnt++;
    }
    // 多一个存'\0'
    arryList = (char *)malloc(sizeof(char) * (cnt + 1));
    // 指定字符数组大小 第二种
    // char arryList[cnt+1];
    for (cnt = 0, p = head; p != NULL; p = p->next, cnt++)
        *(arryList + cnt) = p->data;
    *(arryList + cnt) = '\0';
    return arryList;
}
//尾端插入
Node *InsertList(Node *head, char c)
{
    if (head == NULL)
        CreateList(head, c);
    else
    {
        Node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        Node *newElement = (Node *)malloc(sizeof(Node));
        newElement->data = c;
        newElement->next = NULL;
        p->next = newElement;
    }
    return head;
}

// 题目要求的插入
// ghjkl  i
// ghijkl
// 注意题目并不严谨，此函数从最后一个满足要求的结点后面开始插入
Node *InsertList2(Node *head, char c)
{
    if (head == NULL)
        CreateList(head, c);
    else
    {
        Node *p = head;
        Node *min = head; //追踪差值最小的指针
        while (p->next != NULL)
        {
            // 评测系统不让用abs
            // if (abs(c - p->data) <= abs(c - min->data))
            // {
            //     min = p;
            // }
            if ((c - p->data) * (c - p->data) <= (c - min->data) * (c - min->data))
            {
                min = p;
                // if (min - p->data == 1) //稍微提高速度
                //     break;
            }
            p = p->next;
        }
        Node *newElement = (Node *)malloc(sizeof(Node));
        newElement->data = c;
        newElement->next = min->next;
        min->next = newElement;
    }
    return head;
}
// 寻找数据对应的结点地址
Node *Search(Node *head, char c)
{
    Node *p = head;
    if (p == NULL)
        printf("Wrong list(head=NULL)\n");
    while (p != NULL)
    {
        if (p->data == c)
            return p;
        p = p->next;
    }
    return p;
}
// 给出目标结点地址的删除 单向链表需要遍历，和下面复杂度没有区别，双向链表不需要遍历
Node *DelectList(Node *head, Node *aimPointer)
{
    Node *p = head;
    if (p == NULL)
    {
        printf("Wrong list(head=NULL)\n");
        return head;
    }
    if (p == aimPointer)
    {
        head = aimPointer->next;
        free(p);
        return head;
    }
    while (p->next != aimPointer)
    {
        p = p->next;
    }
    p->next = aimPointer->next;

    free(aimPointer);
    return head;
}

// 根据数据找寻删除结点的遍历
Node *DelectList2(Node *head, char c)
{
    Node *p = head;
    if (p == NULL)
    {
        printf("Wrong list(head=NULL)\n");
        return head;
    }
    Node *delectPointer;
    while (p->next->data != c)
    {
        p = p->next;
    }
    delectPointer = p->next;
    p->next = delectPointer->next;
    free(delectPointer);
    return head;
}
int main(void)
{
    char c;
    Node *head = NULL;
    // Node *p; // 指向当前创建的结点
    // Node *q; //指向上一个结点
    while ((c = getchar()) != '\n')
    {
        head = CreateList(head, c);
    }

    c = getchar();
    char *arryList = TraverseList(head, 1);
    // printf("Test:  arryList,Len:%d\n", (int)strlen(arryList));
    printf("\n%s\n", arryList);
    Node *q = Search(head, c);
    if (q == NULL)
        head = InsertList2(head, c);
    else
        head = DelectList(head, q);
    free(arryList);
    arryList = TraverseList(head, 0);
    printf("%s\n", arryList);

    return 0;
}