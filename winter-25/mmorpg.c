#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void diction(int, int, int, char ch[][11], char ch1[][11]);
int compare(const void *, const void *);
void output(int, int, char ch[][11], char ch1[][11]);

int main(void)
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    char ch[n + k][11], ch1[m][11];
    diction(n, m, k, ch, ch1);
    output(n + k, m, ch, ch1);

    return 0;
}

void diction(int n, int m, int k, char ch[][11], char ch1[][11])
{
    for (int i = 0; i < n; i++)
    {
        scanf("%s", ch[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%s", ch1[i]);
    }
    if (k > 0)
    {
        for (int i = n; i < n + k; i++)
        {
            scanf("%s", ch[i]);
        }
    }
    if (n + k > 1)
        qsort(ch, n + k, sizeof(ch[0]), compare);
    if (m > 1)
        qsort(ch1, m, sizeof(ch1[0]), compare);
}

void output(int nk, int m, char ch[][11], char ch1[][11])
{
    char *found;
    for (int i = 0; i < nk; i++)
    {
        if ((found = (char *)bsearch(ch[i], ch1, m, sizeof(ch1[0]), compare)) == NULL)
        {
            printf("%s\n", ch[i]);
        }
    }
}

int compare(const void *a, const void *b)
{
    const char(*A) = a, (*B) = b;
    return strcmp(A, B);
}
