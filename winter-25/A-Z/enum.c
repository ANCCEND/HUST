#include <stdio.h>
#include <string.h>

int dp[20][20][2] = {0};
int x;

int DP1(int pos, int, int tight, int *num);
int DP0(int pos, int hasx, int tight, int *num, int started);
int countNum(int n);

int main(void)
{
    int n;
    scanf("%d %d", &n, &x);
    memset(dp, -1, sizeof(dp));
    printf("%d", countNum(n));

    return 0;
}

int DP0(int pos, int hasx, int tight, int *num, int started)
{
    if (pos == -1)
        return hasx;
    if (dp[pos][hasx][tight] != -1)
        return dp[pos][hasx][tight];
    int limit = tight ? num[pos] : 9;
    int count = 0;
    int i;

    for (i = 0; i <= limit; i++)
    {
        int new_started = started || i != 0;
        if (started && i == x)
            count += DP0(pos - 1, hasx + 1, tight && i == limit, num, new_started);
        else
            count += DP0(pos - 1, hasx, tight && i == limit, num, new_started);
    }
    if (started && !tight && i == 10)
        dp[pos][hasx][tight] = count;
    return count;
}

int DP1(int pos, int hasx, int tight, int *num)
{
    if (pos == -1)
        return hasx;
    if (dp[pos][hasx][tight] != -1)
        return dp[pos][hasx][tight];
    int limit = tight ? num[pos] : 9;
    int count = 0;
    int i;

    for (i = 0; i <= limit; i++)
    {
        if (i == x)
            count += DP1(pos - 1, hasx + 1, tight && i == limit, num);
        else
            count += DP1(pos - 1, hasx, tight && i == limit, num);
    }
    if (!tight && i == 10)
        dp[pos][hasx][tight] = count;
    return count;
}

int countNum(int n)
{
    int num[10], len = 0;
    while (n)
    {
        num[len++] = n % 10;
        n /= 10;
    }
    len -= 1;

    if (x)
        return DP1(len, 0, 1, num);
    else
        return DP0(len, 0, 1, num, 0);
}