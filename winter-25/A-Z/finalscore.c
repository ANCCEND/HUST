#include <stdio.h>

int main(void)
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int sum = a / 5 + b / 10 * 3 + c / 2;
    printf("%d", sum);

    return 0;
}