#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct
{
    int mod;
    double value;
} Change;

void input(int n, Change change[n]);
void output(int n, int m, Change change[n]);

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    Change change[n];
    input(n, change);
    output(n, m, change);

    return 0;
}

void input(int n, Change change[n])
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d %lf", &change[i].mod, &change[i].value);
    }
}

void output(int n, int m, Change change[n])
{
    int i, j;
    double x, y;
    for (int q = 0; q < m; q++)
    {
        scanf("%d %d %lf %lf", &i, &j, &x, &y);
        double k = 1, a = 0;
        for (int temp = i - 1; temp < j; temp++)
        {
            if (change[temp].mod == 1)
            {
                k *= change[temp].value;
            }
            else if (change[temp].mod == 2)
            {
                a += change[temp].value;
            }
        }
        x *= k, y *= k;
        double x1 = x, y1 = y;
        x = x1 * cos(a) - y1 * sin(a);
        y = x1 * sin(a) + y1 * cos(a);
        printf("%lf %lf\n", x, y);
    }
}