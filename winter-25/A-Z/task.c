#include <stdio.h>
#include <string.h>

void dotask(int n, int *, int num[][n], int);

int main(void)
{
    int n;
    scanf("%d", &n);
    int num[n][n];
    memset(num, 0, sizeof(num));
    for (int i = 0; i < n; i++)
    {
        int j;
        scanf("%d", &j);
        for (int k = 0; k < j; k++)
        {
            scanf("%d", &num[i][k]);
        }
    }
    int arr[n], count = 0;
    memset(arr, 0, sizeof(arr));
    dotask(n, arr, num, 1);
    for (int i = 0; i < n; i++)
    {
        if (arr[i])
            count++;
    }
    printf("%d", count);

    return 0;
}

void dotask(int n, int arr[], int num[][n], int x)
{
    if (arr[x - 1] != 1)
    {
        int i = 0, temp;
        arr[x - 1] = 1;
        while ((temp = num[x - 1][i]) != 0 && i < n)
        {
            if (arr[temp - 1] == 0)
            {
                dotask(n, arr, num, temp);
            }
            i++;
        }
    }
}