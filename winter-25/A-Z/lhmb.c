#include <stdio.h>
#include <stdlib.h>

void seek(int n, int k);
int compare(int *i, int *j);

int main(void)
{
    int n, k;
    scanf("%d %d", &n, &k);
    seek(n, k);

    return 0;
}

void seek(int n, int k)
{
    int num[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    qsort(num, n, sizeof(int), compare);
    int temp = num[0], count = 0;
    for (int i = 0; i < n; i++)
    {

        if (num[i] > temp)
        {
            count++;
            if (count == k)
            {
                printf("%d", temp);
                return;
            }
        }

        temp = num[i];
    }
    printf("NO RESULT");
}

int compare(int *i, int *j)
{
    return *i - *j;
}