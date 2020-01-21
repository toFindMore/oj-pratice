//
// Created by 周健 on 2020-01-20.
//
#include <stdio.h>

const int SIZE = 201;

long long C[SIZE][SIZE];

// C(n,m) = C(n-1,m) + C(n-1,m-1)
void init() {
    for (int i = 0; i < SIZE; i++) {
        C[i][0] = 1;
    }
    for (int i = 1; i < SIZE; i++) {
        for (int j = 1; j < SIZE; j++) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
}

int main() {
    return 0;
}

