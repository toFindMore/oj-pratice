//
// Created by 周健 on 2019-12-11.
//
#include <stdio.h>

const int SIZE = 2;
const int MOD = 7;

struct Matrix {
    int matrix[SIZE][SIZE];
};


Matrix matrixMul(Matrix matrix1, Matrix matrix2) {
    Matrix res;
    res.matrix[0][0] = res.matrix[0][1] = res.matrix[1][0] = res.matrix[1][1] = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                res.matrix[i][j] += matrix1.matrix[i][k] * matrix2.matrix[k][j];
            }
            res.matrix[i][j] %= MOD;
        }
    }
    return res;
}

void printM(Matrix m) {
    printf("\n**************\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ",m.matrix[i][j]);
        }
        printf("\n");
    }
    printf("**************\n");
}

Matrix quickMul(Matrix matrix, int n) {
    if (n == 1) {
        return matrix;
    }
    Matrix matrixTemp = quickMul(matrix, n / 2);
    matrixTemp = matrixMul(matrixTemp, matrixTemp);
    if (n % 2 == 1) {
        matrixTemp = matrixMul(matrix, matrixTemp);
    }
    return matrixTemp;
}


int main() {

    int A, B, n;
    while (scanf("%d%d%d", &A, &B, &n) && !(A == 0 && B == 0 && n == 0)) {
        if(n == 1 || n == 2) {
            printf("1\n");
            continue;
        }
        Matrix matrix;
        matrix.matrix[0][0] = A;
        matrix.matrix[0][1] = B;
        matrix.matrix[1][0] = 1;
        matrix.matrix[1][1] = 0;
        Matrix resMatrix = quickMul(matrix, n - 2);
        int res = (resMatrix.matrix[0][0] + resMatrix.matrix[0][1]) % MOD;
        printf("%d\n", res);
    }
    return 0;
}