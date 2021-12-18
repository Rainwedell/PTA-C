#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define SIZE 201
#define RSIZE 400
int result[RSIZE] = {0};
int multiplication(int *a, int *b, const int aLen, const int bLen)
{

    int carry = 0;
    for (int i = 0; i < aLen + bLen - 1; i++)
    {
        for (int j = 0; j <= i && j <= aLen - 1; j++)
        {
            // if (i - j <= bLen - 1)
            //     result[i] += a[j] * b[i - j];
            if (i - j <= bLen - 1)
                *(result + i) += (*(a + j)) * (*(b + i - j));
        }

        // result[i] += carry;
        // carry = result[i] / 10;
        // result[i] %= 10;
        *(result + i) += carry;
        carry = *(result + i) / 10;
        *(result + i) %= 10;
    }
    if (carry)
    {
        // result[aLen + bLen - 1] = carry;
        *(result + aLen + bLen - 1) = carry;
        return (aLen + bLen);
    }
    return (aLen + bLen - 1);
}
void reverse(int *a, int aLen)
{
    for (int i = 0; i < aLen / 2; i++)
    {
        int temp = *(a + i);
        *(a + i) = *(a + aLen - 1 - i);
        *(a + aLen - 1 - i) = temp;
    }
}
int main(void)
{
    int a[SIZE], b[SIZE], aLen, bLen;
    char A[SIZE], B[SIZE];

    aLen = bLen = 0;
    // 这里输入是高位在前
    // while ((a[aLen++] = getchar() - '0') != '\n' - '0')
    //     ;
    // while ((*(a + aLen++) = getchar() - '0') != '\n' - '0')
    //     ;

    // while ((b[bLen++] = getchar() - '0') != '\n' - '0')
    //     ;
    // while ((*(b + bLen++) = getchar() - '0') != '\n' - '0')
    //     ;
    gets(A);
    gets(B);
    aLen = strlen(A);
    bLen = strlen(B);
    for (int i = 0; i < aLen; i++)
        a[i] = A[i] - '0';

    for (int i = 0; i < bLen; i++)
        b[i] = B[i] - '0';

    reverse(a, aLen);
    reverse(b, bLen);
    // 传入时低位在前
    int Len = multiplication(a, b, aLen, bLen);
    for (int i = Len - 1; i >= 0; i--)
        printf("%d", result[i]);

    return 0;
}