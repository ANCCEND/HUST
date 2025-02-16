#include <stdio.h>

int compare(char *, char *, int);

int main(void)
{
    char s[1001], t[1001];
    int q;
    scanf("%s %s %d", s, t, &q);
    int sl, sr, tl, tr;
    for (int i = 0; i < q; i++)
    {
        scanf("%d%d%d%d", &sl, &sr, &tl, &tr);
        if (compare(s + sl - 1, t + tl - 1, sr - sl >= tr - tl ? sr - sl : tr - tl) < 0)
            printf("yifusuyi\n");
        else if (compare(s + sl - 1, t + tl - 1, sr - sl >= tr - tl ? sr - sl : tr - tl) > 0)
            printf("erfusuer\n", t);
        else
            printf("ovo\n");
    }

    return 0;
}

int compare(char s[], char t[], int r_l)
{
    for (int i = 0; i <= r_l; i++)
    {
        if (s[i] == t[i])
            continue;
        else
            return s[i] - t[i];
    }
    return 0;
}