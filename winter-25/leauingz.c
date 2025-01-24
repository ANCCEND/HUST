#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int local = 5 * n, luogu = 3 * n + 11;
    char *str = (local < luogu ? "Local" : "Luogu");
    printf("%s", str);

    return 0;
}