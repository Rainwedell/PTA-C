#include <stdio.h>
#include <string.h>

void strnCpy(char t[], char s[], int n)
{

    for (int i = 0; i < n && s[i] != '\0'; i++)
        t[i] = s[i];

    t[n] = '\0';
}
int main(void)
{
    char t[100];
    strnCpy(t, "lang", 9);
    printf("%s", t);
    return 0;
}