// 迷宫问题
#include <stdio.h>
#define SIZE 100
int m, n; //行列
int a[SIZE][SIZE] = {0};
int findPath(int a[][SIZE], int i, int j)
{
    if (i == m - 1 && j == n - 1)
        return 1;          //到目标地点
    else if (a[i][j] == 1) //如果这个位置可以走
    {
        a[i][j] = -1; //-1表示这个点已经走过
        // 遍历上下左右4个方向，如果有能到终点的 return 1
        if (findPath(a, i + 1, j) || findPath(a, i, j + 1) || findPath(a, i - 1, j) || findPath(a, i, j - 1))
            return 1;
        else
        {
            a[i][j] = 1;
            return 0;
        }
    }
    else
        return 0;
}
int main(void)
{

    scanf("%d %d", &m, &n);
    int a[m][n];
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
}