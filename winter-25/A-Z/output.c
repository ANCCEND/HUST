#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    output(n);

    return 0;
}

void output(int n)
{
    if (n == 0)
    {
        printf("0");
        return;
    }
    else if (n == 1)
    {
        printf("2(0)");
        return;
    }
    else if (n == 2)
    {
        printf("2");
        return;
    }

    int i = 0, temp = 1;
    while ((temp * 2) <= n)
    {
        i++;
        temp *= 2;
    }

    if (i == 1)
    {
        printf("2");
    }
    else
    {
        printf("2(");
        output(i);
        printf(")");
    }

    if ((n = n - temp) > 0)
    {
        printf("+");
        output(n);
    }
}