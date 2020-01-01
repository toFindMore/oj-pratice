//
// Created by 周健 on 2019-08-16.
//
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int SIZE = 11;
const int MOD = 9973;

typedef long long ll;

struct Matrix {
    int matrix[SIZE][SIZE];
    int size;

    Matrix() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                matrix[i][j] = 0;
            }
        }
    }
};

Matrix mul_matrix(Matrix matrix1, Matrix matrix2) {
    int len = matrix1.size;
    Matrix res;
    res.size = len;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            int x = 0;
            for (int k = 0; k < len; k++) {
                x += (ll) matrix1.matrix[i][k] * matrix2.matrix[k][j] % MOD;
            }
            res.matrix[i][j] = x;
        }
    }
    return res;
}

Matrix power_matrix(Matrix matrix, int k) {
    int len = matrix.size;
    Matrix res;
    res.size = len;
    for (int i = 0; i < SIZE; i++) {
        res.matrix[i][i] = 1;
    }
    while (k > 0) {
        if (k & 1) {
            res = mul_matrix(res, matrix);
        }
        matrix = mul_matrix(matrix, matrix);
        k >>= 1;
    }
    return res;
}

int main() {
    int T, n, k;
    Matrix m;
    #ifdef ONLINE_JUDGE
    #else
        freopen("/Users/ZJ/CLionProjects/Problems/input/1575", "r", stdin);
    #endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        m.size = n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &m.matrix[i][j]);
            }
        }
        Matrix mm = power_matrix(m, k);
        int t = 0;
        for (int i = 0; i < n; i++) {
            t = (t + mm.matrix[i][i]) % MOD;
        }
        printf("%d\n", t);
    }
    return 0;
}