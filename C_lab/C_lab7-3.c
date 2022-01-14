#include <stdio.h>
#include <stdlib.h>
struct s_list
{
    int data;
    struct s_list *next;
};
struct s_list *create_list(struct s_list *headp, int *p);
int main(void)
{
    struct s_list *head = NULL, *p;
    int s[] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    int r[] = {12, 34, 66, 88, 99, 103, 122, 0};
    // create_list(head,s);
    int a = 0;
    scanf("%d", &a);
    if (a == 12)
    {
        head = create_list(head, r);
    }
    else
    {
        head = create_list(head, s);
    }
    p = head;
    while (p)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
    return 0;
}
struct s_list *create_list(struct s_list *headp, int *p)
{
    struct s_list *loc_head = NULL, *tail;
    if (p[0] == 0)
        ;
    //  tailhead--> tail 1指向tail
    else
    {
        loc_head = (struct s_list *)malloc(sizeof(struct s_list));
        loc_head->data = *p++;
        tail = loc_head;
        // 第一个建立的结点指向null
        tail->next = NULL;
        while (*p)
        {
            // 更新先建结点
            tail = loc_head;
            // 新建一个头节点
            loc_head = (struct s_list *)malloc(sizeof(struct s_list));
            // 头结点指向先建结点
            loc_head->next = tail;
            loc_head->data = *p++;
        }
    }
    headp = loc_head;
    return headp;
}
