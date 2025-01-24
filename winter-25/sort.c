#include <stdio.h>

int main(void)
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int q, w;
    if (a < b)
        q = a, w = b;
    else
        q = b, w = a;
    if (q >= c)
        printf("%d %d %d", c, q, w);
    else
    {
        if (c >= w)
            printf("%d %d %d", q, w, c);
        else
            printf("%d %d %d", q, c, w);
    }

    return 0;
}