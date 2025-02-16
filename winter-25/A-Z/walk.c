#include <stdio.h>
#include <string.h>
#include <limits.h>

#define INF INT_MAX

int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

typedef struct
{
    int x, y, magic, cost, color;
} Node;

int bfs(int m, int num[m][m]);
int enqueue(int x, int y, int magic, int cost, int color, Node *queue, int after);

int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);
    int num[m][m];
    memset(num, 0, m * m * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        num[x - 1][y - 1] = c + 1;
    }
    printf("%d", bfs(m, num));

    return 0;
}

int bfs(int m, int num[m][m])
{
    Node queue[m * m * 2];
    int front, after;
    front = after = 0;
    int costs[m][m][2];
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            costs[i][j][1] = INF;
            costs[i][j][0] = INF;
        }
    }
    enqueue(0, 0, 0, 0, num[0][0], queue, after++);

    while (front < after)
    {
        Node current = queue[front++];
        int x = current.x, y = current.y, magic = current.magic, cost = current.cost, color = current.color;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + directions[i][0], ny = y + directions[i][1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < m)
            {
                int newcost;
                if (num[nx][ny] == color)
                {
                    newcost = cost;
                    if (costs[nx][ny][0] > newcost)
                    {
                        costs[nx][ny][0] = newcost;
                        enqueue(nx, ny, 0, newcost, num[nx][ny], queue, after++);
                    }
                }
                else if (num[nx][ny] != 0)
                {
                    newcost = cost + 1;
                    if (costs[nx][ny][0] > newcost)
                    {
                        costs[nx][ny][0] = newcost;
                        enqueue(nx, ny, 0, newcost, num[nx][ny], queue, after++);
                    }
                }
                else if (num[nx][ny] == 0 && magic == 0)
                {
                    magic = 1;
                    for (int i = 0; i < 2; i++)
                    {
                        if (i == color)
                        {
                            newcost = cost + 2;
                            if (costs[nx][ny][1] > newcost)
                            {
                                costs[nx][ny][1] = newcost;
                                enqueue(nx, ny, 1, newcost, num[nx][ny], queue, after++);
                            }
                        }
                        else
                        {
                            newcost = cost + 3;
                            if (costs[nx][ny][1] > newcost)
                            {
                                costs[nx][ny][1] = newcost;
                                enqueue(nx, ny, 1, newcost, num[nx][ny], queue, after++);
                            }
                        }
                    }
                }
            }
        }
    }
    return (costs[m - 1][m - 1][0] < costs[m - 1][m - 1][1] ? costs[m - 1][m - 1][0] : costs[m - 1][m - 1][1]);
}

int enqueue(int x, int y, int magic, int cost, int color, Node *queue, int after)
{
    queue[after].x = x;
    queue[after].y = y;
    queue[after].magic = magic;
    queue[after].cost = cost;
    queue[after].color = color;
}