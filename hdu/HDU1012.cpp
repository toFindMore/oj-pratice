//
// Created by 周健 on 2020-01-03.
//
#include <stdio.h>

int main() {
    long long k = 1;
    printf("n e\n"
           "- -----------\n");
    printf("0 1\n");
    printf("1 2\n");
    printf("2 2.5\n");
    double sum = 1;
    for (int i = 1; i <= 9; i++) {
        k *= i;
        sum += (double) 1 / k;
        if (i >= 3) {
            printf("%d %.9lf\n", i, sum);
        }
    }
    return 0;
}