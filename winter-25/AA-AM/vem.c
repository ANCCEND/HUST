#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b);

int main()
{
    int n, m, k, flag = 1;
    scanf("%d%d%d", &n, &m, &k);
    int goods[k];
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &goods[i]);
    }
    qsort(goods, k, sizeof(int), compare);
    if (m == 1)
    {
        for (int i = 0; i < k; i++)
        {
            int height = i + 1;
            if (height > goods[i])
                flag = 0;
        }
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            int height = (i + 1) / m;
            if (height > goods[i] || height == goods[i] && (i + 1) % m != 0)
                flag = 0;
        }
    }
    if (flag)
        printf("Yes");
    else
        printf("No");

    return 0;
}

int compare(const void *a, const void *b)
{
    int *A = (int *)a, *B = (int *)b;
    return (*A - *B);
}
