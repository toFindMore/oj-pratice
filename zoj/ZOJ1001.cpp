//
// Created by 周健 on 2020-01-31.
//
#include <stdio.h>

typedef long long LL;

int main() {
    LL a, b;
    while (scanf("%lld%lld", &a, &b) != EOF) {
        printf("%lld\n", a + b);
    }
    return 0;
}