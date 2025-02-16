#include <stdio.h>
#include <string.h>

void add(int m, int n, int points[m][2]);

int main()
{
    int m, n;
    scanf("%d%d", &n, &m);
    int points[m][2];
    memset(points, 0, sizeof(points));
    add(m, n, points);
    for (int i = 0; i < m; i++)
    {
        printf("%d %d\n", points[i][0], points[i][1]);
    }

    return 0;
}

void add(int m, int n, int points[m][2])
{
    int move[2];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &move[0], &move[1]);
        for (int j = 0; j < m; j++)
        {
            points[j][0] += move[0];
            points[j][1] += move[1];
        }
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &move[0], &move[1]);
        points[i][0] += move[0];
        points[i][1] += move[1];
    }
}