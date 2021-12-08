#include <stdio.h>
#define LEN 1000

int main(void)
{
    char a[LEN];
    int character[26] = {0};
    int number[10] = {0};
    int others[1] = {0};

    fgets(a, LEN, stdin);
    for (int i = 0; a[i] != '\n'; i++)
    {
        if (a[i] >= '0' && a[i] <= '9')
            number[a[i] - '0']++;
        else if (a[i] >= 'A' && a[i] <= 'Z')
            character[a[i] - 'A']++;
        else if (a[i] >= 'a' && a[i] <= 'z')
            character[a[i] - 'a']++;
        else
            others[0]++;
    }
    for (int i = 0; i < 10; i++)
        if (number[i])
            printf("%d:%d\n", i, number[i]);

    for (int i = 0; i < 26; i++)
        if (character[i])
            printf("%c:%d\n", (i + 'A'), character[i]);

    printf("others:%d", others[0]);

    return 0;
}