#include <stdio.h>

int match(int *goods, int n);
void sort(int *goods, int l, int r);

int main(void)
{
    int n, p;
    scanf("%d %d", &n, &p);
    int goods[n], order = 1, temp = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &goods[i]);
    }
    sort(goods, 0, n - 1);
    for (int i = 0; i < p; i++)
    {
        printf("%d\n", match(goods, n));
    }

    return 0;
}

void sort(int *goods, int l, int r)
{
    if (l < r)
    {
        int i = l + 1, j = r;
        int std = goods[l];

        while (i <= j)
        {
            while (i <= j && goods[i] <= std)
                i++;
            while (i <= j && goods[j] >= std)
                j--;

            if (i < j)
            {
                int temp = goods[i];
                goods[i] = goods[j];
                goods[j] = temp;
            }
        }

        goods[l] = goods[j];
        goods[j] = std;

        sort(goods, l, j - 1);
        sort(goods, j + 1, r);
    }
}

int match(int *goods, int n)
{
    int pos, code, x, i;
    scanf("%d %d", &pos, &code);
    for (x = 1, i = 0; i < pos; i++)
    {
        x *= 10;
    }
    for (int i = 0; i < n; i++)
    {
        if (goods[i] == code || goods[i] > x && goods[i] % x == code)
        {
            return goods[i];
        }
    }
    return -1;
}