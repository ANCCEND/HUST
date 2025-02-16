#include <stdio.h>
#include <stdbool.h>

int n, k;
long long arr[20];
int total = 0;

bool is_prime(long long num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (long long i = 5; i <= num / i; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

void backtrack(int start, int count, long long sum) {
    if (count == k) {
        if (is_prime(sum)) {
            total++;
        }
        return;
    }
    for (int i = start; i < n; i++) {
        backtrack(i + 1, count + 1, sum + arr[i]);
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    if (k == 0 || k > n) {
        printf("0\n");
        return 0;
    }
    backtrack(0, 0, 0);
    printf("%d\n", total);
    return 0;
}