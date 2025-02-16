#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int flag = 0;
    if (n % 2 == 0)
        flag += 1;
    if (n > 4 && n <= 12)
        flag += 2;
    switch (flag)
    {
    case 0:
        printf("0 0 0 1");
        break;
    case 1:
        printf("0 1 1 0");
        break;
    case 2:
        printf("0 1 1 0");
        break;
    case 3:
        printf("1 1 0 0");
        break;
    }

    return 0;
}