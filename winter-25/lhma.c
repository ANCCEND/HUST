#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    matrix(n);

    return 0;
}

void matrix(int n)
{
    int flag = 0, x, j = 0;
    while (scanf("%d", &x) == 1)
    {
        if (flag)
        {
            for (int i = 0; i < x; i++)
            {
                if (j == n)
                {
                    printf("\n");
                    j = 0;
                }
                printf("1");
                j++;
            }
        }
        else
        {
            for (int i = 0; i < x; i++)
            {
                if (j == n)
                {
                    printf("\n");
                    j = 0;
                }
                printf("0");
                j++;
            }
        }
        flag = (!flag);
    }
}