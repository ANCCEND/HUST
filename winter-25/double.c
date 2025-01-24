#include <stdio.h>

int main(void)
{
    long x;
    scanf("%ld", &x);
    int i;
    for (i = 1; x > 1; i++)
    {
        x /= 2;
    }
    printf("%d", i);

    return 0;
}