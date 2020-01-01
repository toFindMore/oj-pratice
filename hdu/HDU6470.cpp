//
// Created by 周健 on 2019-08-17.
//
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

const int SIZE = 6;
const int MOD = 123456789;
typedef long long ll;

struct Matrix {
    ll matrix[SIZE][SIZE];
    int size;

    Matrix(int t) {
        size = t;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                matrix[i][j] = 0;
            }
        }
    }
};

Matrix mul_matrix(Matrix m1, Matrix m2) {
    int len = m1.size;
    Matrix mm(len);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            int x = 0;
            for (int k = 0; k < len; k++) {
                x += (m1.matrix[i][k] % MOD * m2.matrix[k][j]) % MOD;
                x %= MOD;
            }
            mm.matrix[i][j] = x;
        }
    }
    return mm;
}

Matrix power_matrix(Matrix m, ll k) {
    int len = m.size;
    Matrix resMatrix(len);
    for (int i = 0; i < len; i++) {
        resMatrix.matrix[i][i] = 1;
    }
    while (k > 0) {
        if (k & 1) {
            resMatrix = mul_matrix(resMatrix, m);
        }
        m = mul_matrix(m, m);
        k >>= 1;
    }
    return resMatrix;
}

int main() {
    int T;
    ll n;
    //freopen("/Users/ZJ/CLionProjects/Problems/input/6470", "r", stdin);
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &n);
        Matrix matrix(6);
        int mm[SIZE][SIZE] = {
                {1, 2, 1, 3, 3, 1},
                {1, 0, 0, 0, 0, 0},
                {0, 0, 1, 3, 3, 1},
                {0, 0, 0, 1, 2, 1},
                {0, 0, 0, 0, 1, 1},
                {0, 0, 0, 0, 0, 1}
        };
        for(int i=0;i<SIZE;i++) {
            for(int j=0;j<SIZE;j++) {
                matrix.matrix[i][j] = mm[i][j];
            }
        }
        Matrix res = power_matrix(matrix, n - 2);
        int num = (res.matrix[0][0]*2+res.matrix[0][1]+res.matrix[0][2]*8+res.matrix[0][3]*4+res.matrix[0][4]*2+res.matrix[0][5])%MOD;
        printf("%d\n",num);
    }
    return 0;
}
