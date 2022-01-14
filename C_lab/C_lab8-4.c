#include <stdio.h>
#include <stdlib.h>
void writeFloats(const char *fileName);
void readFloats(const char *fileName);

int main(void)
{
    const char fileName[] = "float.dat";
    writeFloats(fileName);
    readFloats(fileName);
    return 0;
}

void writeFloats(const char *fileName)
{
    FILE *fp;
    fp = fopen(fileName, "wb");
    float nums[10];
    for (int i = 0; i < 10; ++i)
    {
        scanf("%f", nums + i);
    }
    fwrite(nums, sizeof(float), 10, fp);
    //二进制文件必须使用fwrite，不能使用fputs

    fclose(fp);
}

void readFloats(const char *fileName)
{
    FILE *fp;
    fp = fopen(fileName, "rb");
    float nums[10];
    for (int i = 0; i < 10; i++)
    {
        unsigned bin = *(unsigned *)(nums + i);

        for (int j = 31; j >= 0; j--)
        {
            putchar('0' + ((bin >> j) & 1));
        }
        putchar('\n');
    }
    fclose(fp);
}
