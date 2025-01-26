#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char str[21];
    int num;
} trans;

void diction(int, trans *);
int compare(const void *, const void *);
void translate(int, int, trans *);

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    getchar();
    trans dict[n];
    diction(n, dict);
    translate(n, m, dict);

    return 0;
}

void diction(int n, trans *dict)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", dict[i].str, &dict[i].num);
    }
    getchar();
    qsort(dict, n, sizeof(trans), compare);
}

int compare(const void *a, const void *b)
{
    const trans *A = (const trans *)a;
    const trans *B = (const trans *)b;
    return strcmp(A->str, B->str);
}

void translate(int n, int m, trans *dict)
{
    char ch;
    while (m-- > 0)
    {
        while ((ch = getchar()) != '\n')
        {
            if (ch == '{')
            {
                trans target;
                int i = 0;
                while ((ch = getchar()) != '}')
                {
                    target.str[i++] = ch;
                }
                target.str[i] = '\0';
                target.num = 0;
                trans *found = bsearch(&target, dict, n, sizeof(trans), compare);
                if (found != NULL)
                {
                    printf("%d", found->num);
                }
            }
            else
                putchar(ch);
        }
        putchar('\n');
    }
}