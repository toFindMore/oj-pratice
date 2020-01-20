//
// Created by 周健 on 2020-01-20.
//
#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        (n & 3) == 2 ? printf("yes") : printf("no");
        printf("\n");
    }
    return 0;
}