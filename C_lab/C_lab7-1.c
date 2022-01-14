#include <stdio.h>
int main(void)
{
    char u[] = "UVWXYZ", v[] = "xyz";
    struct T
    {
        int x;
        char c;
        char *t;
    } a[] = {{11, 'A', u}, {100, 'B', v}}, *p = a;
    int input;
    scanf("%d", &input);
    switch (input)
    {
    case 1:
        printf("%d\n", (++p)->x);
        // 100
        break;
    case 2:
        p++;
        printf("%c\n", p->c);
        break;
    case 3:
        *p++->t;
        // ==*(p++) 但是先执行*p  ->*p + 1
        printf("%c  ", *p->t);
        break;
    case 4:
        printf("%c\n", *(++p)->t);
        break;
    case 5:
        printf("%c\n", *++p->t);
        break;
    case 6:
        printf("%c", ++*p->t);
        break;

    default:
        break;
    }
    return 0;
}