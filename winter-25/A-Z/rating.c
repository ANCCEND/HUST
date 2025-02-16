#include <stdio.h>

int main(void)
{
    int n;
    float sum = 0;
    scanf("%d", &n);
    int x, max = 0, min = 10;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        sum += x;
        max = max > x ? max : x;
        min = min < x ? min : x;
    }
    sum = sum - (max + min);
    printf("%.2f", sum / (n - 2));

    return 0;
}