// 本关任务：编程实现
// （1）用一个单向链表接收一个长字符串，且每个节点接收一个字符，遍历输出链表中的所有字符，
// 并将字符串无冗余地存放到一个动态存储分配的的字符数组中，并且输出该字符串。
// （本题暂不考虑空字符串情况）(结尾以回车结束)
// （2）再输入一个字符，如果该字符已在链表中，则删除该结点，
// 否则在输入字符和结点的数据域字符差值最小的结点后面插入包含该字符的结点，输出最后的字符串。

// 要求：采用模块化设计方法，将创建链表、遍历链表、删除结点、插入结点等功能用函数实现。

#include <stdio.h>
#include <malloc.h>

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
// Node *TraverseList(Node *head)
// {
// }
// Node *InsertList(Node *head, char c)
// {
// }
// Node *DelectList(Node *head, char c)
// {
// }
int main(void)
{
    char c;
    Node *head = NULL;
    // Node *p; // 指向当前创建的结点
    // Node *q; //指向上一个结点
    while ((c = getchar()) != '\n')
    {
        CreateList(head, c);
    }
    return 0;
}