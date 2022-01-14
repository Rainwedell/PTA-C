#include <stdio.h>
struct bits
{
    int bit0;
    int bit1;
    int bit2;
    int bit3;
    int bit4;
    int bit5;
    int bit6;
    int bit7;
}; //存放二进制数
void f0 (int b)
{
    printf("the function %d is called!\n", b);
}
void f1 (int b)
{
    printf("the function %d is called!\n", b);
}
void f2 (int b)
{
    printf("the function %d is called!\n", b);
}
void f3 (int b)
{
    printf("the function %d is called!\n", b);
}
void f4 (int b)
{
    printf("the function %d is called!\n", b);
}
void f5 (int b)
{
    printf("the function %d is called!\n", b);
}
void f6 (int b)
{
    printf("the function %d is called!\n", b);
}
void f7 (int b)
{
    printf("the function %d is called!\n", b);
}
int main(void)
{
    unsigned int a;
    scanf("%d", &a);
    struct bits p;
    p.bit0 = a & 0x1;
    p.bit1 = a>>1 & 0x1;
    p.bit2 = a>>2 & 0x1;
    p.bit3 = a>>3 & 0x1;
    p.bit4 = a>>4 & 0x1;
    p.bit5 = a>>5 & 0x1;
    p.bit6 = a>>6 & 0x1;
    p.bit7 = a>>7 & 0x1;

    void (*p_fun[8])(int b)={f0,f1,f2,f3,f4,f5,f6,f7};
    if(p.bit0 == 1)
        p_fun[0](0);
    if(p.bit1 == 1)
        p_fun[1](1);
    if(p.bit2 == 1)
        p_fun[2](2);
    if(p.bit3 == 1)
        p_fun[3](3);
    if(p.bit4 == 1)
        p_fun[4](4);
    if(p.bit5 == 1)
        p_fun[5](5);
    if(p.bit6 == 1)
        p_fun[6](6);
    if(p.bit7 == 1)
        p_fun[7](7);
    
    return 0;

}