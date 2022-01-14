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
    else
    {
        loc_head = (struct s_list *)malloc(sizeof(struct s_list));
        loc_head->data = *p++;
        tail = loc_head;
        while (*p)
        {
            tail->next = (struct s_list *)malloc(sizeof(struct s_list));
            tail = tail->next;
            tail->data = *p++;
        }
        tail->next = NULL;
    }
    headp = loc_head;
    return headp;
}
