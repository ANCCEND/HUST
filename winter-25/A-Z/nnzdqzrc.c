#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int calculate(int s, int *x);
int compare(const void *a, const void *b);

int main(void)
{
    int s1, s2, s3, s4, time = 0;
    scanf("%d%d%d%d", &s1, &s2, &s3, &s4);
    int a[s1], b[s2], c[s3], d[s4];
    time += calculate(s1, a) + calculate(s2, b) + calculate(s3, c) + calculate(s4, d);
    printf("%d", time);

    return 0;
}

int calculate(int s, int *x)
{
    int sum = 0;
    for (int i = 0; i < s; i++)
    {
        scanf("%d", &x[i]);
        sum += x[i];
    }
    if (s == 1)
        return sum;
    else
        qsort(x, s, sizeof(int), compare);
    int target = sum / 2;
    bool dp[target + 1];
    memset(dp, false, sizeof(dp));
    dp[0] = true;

    for (int i = 0; i < s; i++)
    {
        for (int j = target; j >= x[i]; j--)
        {
            if (dp[j - x[i]])
            {
                dp[j] = true;
            }
        }
    }

    for (int i = target; i > 0; i--)
    {
        if (dp[i])
            return (sum - i);
    }
}

int compare(const void *a, const void *b)
{
    int *A = (int *)a, *B = (int *)b;
    return (*A - *B);
}