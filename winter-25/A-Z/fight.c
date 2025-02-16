#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    long long bf[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &bf[i]);
    }
    int m, p1, p2;
    long long s1, s2;
    scanf("%d %d %lld %lld", &m, &p1, &s1, &s2);
    bf[p1 - 1] += s1;

    long long bn = 0, hm = 0;
    for (int i = 0; i < m - 1; i++)
    {
        bn += (m - 1 - i) * bf[i];
    }
    for (int i = m; i < n; i++)
    {
        hm += (i - m + 1) * bf[i];
    }
    long long temp = bn - hm;
    if (temp > 0)
    {
        long long x, y = temp;
        for (int i = m; i < n; i++)
        {
            x = llabs(temp - (i - m + 1) * s2);
            if (x < y)
            {
                y = x;
                p2 = i + 1;
            }
        }
    }
    else if (temp == 0)
        p2 = m;
    else
    {
        long long x, y = -temp;
        for (int i = 0; i < m - 1; i++)
        {
            x = llabs(-temp - (m - 1 - i) * s2);
            if (x < y)
            {
                y = x;
                p2 = i + 1;
            }
        }
    }
    printf("%d", p2);

    return 0;
}
