#include <stdio.h>
#include <stdlib.h>

// 矩阵乘法：计算 A(n, d) 和 B(d, n) 的乘积，结果保存在 C(n, n)
void matrix_multiply(int **A, int **B, int **C, int n, int d) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < d; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// 向量与矩阵乘法：计算 W(n) 和 M(n, n) 的乘积，结果保存在 result(n)
void vector_matrix_multiply(int *W, int **M, int *result, int n) {
    for (int i = 0; i < n; i++) {
        result[i] = 0;
        for (int j = 0; j < n; j++) {
            result[i] += W[j] * M[j][i];
        }
    }
}

// 向量与矩阵乘法：计算 result(n) 和 V(n, d) 的乘积，结果保存在 final_result(n, d)
void vector_matrix_multiply_2d(int *result, int **V, int **final_result, int n, int d) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            final_result[i][j] = result[i] * V[i][j];
        }
    }
}

int main() {
    int n, d;
    scanf("%d %d", &n, &d);

    // 动态分配内存
    int **Q = (int **)malloc(n * sizeof(int *));
    int **K = (int **)malloc(n * sizeof(int *));
    int **V = (int **)malloc(n * sizeof(int *));
    int *W = (int *)malloc(n * sizeof(int));
    int **Q_KT = (int **)malloc(n * sizeof(int *));
    int *W_dot_Q_KT = (int *)malloc(n * sizeof(int));
    int **final_result = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++) {
        Q[i] = (int *)malloc(d * sizeof(int));
        K[i] = (int *)malloc(d * sizeof(int));
        V[i] = (int *)malloc(d * sizeof(int));
        Q_KT[i] = (int *)malloc(n * sizeof(int));  // Q_KT 是 n x n 的矩阵
        final_result[i] = (int *)malloc(d * sizeof(int));  // final_result 是 n x d 的矩阵
    }

    // 输入矩阵 Q
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            scanf("%d", &Q[i][j]);
        }
    }

    // 输入矩阵 K
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            scanf("%d", &K[i][j]);
        }
    }

    // 输入矩阵 V
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            scanf("%d", &V[i][j]);
        }
    }

    // 输入向量 W
    for (int i = 0; i < n; i++) {
        scanf("%d", &W[i]);
    }

    // 计算 Q × K^T
    matrix_multiply(Q, K, Q_KT, n, d);

    // 计算 W · (Q × K^T)
    vector_matrix_multiply(W, Q_KT, W_dot_Q_KT, n);

    // 计算 (W · (Q × K^T)) × V
    vector_matrix_multiply_2d(W_dot_Q_KT, V, final_result, n, d);

    // 输出结果
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            printf("%d ", final_result[i][j]);
        }
        printf("\n");
    }

    // 释放内存
    for (int i = 0; i < n; i++) {
        free(Q[i]);
        free(K[i]);
        free(V[i]);
        free(Q_KT[i]);
        free(final_result[i]);
    }
    free(Q);
    free(K);
    free(V);
    free(W);
    free(Q_KT);
    free(W_dot_Q_KT);
    free(final_result);

    return 0;
}
