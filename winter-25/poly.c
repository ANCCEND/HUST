#include <stdio.h>
#define MAX 100000

void selectPrime(int s, int *allNum, int *primes);

int count = 0, sum = 0;

int main(void)
{
    int s;
    int primes[MAX + 1] = {0}, allNum[MAX + 1] = {0};
    scanf("%d", &s);
    if (s < 2)
        printf("0\n");
    else if (s == 2)
        printf("2\n1");

    else
    {
        selectPrime(s, allNum, primes);
        for (int i = 0; i < count - 1; i++)
        {
            printf("%d\n", primes[i]);
        }
        printf("%d", count - 1);
    }

    return 0;
}

void selectPrime(int s, int *allNum, int *primes)
{
    for (int i = 2; sum <= s && i <= s; i++)
    {
        if (allNum[i] == 0)
        {
            primes[count++] = i;
            sum += i;
        }
        for (int j = 0; j < count && primes[j] * i < s; j++)
        {
            allNum[primes[j] * i] = 1;
            if (i % primes[j] == 0)
                break;
        }
    }
}