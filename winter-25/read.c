#include <stdio.h>
#include <string.h>

int count(int n, int m);
int seekN(int temp, int, int *);
int flag;

int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);
    printf("%d", count(n, m));

    return 0;
}

int count(int n, int m)
{
    int func[m], temp, count = 0;
    memset(func, -2, sizeof(func));
    while (n-- > 0)
    {
        scanf("%d", &temp) == 1;
        int x = seekN(temp, m, func);
        if (x == 0)
        {
            count++;
            if (flag == m)
                flag = 0;
            func[flag] = temp;
        }
        else if (x == 2)
        {
            count++;
        }
        else
            continue;
    }
    return count;
}

int seekN(int temp, int m, int *func)
{
    for (int i = 0; i < m; i++)
    {
        if (func[i] == temp)
            return 1;
        else if (func[i] == -2)
        {
            func[i] = temp;
            return 2;
        }
    }
    flag++;
    return 0;
}