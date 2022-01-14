// /*测试程序定义了如下结点类型
#include <malloc.h>
#include <stdio.h>
#include <string.h>
typedef struct c_node
{
    char data;
    struct c_node *next;
} C_NODE;
void createLinkList(C_NODE **headp, char s[])
{
    /************************************* BEGIN *******************************************/
    // 建立头结点
    (*headp) = (C_NODE *)malloc(sizeof(C_NODE));
    C_NODE *tail = (*headp);
    tail->data = s[0];
    tail->next = NULL;
    // 不是空字符串的情况
    if (s[0] != '\0')
    {
        int cnt = 0;
        while (*(s + cnt + 1) != '\0')
        {
            tail->data = *(s + cnt);
            tail->next = (C_NODE *)malloc(sizeof(C_NODE));
            cnt++;
            tail = tail->next;
        }
        tail->data = *(s + cnt);
        tail->next = NULL;
    }
    // C_NODE *tail = (*headp);
    // int cnt = 0;
    // while(*(s+cnt)!='\0')
    // {
    //     tail
    // }
    /************************************* BEGIN *******************************************/
}

void judgePalindrome(C_NODE *head)
{
    /************************************* BEGIN *******************************************/
    if (head->data == '\0')
        printf("true\n");
    else
    {
        int cnt = 1;
        C_NODE *tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
            cnt++;
        }
        tail = head;
        char *a = (char *)malloc(sizeof(char) * cnt + 1);
        for (int i = 0; i < cnt; i++)
        {
            *(a + i) = tail->data;
            tail = tail->next;
        }
        *(a + cnt) = '\0';
        int len = strlen(a);
        int state = 0;
        for (int i = 0; i < (len - 1) / 2; i++)
        {
            if (*(a + i) != *(a + len - 1 - i))
                state = 1;
        }
        if (state == 1)
            printf("flase\n");
        else
            printf("true\n");
        free(a);
    }
    /************************************* BEGIN *******************************************/
}

int main(void)
{
    char s[1000], *pc = s;
    int len = 0;
    C_NODE *head, *p;
    scanf("%[^\n]", s);
    createLinkList(&head, s);
    for (p = head; p; p = p->next)
        len++;
    if (len != strlen(s))
    {
        printf("单链表长度不正确");
        return 1;
    }
    else
        for (p = head; p; p = p->next)
            if (p->data != *pc++)
            {
                printf("单链表有错误结点");
                return 1;
            }
    judgePalindrome(head);
    return 1;
}
// *******************************/
