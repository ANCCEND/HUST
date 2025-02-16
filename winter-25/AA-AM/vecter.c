#include <stdio.h>

void seek(int i, int m, int n, int matrix[n][m]);

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int matrix[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        seek(i, m, n, matrix);
    }

    return 0;
}

void seek(int i, int m, int n, int matrix[n][m])
{
    int flag = 0;
    for (int x = 0; x < n; x++)
    {
        if (x == i)
            continue;
        for (int y = 0; y < m; y++)
        {
            if (matrix[x][y] <= matrix[i][y])
                break;
            if (y == m - 1)
            {
                flag = 1;
                printf("%d\n", x + 1);
                return;
            }
        }
    }
    printf("0\n");
}