#include <stdio.h>

#define MOD 998244353


void mat_mult(long long A[3][3], long long B[3][3], long long res[3][3]) {
    long long temp[3][3] = {0};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                temp[i][j] = (temp[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            res[i][j] = temp[i][j];
}


void mat_pow(long long A[3][3], long long n, long long res[3][3]) {
    long long I[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            res[i][j] = I[i][j];
    
    while (n > 0) {
        if (n % 2 == 1) {
            mat_mult(res, A, res);
        }
        mat_mult(A, A, A);
        n /= 2;
    }
}

long long calculate_f(long long n, long long a, long long b, long long c, long long f1, long long f2) {
    if (n == 1) return f1;
    if (n == 2) return f2;

    long long A[3][3] = {
        {a, b, c},
        {1, 0, 0},
        {0, 0, 1}
    };


    long long F[3] = {f2, f1, 1};
    
    long long res[3][3];
    mat_pow(A, n - 2, res);
    
    long long fn = (res[0][0] * F[0] + res[0][1] * F[1] + res[0][2] * F[2]) % MOD;
    return fn;
}

int main() {
    long long n,a, b, c, f1, f2;
    scanf("%lld %lld %lld %lld %lld %lld", &n, &f1, &f2, &a, &b, &c);

    printf("%lld\n", calculate_f(n, a, b, c, f1, f2));
    
    return 0;
}
