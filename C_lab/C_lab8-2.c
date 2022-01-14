
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    // char ch;
    FILE *fp;
    if (argc != 3)
    {
        printf("Arguments error!\n");
        exit(-1);
    }
    int num = 1;
    fp = fopen(argv[1], "r");
    char buf[1024];
    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
        printf("%d  %s", num, buf);
        num++;
        if (num == 26)
        {
            while (getchar())
                ;
            num = 1;
        }
    }
    return 0;
}